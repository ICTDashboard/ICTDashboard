<div id="container">

  <header class="header" role="banner">
    <div id="inner-header" class="wrap cf">
      <p id="logo" class="h1"><a href="http://www.finance.gov.au" rel="nofollow">
          <img id="web-logo" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/html/images/agdof-logo.png" alt="ICT Dashboard"/></a>
          <img id="print-logo" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/html/images/dept-logo-print.png" alt="ICT Dashboard"/></a>
          <span><a href="/" rel="nofollow"><strong><?php print t('ICT Projects'); ?></strong><br><?php print t('Dashboard'); ?></a></span>
      </p>
      <nav role="navigation" id="navigation">
        <?php
          $menu = menu_tree('menu-header-menu');
          print drupal_render($menu);
        ?>
      </nav>

      <?php if (user_is_logged_in()) : global $user; ?>
      <div class="user-tools">
        <div>
          <span><?php print $user->name; ?></span>
          <div class="user-option">
            <a class="arrowdown" href="#"><i class="fa fa-sort-down"></i></a>
            <ul>
              <li><a href="<?php print url('user'); ?>"><?php print t('Account'); ?></a></li>
              <li><a href="<?php print url('user/logout')?>"><?php print t('Sign out'); ?></a></li>
            </ul>
          </div>
        </div>
      </div>
      <?php else : ?>
      <div class="login-register">
        <ul>
          <li class="log"><a href="<?php print url('user'); ?>"><?php print t('Sign in'); ?></a></li>
        </ul>
      </div>
      <?php endif; ?>
    </div>
  </header>

  <div id="content">
    <?php if ($content['content']) : ?>
      <?php print $content['content']; ?>
    <?php endif; ?>
  </div>
</div></div>
  <footer class="footer" role="contentinfo">
    <div id="inner-footer">
      <div class="wrap cf">
        <?php $footer_menu_tree = menu_tree('menu-footer-menu'); ?>
        <?php print drupal_render($footer_menu_tree); ?>
        <?php //print l(t('Contact us'), 'mailto:InvestmentFrame@finance.gov.au', array('attributes' => array('id' => 'contact_link'))); ?>
        <p class="copy">
          <?php print t('With the exception of the Commonwealth Coat of Arms, this site is licensed under a Creative Commons Attribution 3.0 licence (CC BY 3.0 AU).'); ?></p>
        <p class="copy second-copy"><?php print t('ICT Projects Dashboard 2016'); ?></p>
      </div>
    </div>
  </footer>

<!--<script type="text/javascript" src="//code.jquery.com/ui/1.11.2/jquery-ui.js"></script>-->
