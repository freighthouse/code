<?php

	function reading_challenges_view_entity($reading_challenge) {
		//drupal_set_title($reading_challenge->name);
		//$rc_entity = entity_view('reading_challenge', array($reading_challenge->id => $reading_challenge));

		$emw_node = entity_metadata_wrapper('node', $reading_challenge->reading_passage_id);
		$body_text = $emw_node->get('body')->value()['value'];

		$duration = $reading_challenge->duration;
		$minutes = floor($duration / 60);
		$seconds = $duration - ($minutes * 60);

		$output = theme('reading_challenges__completed_challenge', array(
			'reading_passage_title' => $emw_node->get('field_display_title')->value(),
			'body_text' => $body_text,
			'total_words' => $reading_challenge->total_words,
			'clicked_words' => $reading_challenge->words_incorrect,
			'minutes' => $minutes,
			'seconds' => $seconds,
			'score' => $reading_challenge->weighted_score,
		));
		return $output;
	}