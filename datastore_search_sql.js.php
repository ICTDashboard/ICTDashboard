<?php
header('Content-type: application/json');
echo file_get_contents('http://ckan.itdash.lws.links.com.au/api/action/datastore_search_sql?sql='.$_GET['sql']);
?>