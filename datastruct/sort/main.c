#include<stdio.h>
#include"FXsort.h"
#include<time.h>
#include<stdlib.h>
#define FXMAXNUM 100

int main(){
    
    srand((unsigned int) time(0));
    int num[FXMAXNUM] = {};
    for(int loop = 0;loop < FXMAXNUM;loop++){
    
        num[loop] = rand()%1000;
    }
	
	int size = sizeof(num)/sizeof(num[0]);

//	bubble_sort(num1,size);
//	switch_sort(num2,size);
	quick_sort(num,0,size-1);

	for(int loop = 0;loop<size;loop++){
	
		printf("<%d>",num[loop]);
	}
	return 0;
}
