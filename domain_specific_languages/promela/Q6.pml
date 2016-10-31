mtype {request , reply}

chan internet = [3] of {mtype, byte}

chan serverChan1 = [1] of {mtype, byte}
chan serverChan2 = [1] of{mtype, byte}

active [6] proctype client() {
  do
  :: internet ! request , _pid;
     internet ? reply , eval(_pid)
  od
}

active[2]proctype proxy() {
  byte id;
  do
    :: internet ? request , id;
    if
      :: serverChan1 ! request , id
      :: serverChan2 ! request , id
    fi
  od
}

proctype server(chan channel) {
  byte id;
  do
  :: channel ? request ,id;
     internet ! reply ,id
  od
}

init {
  run server(serverChan1);
  run server(serverChan2)
}