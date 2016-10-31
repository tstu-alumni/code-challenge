#define N 10

active proctype P(){
  int array[N];
  int product = 1;
  /* to be added */
  int i = 0;
  do
  :: i >= 10 -> break;
  :: i < 10 -> array[i] = 1; i++; 
  :: i < 10 -> array[i] = 2; i++;
  :: i < 10 -> array[i] = 3; i++;
  :: i < 10 -> array[i] = 4; i++;
  :: i < 10 -> array[i] = 5; i++;
  :: i < 10 -> array[i] = 6; i++;
  :: i < 10 -> array[i] = 7; i++;
  :: i < 10 -> array[i] = 8; i++;
  :: i < 10 -> array[i] = 9; i++;
  :: i < 10 -> array[i] = 10; i++;
  od;
  i = 0;
  do
  :: i >= 10 -> break;
  :: else -> product = product * array[i]; i++;
  od;
  printf("The product is: %d\n", product)
}

//init{
//  run P();
//}
