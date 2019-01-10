<?php

	function get_basic_newsletter_report()
	{
		$type = 'newsletter_signup';
		$query = new EntityFieldQuery;
		$result = $query
			->entityCondition('entity_type', 'node')
			->propertyCondition('status', 1)
			->propertyCondition('type', $type)
			->execute();

		if(sizeof($result) === 0) {
			$toReturn = '<p>There was a problem accessing the newsletter signups please contact your site administrator.</p>';
		}  else {
			$toReturn = '<table>';
			$toReturn .= '
				<tr>
					<th>Email</th>
					<th>Has Full Account</th>
					<th>Rif Newsletter</th>
					<!--<th>LC Newsletter</th>
					<th>LN Newsletter</th>-->
				</tr>';

			foreach($result['node'] as $pos => $item) {
				$emw_node = entity_metadata_wrapper('node', $pos);
				if(!$emw_node->field_get_rif_newsletter->value() /* &&
					!$emw_node->field_get_lc_newsletter->value()&&
					!$emw_node->field_get_ln_newsletter->value()*/
				) { continue; }

				$toReturn .= '
				<tr>
					<td>'.$emw_node->field_email->value().'</td>
					<td>'.($emw_node->author->uid->value() ? '&#10003;' : '').'</td>
					<td>'.($emw_node->field_get_rif_newsletter->value() ? '&#10003;' : '').'</td>
					<!--<td>'.($emw_node->field_get_lc_newsletter->value() ? '&#10003;' : '').'</td>
					<td>'.($emw_node->field_get_ln_newsletter->value() ? '&#10003;' : '').'</td>-->
				</tr>';
			}


			$toReturn .= '</table>';
		}

		$toReturn = '<div class="container">'.$toReturn.'</div>';

		$content['raw_markup'] = array(
			'#type' => 'markup',
			'#markup' => $toReturn,
		);

		return $content;
	}
