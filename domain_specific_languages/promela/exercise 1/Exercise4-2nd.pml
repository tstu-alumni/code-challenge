#define upperLevel 60
#define lowerLevel 40
int liquidLevel = 50, iteration_counter = 0;
bool inflow = false, outflow = true, request = false

active proctype sensor(){
	do
		:: atomic { (liquidLevel <= 40) -> inflow = true; outflow = false }
		:: atomic { (liquidLevel >= 60) -> inflow = false; outflow = true }
		:: iteration_counter >= 100 -> break;
	od
}

active proctype user(){
	do
		:: request = true; 
		:: request = false;
		:: iteration_counter >= 100 -> break;
	od
}

active proctype inflowDev(){
	do
		:: atomic{ inflow -> liquidLevel++; printf("Liquide level is %d\n", liquidLevel); iteration_counter++ }
		:: iteration_counter >= 100 -> break;
	od	
}

active proctype outflowDev(){
	do
		:: atomic{ ( outflow && request) -> liquidLevel--; printf("Liquide level is %d\n", liquidLevel); iteration_counter++ }
		:: iteration_counter >= 100 -> break;
	od	
}