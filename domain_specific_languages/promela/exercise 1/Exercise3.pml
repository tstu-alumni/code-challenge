int x = 5;
int y = 8;
int z = 11;
active proctype P(){
  if
  :: y < x -> z = x;
  :: else -> z = y;
  fi
}

active proctype Q(){
  x--
}

active proctype R(){
  y=x-1;
}