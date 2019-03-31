#include "SqStack.c"
#include <stdio.h>
#include <stdlib.h>
void StackTraverse(SqStack *s);

int main(){
	int num;
	int flag=0;
	int size;
	int e;
	int i;
	SqStack s;
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
				printf("������Ҫ���ٵ�˳��ջ��size��\n");
				scanf("%d",&size);
				if(initStack(&s,size)==SUCCESS){
					printf("initStack���Գɹ�\n");
				}
				break;
			case 2:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(isEmptyStack(&s)==SUCCESS){
					printf("˳��ջΪ�գ�isEmptyLStack���Գɹ�\n");
					printf("-----------------\n");
				}
				else{
					printf("˳��ջ��Ϊ�գ�isEmptyLStack���Գɹ�\n");
					printf("-----------------\n");
				}
				break;
			case 3:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(getTopStack(&s,&e)==SUCCESS){
					printf("ջ��Ԫ��Ϊ%d��getTopStack���Գɹ�\n",e);
					printf("-----------------\n");
				}
				else{
					printf("˳��ջΪ�գ���ջ��Ԫ�أ�getTopStack���Գɹ�\n");
					printf("-----------------\n");
				}
				break;
			case 4:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(clearStack(&s)==SUCCESS){
					printf("clearStack���Գɹ�\n");
					printf("-----------------\n");
				}
				break;
			case 5:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(destroyStack(&s)==SUCCESS){
					printf("destroyStack���Գɹ�\n");
					printf("-----------------\n");
					flag=0;
				}
				break;
			case 6:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(stackLength(&s,&e)==SUCCESS){
					printf("˳��ջ�ĳ���Ϊ%d,stackLength���Գɹ�\n",e);
					printf("-----------------\n");
				}
				break;
			case 7:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				printf("������Ҫ��ջ��ջ�ĸ�����\n");
				scanf("%d",&e);
				if(e>s.size){
					printf("�������Ҫ�����ջ�ĸ�������ջ�Ĵ�С\n");
					continue;
				}
				else{
					printf("������Ҫ��ջ�����ݣ�\n");
					while(e-->0){
						scanf("%d",&i);
						pushStack(&s,i);
					}
					printf("����˳��ջ�õ���");
					StackTraverse(&s);
					printf("pushStack���Գɹ�\n");
					printf("-----------------\n");
					break;
				}
			case 8:
				if(flag==0){
					printf("���ȶ���ջ���г�ʼ��\n");
			    	continue;
				}
				if(s.top==-1){
					printf("��ǰ˳��ջΪ��ջ���޷����г�ջ����\n");
					continue;
				}
				printf("������Ҫ��ջ��ջ�ĸ�����\n");
				scanf("%d",&e);
				if(e>s.top+1){
					printf("������󣺳�ջ��ջ�ĸ����������е�ջ\n");
				}
				else{
					while(e-->0){
						popStack(&s,&i);
					}
					printf("����˳��ջ�õ���");
					StackTraverse(&s);
					printf("popStack���Գɹ�\n");
					printf("-----------------\n");
					break;
				}		
				
		}
	}
	return 0;
} 

void StackTraverse(SqStack *s){
	int p=s->top;
	while(p>=0){
		printf("%d ",s->elem[p]);
		p--;
	}
}
