#define N 10

proctype P(){
  int i = 0;
  do
  :: i<10 -> printf("Hello\n"); i++;
  :: i<10 -> printf("World\n"); i++;
  :: i >= N -> break;
  od  
}

init{
  run P();
}
