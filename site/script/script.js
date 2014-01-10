var Ws,
	lang;
	

function checkDepencies(){
	return (!window.WebSocket);
}

/**
 *  @brief one page of the server
 */
function Page(){}

Page.prototype.constructor = Page;

if(checkDepencies()){
	alert("Upgrade your browser to see this page");
}

Ws = (function(){
	// Address to connect to
	var address = "ws://127.0.0.1:8080/request";
	
	// Number of attempt done
	var attempt = 0;

	// The websocket
	var ws= null;
	
	function onmessage(evt){
		console.log( "Received Message: "); 
		console.log(JSON.parse(evt.data)); 
	}
	
	function onclose(evt) { 
		console.log("WebSocket::closed"); 
		setTimeout(reconnect, 90000);
	};
	
	function onerror(evt) { 
		console.log("WebSocket::error"); 
		console.log(evt) ;
	};
	
	function onopen(evt) { 
		console.log("WebSocket::open"); 
		attempt = 0; 
	}; 
	
	function connect() {
		ws = new WebSocket(address);
		setTimeout(bindEvents, 1000);
		
		ws.onmessage = onmessage;
		ws.onclose = onclose;
		ws.onerror = onerror;
		
		console.log("WebSocket::init");
	}

	function bindEvents() {
		// Event
		if(ws.readyState != ws.OPEN){
			ws.onopen = onopen;
			console.log("Websocket::bindEvents");
		}else{
			onopen();
		};
	}
	
	function getWebsocket(){
		return ws;
	}
	
	function reconnect(){
		if(attempt <3){
			attempt ++;
			console.log("Websocket >> Trying to reconnect...");
			connect();
		}
	}

	// Send a objet using Json
	function send(obj){
		if(ws.readyState==ws.OPEN){
			console.log( "Sending Message: "); 
			console.log(obj); 
			if(obj instanceof Object){
				ws.send(JSON.stringify(obj));
				if(!obj.type){
					console.warn("Sending invalid object, server may refuse");
				}
			}else{
				ws.send(JSON.stringify({type:obj}));
			}
			return true;
		}else{
			return false;
		}
	}

	// Testing purpose
	function refresh(){
		if(ws.readyState==ws.OPEN){
			send({message:"foo"}); // testing purpose
		}
	}
	
	// WIP
	function isLogged()
	{
		return true;
	}
	
	// Request
	function sell(owned, quantity, price)
	{
		/**
		 * pass order to sell bitcoin:
		 * - Quantity of bitcoin owned
		 * - Quantity to sell
		 * - Price to sell
		 */
		if(isLogged()){
			return send({
				type:"sell",
				owned: owned,
				quantity: quantity,
				price: price
			});
		}else{
			return false;
		}
	}
	
	function buy(owned, quantity, price)
	{
		/**
		 * pass order to Buy bitcoin:
		 * - Quantity of euro owned
		 * - Quantity to how many euro to use
		 * - Price to buy
		 */
		if(isLogged()){
			return send({
				type:"buy",
				owned: owned,
				quantity: quantity,
				price: price
			});
		}else{
			return false;
		}
	}
	
	function setLang(code)
	{
		/**
		 * pass order to change the lang of a client:
		 * - code of the lang
		 */
		if(isLogged()){
			return send({
				type:"lang",
				lang: code
			});
		}else{
			return false;
		}
	}
	
	connect();
	
	return {
		// Direct websocket action
		send:send,
		getWs:getWebsocket,
		
		// Possible request
		buy:     buy,
		sell:    sell,
		setLang: setLang
	};
})();

lang = (function(){
	var lang_data = {};
	var can_request = false;
	var _code;
	
	var DefaultLang = "EN_en";
	
	 // Dev address
	var _address = "http://localhost/lang/";
	
	// Should be .xml for real
	var _extension = ".php";
	
	function _initLang(){
		can_request = true;
		
		// language format needed will be like EN_en or EN_us or FR_fr [...]
		if(navigator.language.length == 2){
			setLang(navigator.language.toUpperCase()
					+"_"
					+navigator.language.toLowerCase());
		}else{
			setLang(navigator.language);
		}
	}
	
	function setLang(code){
		if(_code == code || !can_request) return false;
		$.ajax( {
            type: "GET",
            url: _address + code + _extension,
            dataType: "xml",
            success: function(xml) 
			{
				$(xml).find('tr').each(   
					function()
					{
						lang_data[ $(this).attr('id') ] = $(this).text();
					}
				);
				_code = code;
			},
			error: function(error)
			{
				if( code != DefaultLang){
					setLang(DefaultLang);
				}
			}
        });
		return true;
	}
	
	function tr(code){
		var translation = lang_data[code];
		if( translation )
		{
			return translation;
		}else{
			return code;
		}
	}
		
	$(document).ready( _initLang() );
	
	return { 
			tr: tr,
			setLang:setLang 
	};
}());