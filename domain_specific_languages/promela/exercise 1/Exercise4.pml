#define upper_level 60
#define lower_level 40
int amount = 20;
bool isP1 = false;
bool isP3 = false;
//input
active proctype P1(){
  do
  :: isP1 -> amount++; printf("Liquid level is %d\n", amount);
  od
}
//Sensor
active proctype P2(){
  do
  :: atomic { amount <= lower_level -> isP1 = true; isP3 = false; }
  :: atomic { amount >= upper_level -> isP1 = false; isP3 = true; }
  od    
}
//output
active proctype P3(){
  do
  :: isP3 -> amount--; printf("Liquid level is %d\n", amount);
  od
}