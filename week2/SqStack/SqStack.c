#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h> 

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));
	if(s->elem==NULL) return ERROR;
	s->top=-1;
	s->size=sizes;
	return SUCCESS;
}
	

Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==-1) return SUCCESS;
	else return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if(s->top==-1) return ERROR;
	*e=(s->elem)[s->top];
	return SUCCESS;
	
}

Status clearStack(SqStack *s)   //���ջ
{
	s->top=-1;
	return SUCCESS;
	
}

Status destroyStack(SqStack *s)  //����ջ
{
	free(s->elem);
	s->top=-1;
	s->size=0;
	return SUCCESS;
}


Status stackLength(SqStack *s,int *length)   //���ջ����
{
	if(s->top==-1) return ERROR;
	*length=(s->top)+1;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	if(s==NULL||s->top>=s->size-1) return ERROR;
	s->top++;
	s->elem[s->top]=data;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	if(s==NULL||s->top==-1) return ERROR;
	*data=s->elem[s->top];
	s->top--;
	return SUCCESS;
}


