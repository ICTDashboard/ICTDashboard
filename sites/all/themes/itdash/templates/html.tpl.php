<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup themeable
 */
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>

<head profile="<?php print $grddl_profile; ?>">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>

  <!--[if lt IE 9]>
  <script type="text/javascript" src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->

  <?php print $styles; ?>
  <?php print $scripts; ?>
  <link rel="stylesheet" id="icon-stylesheet-css"  href="http://netdna.bootstrapcdn.com/font-awesome/4.0.0/css/font-awesome.css" type="text/css" media="all" />

  <!--[if lte IE 8]>  <script type="text/javascript" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/js/r2d3.js"></script><![endif]-->
  <!--[if gte IE 9]><!-->
  <script type="text/javascript" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/js/d3.v3.min.js"></script>
  <!--<![endif]-->

  <link href="/<?php print drupal_get_path('theme', 'itdash'); ?>/css/nv.d3.css" rel="stylesheet">
  <script type="text/javascript" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/js/nv.d3.js"></script>
  <script type="text/javascript" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/js/d3-timeline.js"></script>
  <!--[if lt IE 9]>
  <script type="text/javascript" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/js/flashcanvas.js"></script>
  <![endif]-->
  <script type="text/javascript" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/js/flotr2.min.js"></script>
  <script type="text/javascript" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/js/moment.min.js"></script>
  <script type="text/javascript" src="/<?php print drupal_get_path('theme', 'itdash'); ?>/js/jquery.fn.gantt.js"></script>

  <!--meta name="viewport" content="width=device-width, initial-scale=1.0"/-->
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
<div id="skip-link">
  <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
</div>
<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?>
</body>
</html>
