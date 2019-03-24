#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	DuLNode *head;  
	head=(DuLNode*)malloc(sizeof(DuLNode)); 
	if(head==NULL) return ERROR;
	else{
		head->prior=NULL;   
		head->next=NULL;
		*L=head;
		return SUCCESS;
	}
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode *p=*L;
	while(*L){
		*L=p->next;
		free(p);
        p=*L;
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	DuLNode *r;
	r=p->prior;
	r->next=q;
	p->prior=q;
	q->next=p;
	q->prior=r;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	DuLNode *r;
	r=p->next;
	r->prior=q;
	p->next=q;
	q->next=r;
	q->prior=p;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLNode *q=p->next;
	DuLNode *r=q->next;
	*e=q->data;
	p->next=r;
	r->prior=p;
	free(q);
	p=NULL;
	return SUCCESS;
	
}
 
/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode *p=L;
	while(p){
		visit(p->data);
		p=p->next;
	}
}

