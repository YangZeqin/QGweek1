#include "LinkStack.c"
#include <stdio.h>
#include <stdlib.h>
void StackTraverse(LinkStack *s);

int main(){
	int num;
	int i,j;
	int flag=0;
	LinkStack s;
	printf("1.initLStack\n");
	printf("2.isEmptyLStack\n");
	printf("3.getTopLStack\n");
	printf("4.clearLStack\n");
	printf("5.destroyLStack\n");
	printf("6.LStackLength\n");
	printf("7.pushLStack\n");
	printf("8.pushLStack\n");
	printf("-----------------\n");
	while(1){
		printf("������Ҫ���Ĺ��ܱ�ţ�\n");
		printf("-----------------\n");
		scanf("%d",&num);
		switch(num){
			case 1:
				flag=1;
				if(initLStack(&s)==SUCCESS){
					printf("initLStack���Գɹ�\n");
					printf("-----------------\n");
				}
				else {
					printf("initLStack����ʧ��\n");
					printf("-----------------\n");
				}
				break;
			case 2:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(isEmptyLStack(&s)==SUCCESS){
					printf("��ջΪ�գ�isEmptyLStack���Գɹ�\n");
					printf("-----------------\n");
				}
				else{
					printf("��ջ��Ϊ�գ�isEmptyLStack���Գɹ�\n");
					printf("-----------------\n");
				}
				break;
			case 3:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(getTopLStack(&s,&i)==SUCCESS){
					printf("ջ��Ԫ��Ϊ%d,getTopLStack���Գɹ�\n");
					printf("-----------------\n");
				}
				break;
			case 4:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(clearLStack(&s)==SUCCESS){
					printf("clearLStack���Գɹ�\n");
					printf("-----------------\n");
				}
				break;
			case 5:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(destroyLStack(&s)==SUCCESS){
					printf("destroyLStack���Գɹ�\n");
					printf("-----------------\n");
					flag=0;
					break;
				}
			case 6:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(LStackLength(&s,&i)==SUCCESS){
					printf("��ǰ��ջ�ĳ���Ϊ%d,LStackLength���Գɹ�\n",i);
					printf("-----------------\n");
				}
				break;
			case 7:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				printf("������Ҫ��ջ��ջ�ĸ�����\n");
				scanf("%d",&j);
				printf("������Ҫѹ��ջ��ջ��Ԫ�ش�С��\n");
				while(j-->0){
					scanf("%d",&i);
					pushLStack(&s,i);
				}
				printf("������ջ�õ���");
				StackTraverse(&s);
				printf("pushLStack���Գɹ�\n");
				break;	
			case 8:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}	
				printf("������Ҫ��ջ��ջ�ĸ�����\n");
				scanf("%d",&j);
				if(j>s.count){
					printf("��������������ջ��������ջ�ĸ���\n");
					continue;
				}
				else{
					while(j-->0){
					popLStack(&s,&i);
				}
				printf("������ջ�õ���");
				StackTraverse(&s);
				printf("popLStack���Գɹ�\n");
				break;	
				}
		}
	}
	return 0;
}

void StackTraverse(LinkStack *s){
	StackNode *p=s->top;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
