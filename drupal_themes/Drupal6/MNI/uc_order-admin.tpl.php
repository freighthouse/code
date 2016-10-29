<?php
// $Id: uc_order-admin.tpl.php,v 1.1.2.1 2010/07/16 15:45:09 islandusurper Exp $

/**
 * @file
 * This file is the default admin notification template for Ubercart.
 */
?>

<p>
<h3>New Order from MNINEWS</h3>
<?php echo t('Order number:')." ".$order_admin_link; ?><br />
<?php echo t('Customer:')." ".$order_first_name." ".$order_last_name; ?><br />
<?php echo t('Customer Email:')." ".$order_email; ?><br />
<?php echo t('Payment Method:')." ".$order->payment_method; ?><br />
<?php if($order_vat_number) { echo t('Order vat-number:')." ".$order_vat_number;
} ?><br />
<?php echo t('Billing Address:')." ".$order_billing_address; ?><br />
<?php echo t('Billing Phone:')." ".$order_billing_phone; ?><br />
<?php if (uc_order_is_shippable($order)) { 
                echo t('Shipping method:')." ".$order_shipping_method;
} ?>
<p>
<?php echo t('Products:'); ?><br />
<?php
$context = array(
  'revision' => 'themed',
  'type' => 'order_product',
);
foreach ($products as $product) {
    $price_info = array(
    'price' => $product->price,
    'qty' => $product->qty,
    );
    $context['subject'] = array(
    'order_product' => $product,
    );
?>
- Quantity: <?php echo $product->qty; ?><br />
- Product ID: <?php echo $product->nid; ?><br />
- Title: <?php echo $product->title; ?><br />
- Price: <?php echo uc_price($price_info, $context); ?><br />
<br />
<?php } ?>
</p>

<p><?php
$taxes=$order->data['taxes'];
if (!empty($taxes)) {
    echo "Taxes Applied:<br />";

    foreach ($taxes as $tax) {
        echo $tax->name." rate:".    $tax->rate."<br>";
    }
}
?></p>
<p><?php 
$context = array(
  'revision' => 'themed',
  'type' => 'line_item',
  'subject' => array(
    'order' => $order,
  ),
);
foreach ($order->line_items as $line_item) {
    if ($line_item['line_item_id'] == 'subtotal' || $line_item['line_item_id'] == 'total') {
        continue;
    }
    $context['subject']['line_item'] = $line_item;
    echo str_replace("xx", "x", $line_item['title']).": ".uc_price($line_item['amount'], $context)."<br>"; //the xx x thing is for some reason it spells excluding exxcluding.
}
?>
Shipping Cost: 0<br>
Rebate (0%) = 0<br>
<?php echo t('Order subtotal:')." ".$order_subtotal; ?><br>
<?php echo t('Order total:')." ".$order_total; ?><br>
</p>
<p>
<?php echo t('Order comments:')." ".$order_comments; ?>
</p>
