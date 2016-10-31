mtype {request , reply}

chan internet = [3] of {mtype, byte, byte}

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


proctype server() {
  byte id;
  do
  :: internet ? request ,id, 1;
  	 printf("Server %d received a request from the client %d\n", _pid, id);
     internet ! reply ,id, _pid
	 printf("Server %d sent a reply to the client %d\n", _pid, id );
  od
}

init {
  run server();
  run server()
}