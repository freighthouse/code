getSpreadsheetData = function(){
	// ID of the Google Spreadsheet
	var spreadsheetID = '1LFS_iqrZ_V0GLibUqbSyzFeGY2njwcezsq30Hlv8sMY'; // Ed's Google Sheet
	//var spreadsheetID = '2PACX-1vSh9wV5-O0QbYX4WqLKLCH-SpDPiD-41Txq1x9tiyXwgX4npIeskL1Ce0rDZCCOLYG3kXuEbkNg6bne'; // The published page
	//var spreadsheetID = "17_rmnIgf8M3nNoDek4WExEVI87v8WBY9Y9dJEwMKYlE"; // Test Google Sheet

	// Make sure it is public or set to Anyone with link can view
	var url = "https://spreadsheets.google.com/feeds/list/" + spreadsheetID + "/default/public/values?alt=json";
	//console.log(url);

	jQuery.getJSON(url, function(data) {

		// Leaving this here in case we want to prepend some 0's
		function prependZeros(num){
			var str = ("" + num);
			return (Array(Math.max(8-str.length, 0)).join("0") + str);
		}
		function insertCommas(str) {
			var i = str.length;
			var counter = 0;
			var toReturn = '';
			while (i--) {
				counter++;
				toReturn = str.charAt(i)+toReturn;
				if(counter % 3 == 0 && i != 0) {
					toReturn = ','+toReturn;
				}
			}
			return toReturn;
		}

		var entry = data.feed.entry;

		var subTotal = 0;
		jQuery(entry).each(function(){
			subTotal += parseInt(this.gsx$numberofbooks.$t << 0);
		});
		//subTotal = 1879879;
		//subTotal = 7111;
		subTotal = prependZeros(subTotal);
		subTotal = insertCommas(subTotal);
		//subTotal = subTotal.toLocaleString('en-US');
		jQuery('.results').text(subTotal);
		//jQuery('.results').prepend('<h2>Total Books: '+ subTotal +'</h2>');
	});

	var newVal = jQuery('.counter-num').html();
	newVal++;
	jQuery('.counter-num').html(newVal);
};


var tid = setInterval(getSpreadsheetData, 2000);

getSpreadsheetData();