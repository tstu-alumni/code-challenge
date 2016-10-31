//enhenced by the author
chan request = [0] of {byte}
chan reply = [0] of {bool}

active proctype Server(){
byte client;
do
:: request ? client -> printf("Client %d\n", client); //reply ! true
od
}

active proctype Client0(){
do
::atomic{
    printf("Client side 0\n");
    request ! 0;
    //reply ? _
  }
 od
}

active proctype Client1(){
do
:: atomic{
    printf("Client side 1\n");
    request ! 1;
    //reply ? _
  }
od
}