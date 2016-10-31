#define N 10
chan procChan[N] = [100] of {byte}

active [N] proctype process(){	
	byte d = -1, f = -1, e = -1;
	byte max = -1;
	
	activ:
	d = _pid;
	atomic{
	do
	::	procChan[ (_pid +1 ) % N ] ! d ->
		procChan[ (N - _pid - 1) % N ] ? e;
		if
			:: ( e == _pid ) -> printf("1. Process %d is elected\n", _pid);
		fi
		if
			:: ( d > e ) -> procChan[ (_pid +1 ) % N ] ! d;
			:: else -> procChan[ (_pid +1 ) % N ] ! e;
		fi
		procChan[ (N - _pid - 1) % N ] ? f;
		if
			:: ( f == _pid ) -> printf("2. Process %d is elected\n", _pid);	
		fi
		if
			:: d > f -> max = d
			:: else -> max = f
		fi
		if
			:: ( e >=  max) -> d = e;
			:: else -> goto relay;
		fi

	od

	relay:
	do
		:: 	procChan[ (N - _pid - 1) % N ] ? d -> 
			if
			:: ( d == _pid ) -> printf("3. Process %d is elected\n", _pid);
			fi
			procChan[ (_pid +1 ) % N ] ! d ->
	od
	}
}