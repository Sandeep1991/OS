#include<stdio.h>
#include<stdlib.h>
#include "my402list.h"

/* structure for a node 
typedef struct tagMy402ListElem {
    void *obj;
    struct tagMy402ListElem *next;
    struct tagMy402ListElem *prev;
} My402ListElem;
 */
int Length(My402List* list)
{
	return list->num_members;
}

/* For testing the above functions */
int My402ListInit(My402List* list)
{
	list->num_members=0;
	list->anchor.obj=NULL;	
	list->anchor.next=&(list->anchor);
	list->anchor.prev=&(list->anchor);
	return TRUE;
}

int  My402ListAppend(My402List* list, void* obj)
{
	My402ListElem* newlist= (My402ListElem *)malloc(sizeof(My402ListElem));
	if(newlist==NULL)
	{
		//return FALSE;
	}
	list->num_members=list->num_members+1;
	newlist->obj=obj;
	newlist->next=&(list->anchor);
	newlist->prev=list->anchor.prev;
	list->anchor.prev=newlist;
	newlist->prev->next=newlist;	
	
	return TRUE;
}

