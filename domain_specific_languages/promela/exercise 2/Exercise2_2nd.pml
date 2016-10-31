
//comoplete
chan request = [2] of {byte, chan}
chan reply [5] = [2] of {byte }

active [2] proctype Server(){
byte client;
chan replyChannel;
do
:: request ? client, replyChannel -> printf("Client %d processed by server %d\n", client, _pid); reply[client] ! _pid;
									 replyChannel ! _pid
od
}

active [5] proctype Client0(){
byte server;

do
:: request ! _pid-2, reply[_pid-2]; reply[_pid-2] ? server;
od

}