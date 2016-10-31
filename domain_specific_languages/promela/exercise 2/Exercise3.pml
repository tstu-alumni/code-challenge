//comoplete
chan request = [0] of {byte}
chan reply[2] = [0] of {byte}
byte clientNumber = 1;

active proctype Server(){
  byte client;
  reply[0] ! _pid;
  do
    ::  request ? client;
	       if	  
	       	::  client == 0 -> reply[1] ! _pid;
         	::  client == 1 -> reply[0] ! _pid;
	       fi		  
  od

}

active proctype Client1(){
  byte server;  
  do
    ::  reply[0] ? server;
        printf("Hello ");
        request ! 0;  
  od
}

active proctype Client2(){
  byte server;    
  do
    ::  reply[1] ? server;
        printf("World\n");
        request ! 1
  od
}