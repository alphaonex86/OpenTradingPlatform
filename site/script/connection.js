var customWs;
if (window.WebSocket) {
	
	customWs = (function(){
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
}else{
	// Too old browser
	alert("Your browser don't support WebSocket");
}