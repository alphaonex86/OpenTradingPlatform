var customWs;
if (window.WebSocket) {
	
	customWs = (function(){
		// Address to connect to
		var address = "ws://127.0.0.1:8080";
		
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
		
		connect();
		
		return {
			send:send,
			getWs:getWebsocket
		};
	})();
}else{
	// Too old browser
	alert("Your browser don't support WebSocket");
}