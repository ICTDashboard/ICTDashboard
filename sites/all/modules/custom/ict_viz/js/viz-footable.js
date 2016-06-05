jQuery(function($){
	$('.viz-filtered-projects').footable({
		"on": {
			"init.ft.table": function(e, ft){
				// bind to the plugin initialize event to do something
				console.log('hi');
			}
		}
	});
});