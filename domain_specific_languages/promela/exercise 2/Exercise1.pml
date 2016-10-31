////ex1
chan request = [10] of {byte}

active proctype Server(){
byte number;
do
:: request ? number -> printf("Number %d\n", number); //reply ! true
od
}

active proctype Client1(){
int i = 0;
  do
  :: i >= 10 -> break;
  :: atomic {i < 10 ->  request ! i; i++;}
  od
}