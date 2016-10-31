//incomoplete
chan request = [0] of {byte, chan}
chan reply [2] = [0] of {byte, byte}

active [2] proctype Server(){
byte client;
chan replyChannnel
do
:: request ? client, replyChannnel -> printf("Client %d processed by server %d\n", client, _pid); replyChannnel ! _pid, client;
od
}

active [2] proctype Client0(){
byte server;
byte whichChannel;

request ! _pid, reply[_pid - 2];
reply[_pid - 2] ? server;
printf("Reply received from server %d by client %d\n", server, _pid);

}