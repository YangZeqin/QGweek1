#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h> 
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	LNode *p=(LNode *)malloc(sizeof(LNode));
	if(p==NULL) return ERROR;
	else{
		p->next=NULL;
		*L=p;
		return SUCCESS;
	}
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LNode *p=*L;
	while(p!=NULL){
		*L=p->next;
		free(p);
		p=*L;
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	q->next=p->next;
	p->next=q;
	return SUCCESS; 
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LNode *q=p->next;
	*e=q->data;
	p->next=q->next;
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode *p=L;
	while(p!=NULL){
		visit(p->data);
		p=p->next;
	}
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e 
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode *p=L;
	while(p!=NULL){
		if(p->data==e) break;
		else p=p->next;
	}
	if(p==NULL) return ERROR;
	else return SUCCESS;
} 

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LNode *p1=*L;
	LNode *p2=NULL;
	LNode *t=NULL;
	while(p1!=NULL){
		t=p1->next;
		p1->next=p2;
		p2=p1;
		p1=t;
	}
	*L=p2;
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LNode *fast=L->next;
	LNode *slow=L->next;
	while(fast!=NULL&&slow!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow) return SUCCESS;
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish 
 */
LNode* ReverseEvenList(LinkedList *L) {
	LNode *p,*q,*r,*head;
	p=(LNode *)malloc(sizeof(LNode));
	head=p;
	q=*L;
	p->data=q->data;
	q=q->next;
	while(q){
        p->next=(LNode *)malloc(sizeof(LNode));
        p=p->next;
        p->data=q->data;
	    q=q->next;
	}
	p->next=NULL;
	p=(LNode *)malloc(sizeof(LNode));
	p->next=head;
	q=p->next;
	r=q->next;
	while(r){
		if(r->data%2==0){
			if(p->next==head){
				q->next=r->next;
				r->next=q;
				head=r;	
			}
			else{
				q->next=r->next;
				r->next=q;
				p->next=r;
			}
		}
		p=p->next;
		q=p->next;
	    r=q->next;
	}
	return head;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish 
 */
LNode* FindMidNode(LinkedList *L) {
	LNode *fast=(*L)->next;
	LNode *slow=(*L)->next;
	while(fast->next!=NULL&&fast->next->next!=NULL){
		slow=slow->next;
		fast=fast->next->next; 
	}
	return slow;
}
