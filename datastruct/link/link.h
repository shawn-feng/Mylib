#ifndef LINK_H
#define LINK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	void *p_data;
	struct node* p_next;
	struct node* p_last;
}node;

typedef struct link{
	struct node* head;
	struct node* tail;
	struct node* cur_node;
}link;



link* FXinit(link*);
void FXdel_init(link*);
void FXclean(link*);
void FXdel_node(node*);
void FXin_node_back(node*,node*);
void FXin_node_front(node*,node*);
void FXin_data_back(void*,node*);
void FXin_data_front(void*,node*);

node* FXfind(void*,link*,int(*compare)(void*,void*));
void FXsort(link*,int(*)(const void*,const void*));
int FXcount(link*);
void* FXarray_node(link*,node* arr[],int);
void* FXgetdata(node*);
void FXinit_with_arr(node* arr[],int count,link* lds);

#endif
