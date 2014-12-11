TODO make timestamp/name/metric unique key

To create the datastore resource, make a dataset with url "it-dashboard-data" then:
$ curl -X POST http://127.0.0.1:5000/api/3/action/datastore_create \
-H "Authorization: {YOUR-SYSADMIN-API-KEY}" \
-d '{"resource": {"package_id":"it-dashboard-data"},"fields": [{"id":"timestamp","type":"text"},{"id":"name","type":"text"},{"id":"metric","type":"text"},{"id":"value","type":"text"}]}'