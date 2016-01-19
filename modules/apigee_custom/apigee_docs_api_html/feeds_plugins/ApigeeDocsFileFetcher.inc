<?php

/**
 * @file
 * Home of the ApigeeDocsFileFetcher and related classes.
 *
 * It adds recursive directory scanning, also, it respects file extensions.
 */

/**
 * Fetches data via HTTP.
 */
class ApigeeDocsFileFetcher extends FeedsFileFetcher {

  /**
   * Implements FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);

    // Just return a file fetcher result if this is a file.
    if (is_file($source_config['source'])) {
      return new FeedsFileFetcherResult($source_config['source']);
    }

    $allowed = explode(' ', trim($this->config['allowed_extensions']));

    // Batch if this is a directory.
    $state = $source->state(FEEDS_FETCH);
    $files = array();


    $destination = file_stream_wrapper_get_instance_by_uri('public://apigee_docs_api_html')->realpath();

    if (!isset($state->files) && !empty($source_config['branch'])) {
      $git_dir = md5($source_config['source']) . '.git';
      $source_path = $destination . '/' . $git_dir;

      if (!file_prepare_directory($destination, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
        throw new Exception(t('Files directory either cannot be created or is not writable.'));
      }

      $start_dir = getcwd();
      $branch = escapeshellarg($source_config['branch']);

      if (file_exists($source_path)) {
        $this->rRmdir($source_path);
      }

      if (!is_dir($source_path)) {
        chdir($destination);
        $url = escapeshellarg($source_config['source']);
        $command = "git clone --recursive --branch $branch $url $git_dir";
        shell_exec($command);
      }
      else {
        chdir($source_path);
        shell_exec("git checkout $branch");
        shell_exec('git reset --hard');
        shell_exec('git clean -d -fx ""');
        shell_exec('git pull');
      }
      chdir($start_dir);
    }
    else {
      $source_path = $source_config['source'];
    }


    if (!isset($state->files)) {
      $state->files = $this->listFilesRecursive($source_path, $allowed);
      $state->total = count($state->files);
    }
    if (count($state->files)) {
      $file = array_shift($state->files);
      $state->progress($state->total, $state->total - count($state->files));
      return new FeedsFileFetcherResult($file);
    }

    throw new Exception(t('Resource is not a file or it is an empty directory: %source', array('%source' => $source_path)));
  }

  /**
   * Recursively remove a directory.
   * @param string $dir
   *   The directory to remove.
   */
  protected function rRmdir($dir) {
    foreach (scandir($dir) as $file) {
      if ($file === '.' || $file === '..') {
        continue;
      }
      $file = $dir . '/' . $file;
      if (is_dir($file)) {
        $this->rRmdir($file);
      }
      else {
        unlink($file);
      }
    }
    rmdir($dir);
  }

  /**
   * Return an array of files in a directory.
   *
   * @param $dir
   *   A stream wreapper URI that is a directory.
   *
   * @return
   *   An array of stream wrapper URIs pointing to files. The array is empty
   *   if no files could be found. Never contains directories.
   */
  protected function listFilesRecursive($dir, $allowed) {
    $dir = file_stream_wrapper_uri_normalize($dir);
    $files = array();
    if ($items = @scandir($dir)) {
      // Scan files.
      $dirs = array();
      while ($item = array_shift($items)) {
        $file_uri = "$dir/$item";
        if (is_file($file_uri)) {
          $files[] = $file_uri;
        }
        elseif (is_dir($file_uri) && $item != '.' && $item != '..' && $item != '.git') {
          $dirs[] = $file_uri;
        }
      }
      while ($dir = array_shift($dirs)) {
        $files = array_merge($files, $this->listFilesRecursive($dir, $allowed));
      }
    }

    return $files;
  }

  /**
   * Source form.
   */
  public function sourceForm($source_config) {

    // $source_config = $source_config + $this->sourceDefaults();

    $form = parent::sourceForm($source_config);

    $form['source']['#description'] = '';
    $form['source']['#title'] = t('File or url');

    $form['branch'] = array(
      '#type' => 'textfield',
      '#title' => t('Branch'),
      '#default_value' => isset($source_config['branch']) ? $source_config['branch'] : 'master',
    );

    $form['table_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Table ID'),
      '#default_value' => isset($source_config['table_id']) ? $source_config['table_id'] : 'table_id',
    );


    return $form;
  }

  /**
   * Override parent validation.
   *
   * @todo Add validation for form inputs.
   */
  public function sourceFormValidate(&$values) {
		//set the table id in the validation. cool :)
		variable_set('feeds_import_table_id',$values['table_id']);
    // parent::sourceFormValidate($values);
  }

  public function sourceDefaults() {
    return array(
      'branch' => 'master',
    ) + parent::sourceDefaults();
  }
}
