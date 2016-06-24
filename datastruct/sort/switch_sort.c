#include<stdio.h>


int switch_sort(int num[],int size){

	
	for(int loopi = 0;loopi < size-1;loopi++){
	
		int max = num[loopi];
		int maxindex = loopi;
		for(int loopj = loopi+1;loopj<size;loopj++){
			
			if(max<num[loopj]){
			
				max=num[loopj];
				maxindex = loopj;
			}
		}

		if(loopi == maxindex)continue;

		num[loopi] = num[loopi]^num[maxindex];
		num[maxindex] = num[loopi]^num[maxindex];
		num[loopi] = num[loopi]^num[maxindex];
	}

	return 0;
}
