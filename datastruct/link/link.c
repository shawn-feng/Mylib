#include"link.h"

link* FXinit(link* lds){

	lds = calloc(1,sizeof(link));
	lds->head = calloc(1,sizeof(node));
	lds->tail = calloc(1,sizeof(node));
	lds->head->p_next = lds->tail;
	lds->tail->p_last = lds->head;
	lds->cur_node = lds->head->p_next;
	return lds;
}

void FXdel_init(link* lds){

	for(lds->cur_node = lds->head->p_next;lds->cur_node != lds->tail;){
	
		node* temp = lds->cur_node->p_next;
		FXdel_node(lds->cur_node);
		lds->cur_node = temp;
	}
	return;
}

void FXdel_node(node* delnode){
	
	delnode->p_next->p_last = delnode->p_last;
	delnode->p_last->p_next = delnode->p_next;
	free(delnode);
}

void FXclean(link* lds){

	FXdel_init(lds);
	free(lds->head);
	free(lds->tail);
	lds->head = NULL;
	lds->tail = NULL;
	lds->cur_node = NULL;
	return ;
}

void FXin_node_back(node* innode,node* pnode){
	
	pnode->p_next->p_last = innode;
	innode->p_next = pnode->p_next;
	innode->p_last = pnode;
	pnode->p_next = innode;

	return;
}

void FXin_data_back(void *p_data,node* pnode){

	node* newn = calloc(1,sizeof(node));
	newn->p_data = p_data;
	FXin_node_back(newn,pnode);
	return;
}

void FXin_node_front(node* innode,node* pnode){

	FXin_node_back(innode,pnode->p_next);
	return;
}

void FXin_data_front(void *p_data,node* pnode){

	FXin_data_back(p_data,pnode->p_next);
	return;
}


node* FXfind(void*p_data,link* lds,int(*compare)(void*,void*)){
	
	for(lds->cur_node = lds->head->p_next;lds->cur_node != lds->tail;lds->cur_node = lds->cur_node->p_next){
	
		if(compare(p_data,lds->cur_node->p_data))return lds->cur_node;
	}
	
	return NULL;
}

int FXcount(link* lds){
	
	int count = 0;
	for(lds->cur_node = lds->head->p_next;lds->cur_node != lds->tail;lds->cur_node = lds->cur_node->p_next){
		count++;
	}

	return count;
}

void* FXarray_node(link* lds,node* array[],int count){

	lds->cur_node = lds->head->p_next;

	for(int loop = 0;loop < count;loop++){
		
		*(array+loop) = lds->cur_node;
		lds->cur_node = lds->cur_node->p_next;
	}

	return array;
}

void FXsort(link* lds,int(*compare_data)(const void*,const void*)){

	int count = FXcount(lds);
	node* array[count];

	FXarray_node(lds,array,count);

	qsort(array,count,sizeof(node),compare_data);

}

void* FXgetdata(node* p_node){

	return p_node->p_data;
}

void FXinit_with_arr(node* arr[],int count,link* lds){

	for(int loop = 0;loop < count;loop++){
		
		FXin_node_back(*(arr+loop),lds->head);
	}
	return ;
}
