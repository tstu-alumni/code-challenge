mtype {request, reply, delay}
chan internet = [1000] of {mtype, byte}

proctype process(){
	printf("Request = %d\n", request);
	printf("Reply = %d\n", reply);
	printf("Delay = %d\n", delay);
}

active [2] proctype client(){
	internet ! request, _pid
}

active [2] proctype proxy(){
	byte clientRequest, clientId;
	do
	::	internet ? clientRequest, clientId ->
		printf("Proxy %d processed a Request = %d from Client %d\n", _pid, clientRequest, clientId);
	od
}

//init{
	//run process();
//}