#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top=(StackNode *)malloc(sizeof(StackNode));
	if(s->top==NULL) return ERROR;
	s->top->next=NULL;
	s->top->data=0;
	s->count=1;
	return SUCCESS;	
}

Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if(s->count==0) return SUCCESS;
	else return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
	if(s->count==0) return ERROR;
	*e=s->top->data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s)   //清空栈
{
	if(s->count==0) return ERROR;
	LinkStackPtr p;
	while(s->top){
		p=s->top;
		s->top=s->top->next;
		s->count--;
		free(p);
	}
	return SUCCESS;	
}

Status destroyLStack(LinkStack *s)   //销毁栈
{
	clearLStack(s);
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	*length=s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
	if(s->count==1){
		s->top->data=data;
		s->count++;	
	}
	else{
		LinkStackPtr p=(StackNode *)malloc(sizeof(StackNode));
		p->data=data;
		p->next=s->top;
		s->top=p;
		s->count++;
	}
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
	if(s->count==0) return ERROR;
	LinkStackPtr p=s->top;
	s->top=s->top->next;
	s->count--;
	free(p);
	return SUCCESS;
}
