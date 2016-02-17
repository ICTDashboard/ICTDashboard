<div class="page-title dotbg">
  <div class="inner-title-content wrap cf">
    <h1><?php print $title; ?></h1>
  </div>
</div>

<div class="<?php print $classes; ?> clearfix wrap  bean-admin-editable"<?php print $attributes; ?>>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      print render($content);
      if (bean_access('update',$variables['elements']['#bundle'])){
            print l('<span>'.t('Edit').'</span>', $url . '/edit',
                array(
                    'attributes' => array('class' => 'general-button'),
                    'html' => TRUE
                )
            );
      }
    ?>
  </div>
</div>
