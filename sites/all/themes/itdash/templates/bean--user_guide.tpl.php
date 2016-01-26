<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

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
