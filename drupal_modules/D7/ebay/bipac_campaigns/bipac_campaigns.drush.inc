<?php

/**
 * @file
 *   This simply bulk-submits letters to BIPAC
 *   using the Drush CL interface
 */

/**
 * Implements hook_drush_command()
 */
function bipac_campaigns_drush_command() {
  $items = array();
  $items['bipac-campaigns-count'] = array(
    'description' => 'Figure out counts by topic',
    'aliases' => array('bipac-count'),
    'examples' => array(
      'drush bipac-count' => 'Provide a campaigns submission counts by topic',
    ),
  );
  $items['bipac-campaigns-bulk'] = array(
    'description' => 'Single process version of the BIPAC letter processor',
    'aliases' => array('bipac-bulk'),
    'arguments' => array(
      'size' => 'The size of the batch',
    ),
    'examples' => array(
      'drush bipac-bulk 100' => 'Process a batch of 100 submissions',
    ),
  );
  $items['bipac-campaigns-threaded'] = array(
    'description' => array('Threaded version of the BIPAC letter processor'),
    'aliases' => array('bipac-threaded'),
    'options' => array(
      'threads' => 'The number of threads.  Do not go crazy. Recommended 10.',
      'limit' => 'Max possible jobs in a single queue.  Recommended 1000.',
      'batch_size' => 'How many items to process in each queue.  Recommended 100.',
    ),
    'examples' => array(
      'drush bipac-threaded --threads=10 --limit=1000 --batch_size=100' => 'Process a 10 threaded batch of 1000 with 100 per batch',
    ),
  );
  $items['bipac-campaigns-consumer'] = array(
    'description' => 'A thread',
    'arguments' => array(
      'size' => 'How many items to process in a queue',
    ),
  );
  return $items;
}

/**
 * Callback for bipac-campaigns-count
 */
function drush_bipac_campaigns_count() {
  $results = db_select('bipac_emergency', 'b')
  ->fields('b')
  ->execute();

  $counts = array();

  if (!empty($results)) {
    foreach ($results as $result) {
      $data = unserialize($result->data);
      $topic = $data['topic'];
      $status = $result->status;

      if (($status == 1) || ($status == 4)) {
        if (empty($counts[$topic])) {
          $counts[$topic] = 1;
        }
        else {
          $tmp = $counts[$topic];
          $tmp++;
          $counts[$topic] = $tmp;
        }
      }
    }
  }
  foreach ($counts as $a => $b) {
    drupal_set_message(t('Processed %count submissions for %topic', array('%topic' => $a, '%count' => $b)));
  }
}

/**
 * Process our queue
 */
function drush_bipac_campaigns_threaded() {
  $time = time();
  $threads = drush_get_option('threads', 10);
  $roll_limit = drush_get_option('limit', 1000);
  $batch_size = drush_get_option('batch_size', 100);

  $queue = DrupalQueue::get('bipac_campaigns_roll', TRUE);

  _bipac_campaigns_populate_queue($roll_limit);

  $queue_size = $queue->numberOfItems();

  if ($queue_size < $roll_limit) {
    $new_size = $queue_size / $threads;
    $batch_size = ceil($new_size);
  }

  try {
    drush_thread_manager($queue_size, $batch_size, $threads, '_bipac_setup');
  }
  catch (Exception $e) {
    drush_set_error($e->getMessage());
  }

  $time = time() - $time;
  drush_print('Time taken: ' . $time);
}

function _bipac_setup($thread_id, $batch_size, $offset) {
  $command = 'drush bipac-campaigns-consumer ' . $batch_size;
  return $command;
}

function drush_bipac_campaigns_consumer($size) {
  $queue = DrupalQueue::get('bipac_campaigns_roll', TRUE);
  for ($i = 0; $i < $size; $i++) {
    if ($item = $queue->claimItem()) {
      $dump = $item->data;
      $id = $dump['id'];
      $data = $dump['data'];
      $status = _bipac_campaigns_process_letters($data, $id);
      // drush_print('Result: ' . $status);
      $queue->deleteItem($item);
    }
  }
}

function _bipac_campaigns_populate_queue($size) {
  drush_bipac_campaigns_bulk($size, TRUE);
}

/**
 * Callback for bipac-campaigns-bulk
 */
function drush_bipac_campaigns_bulk($size = NULL, $as_queue = FALSE) {
  if (empty($size)) {
    return drush_set_error(dt('You must specify a numerical size.'));
  }

  $results = db_select('bipac_emergency', 'b')
  ->fields('b')
  ->range(0, $size)
  ->orderBy('b.id', 'ASC')
  ->isNull('b.status')
  ->execute();

  if (!empty($results)) {
    $count = 0;
    foreach ($results as $result) {
      $id = $result->id;
      $data = unserialize($result->data);
      if (!empty($result->data)) {
        if ($as_queue === FALSE) {
          $status = _bipac_campaigns_process_letters($data, $id);
          drush_print($status);
          $count++;
        }
        else {
          $queue_build = array('id' => $id, 'data' => $data);
          $queue = DrupalQueue::get('bipac_campaigns_roll');
          $queue->createItem($queue_build);
        }
      }
    }
    drupal_set_message(t('Processed %count submissions', array('%count' => $count)));
  }
}

/**
 * A multithreading manager for drush.
 *
 * @see
 *   https://github.com/johnennewdeeson/drush-multi-processing/blob/master/mt.drush.inc
 *
 * @param int $job_count
 *   The total number of jobs to process
 * @param int $job_batch_size
 *   The number of jobs handed to each thread
 * @param int $thread_count
 *   The maximum number of active threads
 * @param string $setup_function
 *   The function to generate the thread command. This is written for your
 *   application its signature is:
 *   my_setup_function($thread_id, $limit, $offset) : string;
 *   Where $thread_id is the unique thread identifier, $limit is the total
 *   number of records to process and offset is the starting point. The
 *   function should return a string which is a shell command that the thread
 *   will execute in a separate process.
 * @param string $teardown_function
 *   A function which runs when a thread completes. It's signature is:
 *   my_teardown_function($thread_id);
 *   Your business logic can then run any cleanup which occurs when the
 *   thread completes.
 * @param int $starting_offset
 *   (optional) Start x records into the process.
 */
function drush_thread_manager($job_count, $job_batch_size, $thread_count, $setup_function, $teardown_function = '', $starting_offset = 0) {

  if (!function_exists('proc_open')) {
    throw new Exception('proc_open command is needed to use multi threading.');
  }

  $jobs_remaining = $job_count;
  $processes = array();
  $running = TRUE;
  $offset = $starting_offset;
  $start = time();

  $descriptor_spec = array(
    0 => array("pipe", "r"),
    1 => array("pipe", "w"),
    2 => array("pipe", "w"),
  );

  while ($running) {

    // Fill all empty threads.
    for ($thread_id = 0; $thread_id < $thread_count; $thread_id++) {
      if ($jobs_remaining > 0 && !isset($processes[$thread_id])) {
        $pipes = array();
        $cmd = $setup_function($thread_id, $job_batch_size, $offset);
        $process = proc_open($cmd, $descriptor_spec, $pipes);

        drush_print("Thread {$thread_id} starts at offset $offset. Jobs remaining: $jobs_remaining");

        foreach ($pipes as $pipe) {
          stream_set_blocking($pipe, FALSE);
        }

        $offset += $job_batch_size;
        $jobs_remaining -= $job_batch_size;

        $processes[$thread_id] = array(
          'process' => $process,
          'pipes' => $pipes,
        );

        //sleep(1);
      }
    }

    // Monitor running threads.
    for ($thread_id = 0; $thread_id < $thread_count; $thread_id++) {
      if (!isset($processes[$thread_id])) {
        continue;
      }

      $process_running = _mt_monitor_process($thread_id, $processes[$thread_id]['process'], $processes[$thread_id]['pipes']);

      if (!$process_running) {
        unset($processes[$thread_id]);

        if (!empty($teardown_function)) {
          $teardown_function($thread_id);
        }

        $speed = ($job_count - $jobs_remaining) / (time() - $start);
        $end_date = date('G:i:s d/m/y', ($job_count / $speed) + $start);
        $speed = floor($speed * 60);

        drush_print("Thread {$thread_id} finished. Average speed is {$speed} jobs/minute. Estimated completion at {$end_date}");
      }
    }

    // Check for endgame.
    if ($jobs_remaining < 1 && empty($processes)) {
      $running = FALSE;
    }
    else {
      // Pause the master process.
      sleep(1);
    }
  }
}

/**
 * Monitor a process.
 *
 * This function checks a running process.
 * If it has finished it is closed down safely.
 *
 * @return bool
 *   TRUE if the process is still running
 *   FALSE if it is not running.
 */
function _mt_monitor_process($thread_id, $process, $pipes) {
  $status = proc_get_status($process);

  foreach ($pipes as $id => $pipe) {
    if ($id == 0) {
      // Don't read from stdin!
      continue;
    }

    $messages = stream_get_contents($pipe);

    if (!empty($messages)) {
      foreach (explode("\n", $messages) as $message) {
        $message = str_replace('[error]', '', $message);
        $message = str_replace('[completed]', '', $message);
        $message = trim($message);
        if (!empty($message)) {
          if ($id == 1) {
            // Message from stdout.
            drush_print(" -> T$thread_id: $message");
          }
          else {
            // Message from stderr.
            drush_set_error(" -> T$thread_id: $message");
          }
        }
      }
    }
  }

  if (!$status['running']) {
    foreach ($pipes as $pipe) {
      fclose($pipe);
    }

    proc_close($process);
  }

  return $status['running'];
}
