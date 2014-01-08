
if (window.WebSocket) {
	var ws= new WebSocket("ws://127.0.0.1:8080");

	ws.onopen = function(evt) { console.log("Connection open ..."); }; 
	ws.onmessage = function(evt) { console.log( "Received Message: "); console.log(JSON.parse(evt.data)); }; 
	ws.onclose = function(evt) { console.log("Connection closed."); };
	ws.onerror = function(evt) { console.log("WebSocket error : "); console.log(evt) };

	function send(obj){
		if(ws.readyState==ws.OPEN){
			console.log( "Sending Message: "); 
			console.log(obj); 
			if(obj instanceof Object){
				ws.send(JSON.stringify(obj));
			}else{
				ws.send(JSON.stringify({type:obj}));
			}
			return true;
		}else{
			return false;
		}
	}

	function refresh(){
		if(ws.readyState==ws.OPEN){
			send({message:"foo"}); // testing purpose
		}
	}
	
	//setInterval(refresh, 10000);
}else{
	alert("Your browser don't support WebSocket");
}