<?php

function ckan_remote_post_views_data() {

  $tableName = 'ckan_remote_post_submissions';
  $data = array();
  $data[$tableName]['table']['group'] = t('CKAN');

  $data[$tableName]['table']['base'] = array(
    'field' => 'id',
    'title' => t('Ckan submissions results'),
    'help' => t("Contains CKAN submissions results")
  );

  $data[$tableName]['sid'] = array(
    'title' => t('Submission ID'),
    'help' => t('Submission ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data[$tableName]['timestamp'] = array(
    'title' => t('Date created'),
    'help' => t('Date when submission was sent'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data[$tableName]['status'] = array(
    'title' => t('Submission status'),
    'help'  => t('Submission status'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data[$tableName]['result'] = array(
    'title'    => t('Result'),
    'help'     => t('Result'),
    'field'    => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument'  => array('handler' => 'views_handler_argument_numeric'),
    'filter'    => array('handler' => 'views_handler_filter_numeric'),
    'sort'      => array('handler' => 'views_handler_sort_numeric')
  );

  $data[$tableName]['payload'] = array(
    'title'    => t('Submission data'),
    'help'     => t('Submission data'),
    'field'    => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument'  => array('handler' => 'views_handler_argument_numeric'),
    'filter'    => array('handler' => 'views_handler_filter_numeric'),
    'sort'      => array('handler' => 'views_handler_sort_numeric')
  );

  $data[$tableName]['header'] = array(
    'title'    => t('Submission Header'),
    'help'     => t('Submission Header'),
    'field'    => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument'  => array('handler' => 'views_handler_argument_numeric'),
    'filter'    => array('handler' => 'views_handler_filter_numeric'),
    'sort'      => array('handler' => 'views_handler_sort_numeric')
  );

  $data[$tableName]['url'] = array(
    'title'    => t('Submission URL'),
    'help'     => t('Submission URL'),
    'field'    => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument'  => array('handler' => 'views_handler_argument_numeric'),
    'filter'    => array('handler' => 'views_handler_filter_numeric'),
    'sort'      => array('handler' => 'views_handler_sort_numeric')
  );

  $data[$tableName]['id'] = array(
    'title'     => t('Unique identifier'),
    'help'      => t('Primary key for table'),
    'field'     => array('handler' => 'views_handler_field'),
    'argument'  => array('handler' => 'views_handler_argument_numeric'),
    'filter'    => array('handler' => 'views_handler_filter_numeric'),
    'sort'      => array('handler' => 'views_handler_sort_numeric'));

  return $data;
}