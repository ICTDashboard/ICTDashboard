<?php
/**
 * @file
 * ckan_api.inc
 */


class ckan_api_ValidateError extends Exception{}
class ckan_api_ActionNotExistsError extends Exception{}
class ckan_api_CKANSideError extends Exception{}


class CkanApi {
  private $api_key;
  private $base_url;

  private $post_actions = array(
      'resource_create' => array('required' => array('package_id', 'url')),
      'resource_update' => array('required' => array('id'))
    );
  private $get_actions = array(
    'resource_get_json_file' => array()
  );

  private $allowed_methods = array('GET', 'POST');

  private static $_instance = null;

  private function __construct() {
    $this->set_base_url( variable_get('ckan_url'), variable_get('ckan_api_version', 3) );
  }

  private function set_base_url($base_url, $api_version) {
    $this->base_url = "{$base_url}/api/{$api_version}/action/";
  }

  private function validate($data, $info)  {
    foreach ($info['required'] as $num => $field) {
      if ( !array_key_exists($field, $data) ) throw new ckan_api_ValidateError("Field $field must be defined", 400);
    }
  }

  public function set_api_key($api_key) {
    $this->api_key = $api_key;
  }

    static public function getInstance() {
    if( is_null(self::$_instance) ){
      self::$_instance = new self();
    }
    return self::$_instance;
  }


  public function action($action, $params=array() ) {
    $data = array(
      'headers' => array(
          'Content-Type' => 'application/x-www-form-urlencoded',
          'X-CKAN-API-Key' => array_key_exists('api_key', $params) ? $params['api_key'] : variable_get('ckan_admin_key'
        ),
      ),
    );
    $params += array('data'=>array());

    if ( array_key_exists($action, $this->post_actions) ) {
      $this->validate( $params['data'], $this->post_actions[$action]);
      $data['data'] = $params['data'];
      $data['method'] = 'POST';

      $rdata = $this->curl_request_data($this->base_url.$action, $data);

      if ($rdata->success) {
        return $rdata->result;
      } else {
        watchdog('ckan_' . $action, serialize($rdata));
        return $rdata->error;
      }
    }
    else if ( array_key_exists($action, $this->get_actions ) ) {
      //$this->validate( $params['data'], $this->get_actions[$action]);
      //$data['data'] = $params['data'];
      $data['method'] = 'GET';

      $rdata = $this->curl_get_json_data($params['url'], $data);

      if ($rdata) {
        return $rdata;
      } else {
        watchdog('ckan_' . $action, 'Could not read the file');
        return $rdata;
      }
    }

    if ( !isset($data['method']) ) throw new ckan_api_ActionNotExistsError('Invalid action');
	
  }

  private function curl_request_data($url, $data=array()) {
  	/* cURL with SOCKS PROXY setup */
  	$ch = curl_init();
  	     
  	if($ch === false) {
  	    die('Failed to create curl object');
  	}

  	$timeout = 60 * 5;
  	curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_POST, TRUE);
  	curl_setopt($ch, CURLOPT_POSTFIELDS, $data['data']);
  	curl_setopt($ch, CURLOPT_HTTPHEADER, array(
  		'X-CKAN-API-Key: ' . $data['headers']['X-CKAN-API-Key']
  	));
  	curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
  	curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $timeout);

  	//proxy details
  	curl_setopt($ch, CURLOPT_PROXY, '127.0.0.1:2001');
  	curl_setopt($ch, CURLOPT_PROXYTYPE, CURLPROXY_SOCKS4);
  	 
  	$req_res = curl_exec($ch);

  	// $info = curl_getinfo($ch);

  	curl_close($ch);

    $rdata = json_decode($req_res);

    return $rdata;
  }

  private function curl_get_json_data($url, $data=array()) {
    $timeout = 5;
    // var_dump($url); die;
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $timeout);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array(
      'X-CKAN-API-Key: ' . $data['headers']['X-CKAN-API-Key']
    ));
    curl_setopt($ch, CURLOPT_HEADER, false);

    //proxy details
    curl_setopt($ch, CURLOPT_PROXY, '127.0.0.1:2001');
    curl_setopt($ch, CURLOPT_PROXYTYPE, CURLPROXY_SOCKS4);

    $get_data = curl_exec($ch);
    // $info = curl_getinfo($ch);
    curl_close($ch);

    // var_dump($info);
    $rdata = json_decode($get_data, true);

    return $rdata;
  }

}


