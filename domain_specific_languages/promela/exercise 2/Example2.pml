//incomoplete
chan request = [0] of {byte}
chan reply = [0] of {byte}

active [2] proctype Server(){
byte client;
do
:: request ? client -> printf("Client %d processed by server %d\n", client, _pid); reply ! _pid;
od
}

active [2] proctype Client0(){
byte server;

request ! _pid;
reply ? server;
printf("Reply received from server %d by client %d\n", server, _pid);

}