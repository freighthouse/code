<?php

/**
 * @file
 *   Address template for BIPAC Officials
 *
 * @args
 *   $office_type
 *   $address_1
 *   $address_2		// Note that city/state/zip are conflated with 2 & 3
 *   $address_3		// This is a data limitation
 *   $phone
 *   $fax
 */
?>

<div class="official-address">
  <?php if (!empty($office_type) && ($office_type == 'Capitol Office') ): ?><div class="official-address-officetype"><?php echo $office_type; ?></div><?php endif; ?>
  <?php if (!empty($address_1)): ?><div class="official-address-address-1"><?php echo $address_1; ?></div><?php endif; ?>
  <?php if (!empty($address_2)): ?><div class="official-address-address-2"><?php echo $address_2; ?></div><?php endif; ?>
  <?php if (!empty($address_3)): ?><div class="official-address-address-3"><?php echo $address_3; ?></div><?php endif; ?>
  <?php if (!empty($address_4)): ?><div class="official-address-address-4"><?php echo $address_4; ?></div><?php endif; ?>
  <?php if (!empty($address_5)): ?><div class="official-address-address-5"><?php echo $address_5; ?></div><?php endif; ?>
  <?php if (!empty($address_6)): ?><div class="official-address-address-6"><?php echo $address_6; ?></div><?php endif; ?>
  <?php if (!empty($phone)): ?><div class="official-address-phone"><?php print t('P: '); ?><?php echo $phone; ?></div><?php endif; ?>
  <?php if (!empty($fax)): ?><div class="official-address-fax"><?php print t('F: '); ?><?php echo $fax; ?></div><?php endif; ?>
</div>
