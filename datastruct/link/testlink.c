#include "link.h"
int compare(void*,void*);
int main(){
	
	
	link* lds = NULL;
	lds = FXinit(lds);
	int loop = 0;
	for(;loop < 10;loop++){
	
		int* p = malloc(4);
		*p = loop;
		FXin_data_back(p,lds->head);
	}

	printf("count:%d\n",FXcount(lds));
	
	int num = 4;
	printf("data is 4: %d\n",*(int*)(FXfind(&num,lds,compare)->p_data));


	FXclean(lds);
	free(lds);
	lds=NULL;
	return 0;
}

int compare(void* p1,void* p2){

	if(*(int*)p1 == *(int*)p2)return 1;

	return 0;
}

