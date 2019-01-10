<?php
/**
 * @file
 * Default theme implementation for beans.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="hero-container">
        <div class="content"<?php print $content_attributes; ?>>
            <div class="inner-content">
                <h1><?php print $title; ?></h1>
                <?php if ($content['field_summary']): ?>
                    <?php print render($content['field_summary']); ?>
                <?php endif; ?>
                <?php if ($content['field_link']): ?>
                    <?php print render($content['field_link']); ?>
                <?php endif; ?>

                <?php //print render($content['']); ?>
            </div>
        </div>
        <div class="homepage-hero-slider">
            <?php if ($content['field_video_url']): ?>
                <div class="embedded-video">
                    <iframe id="ytplayer" type="text/html"
                            src="<?php print ($content['field_video_url']['#items'][0]['safe_value']); ?>?autoplay=1&loop=1&rel=0&mute=1&playlist=Op_t685ZbsU"
                            frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>
                </div>
            <?php elseif (count($content['field_hero_image']['#items']) > 1): ?>
                <?php print render($content['field_hero_image']); ?>
            <?php elseif ($content['field_hero_image']): ?>
                <?php print render($content['field_hero_image']); ?>
            <?php endif; ?>
        </div>
    </div>
    <?php if ($content['field_hero_description']): ?>
    <div class="homepage-hero-description">
        <div class="field-hero-description">
            <?php print render($content['field_hero_description']); ?>
        </div>
    </div>
    <?php endif; ?>
</div>
