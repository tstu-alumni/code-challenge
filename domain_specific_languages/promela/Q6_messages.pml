mtype {request , reply}

chan internet = [3] of {mtype, byte, byte}

chan serverChan1 = [1] of {mtype, byte}
chan serverChan2 = [1] of{mtype, byte}

active [2] proctype client() {
  byte sid 
  //do
  if
  :: internet ! request , _pid, 1;
  	 printf("Client %d sent a request\n", _pid);
     internet ? reply , eval(_pid), sid
  	 printf("Client %d received a reply from the server %d \n", _pid, sid);
  fi
  //od
}

active[2]proctype proxy() {
  byte id;
  do
    :: internet ? request , id, 1;
	   printf("Proxy %d received a request from the client %d\n", _pid, id);
    if
      :: serverChan1 ! request , id
      :: serverChan2 ! request , id
    fi
	  printf("Proxy %d redirected a request form client %d\n", _pid, id);
  od
}

proctype server(chan channel) {
  byte id;
  do
  :: channel ? request ,id;
  	 printf("Server %d received a request from the client %d\n", _pid, id);
     internet ! reply ,id, _pid
	 printf("Server %d sent a reply to the client %d\n", _pid, id );
  od
}

init {
  run server(serverChan1);
  run server(serverChan2)
}