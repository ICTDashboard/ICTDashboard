<?php
header('Content-type: application/json');
$ch = curl_init();
$url = 'http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql='.urlencode($_GET['sql']);
#file_put_contents('/tmp/sql.sql', $url."\n", FILE_APPEND | LOCK_EX);
curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_HEADER, 0);
curl_exec($ch);
curl_close($ch);
?>