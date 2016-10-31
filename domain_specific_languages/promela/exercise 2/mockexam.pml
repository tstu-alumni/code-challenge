//complete
mtype {request, reply}

chan internet = [1000] of {mtype, byte}
chan serverChan1 = [1000] of {mtype, byte}
chan serverChan2 = [1000] of {mtype, byte}

active [2] proctype client() {
/* code to be added */
	byte serverReply;
	printf("Client process id %d initiated\n", _pid);
	if
	::	atomic{
			internet ! request, _pid ->
				printf("Client process id %d sent a request\n", _pid);
		}
	fi
	if
	::	atomic{
			internet ?? reply, eval(_pid) ->
				printf("Client process id %d received a reply\n", _pid);
		}
	fi
}

active [1] proctype proxy() {
/* code to be added */
	byte clientRequest, clientId;
	printf("Proxy process id %d initiated\n", _pid);
	do
	::	internet ?? request, clientId ->
			printf("Proxy process id %d received a request from client process id %d\n", _pid, clientId);
			if
			:: serverChan1 ! request, clientId;
			:: serverChan2 ! request, clientId;
			fi
	od
}

proctype server(chan channel) {
/* code to be added */
	byte clientRequest, clientId;
	printf("Server process id %d initiated\n", _pid);
	do
	::	channel ? clientRequest, clientId ->
			printf("Server process id %d received a request from client process id %d\n", _pid, clientId);
			internet ! reply, clientId;
			printf("Server process id %d sent a reply to client process id %d\n", _pid, clientId);
	od
}

init {
run server(serverChan1);
run server(serverChan2)
}