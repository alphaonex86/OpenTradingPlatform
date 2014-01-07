var ws = $.websocket("ws://127.0.0.1:8080/", {
        open: function() { console.log("WebSocket open"); },
        close: function() { console.log("WebSocket closed"); },
        events: {
				open: function(e) { console.log("Can open"); },
                say: function(e) {
                        alert(e.data.name); // 'foo'
                        alert(e.data.text); // 'baa'
                }
        }
});


function refresh(){
	ws.send("refresh");
}

//setInterval(refresh, 10000)