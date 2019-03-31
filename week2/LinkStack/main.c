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
		printf("请输入要检测的功能编号：\n");
		printf("-----------------\n");
		scanf("%d",&num);
		switch(num){
			case 1:
				flag=1;
				if(initLStack(&s)==SUCCESS){
					printf("initLStack测试成功\n");
					printf("-----------------\n");
				}
				else {
					printf("initLStack测试失败\n");
					printf("-----------------\n");
				}
				break;
			case 2:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(isEmptyLStack(&s)==SUCCESS){
					printf("链栈为空，isEmptyLStack测试成功\n");
					printf("-----------------\n");
				}
				else{
					printf("链栈不为空，isEmptyLStack测试成功\n");
					printf("-----------------\n");
				}
				break;
			case 3:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(getTopLStack(&s,&i)==SUCCESS){
					printf("栈顶元素为%d,getTopLStack测试成功\n");
					printf("-----------------\n");
				}
				break;
			case 4:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(clearLStack(&s)==SUCCESS){
					printf("clearLStack测试成功\n");
					printf("-----------------\n");
				}
				break;
			case 5:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(destroyLStack(&s)==SUCCESS){
					printf("destroyLStack测试成功\n");
					printf("-----------------\n");
					flag=0;
					break;
				}
			case 6:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(LStackLength(&s,&i)==SUCCESS){
					printf("当前链栈的长度为%d,LStackLength测试成功\n",i);
					printf("-----------------\n");
				}
				break;
			case 7:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				printf("请输入要入栈的栈的个数：\n");
				scanf("%d",&j);
				printf("请输入要压入栈的栈的元素大小：\n");
				while(j-->0){
					scanf("%d",&i);
					pushLStack(&s,i);
				}
				printf("遍历链栈得到：");
				StackTraverse(&s);
				printf("pushLStack测试成功\n");
				break;	
			case 8:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}	
				printf("请输入要出栈的栈的个数：\n");
				scanf("%d",&j);
				if(j>s.count){
					printf("输入错误：所输入出栈个数大于栈的个数\n");
					continue;
				}
				else{
					while(j-->0){
					popLStack(&s,&i);
				}
				printf("遍历链栈得到：");
				StackTraverse(&s);
				printf("popLStack测试成功\n");
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
