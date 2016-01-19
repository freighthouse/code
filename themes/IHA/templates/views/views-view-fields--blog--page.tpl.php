<div class="blog_group">
  <div class="field-blog-image list_blog_image">
    <?php print (!empty($fields['field_blog_image'])) ?
        $fields['field_blog_image']->content : ''; ?>
  </div>
  <div class="field-blog-publish-date">
    <?php print (!empty($fields['field_blog_publish_date'])) ?
        $fields['field_blog_publish_date']->content : ''; ?>
  </div>
  <div class="views-field-title">
    <?php print (!empty($fields['title'])) ?
        $fields['title']->content : ''; ?>
  </div>
  <div class="field-blog-body">
    <?php print (!empty($fields['field_blog_body'])) ?
        $fields['field_blog_body']->content : ''; ?>
  </div>
</div>
