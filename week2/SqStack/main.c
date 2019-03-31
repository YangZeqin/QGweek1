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
		printf("请输入要检测的功能编号：\n");
		printf("-----------------\n");
		scanf("%d",&num);
		switch(num){
			case 1:
				flag=1;
				printf("请输入要开辟的顺序栈的size：\n");
				scanf("%d",&size);
				if(initStack(&s,size)==SUCCESS){
					printf("initStack测试成功\n");
				}
				break;
			case 2:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(isEmptyStack(&s)==SUCCESS){
					printf("顺序栈为空，isEmptyLStack测试成功\n");
					printf("-----------------\n");
				}
				else{
					printf("顺序栈不为空，isEmptyLStack测试成功\n");
					printf("-----------------\n");
				}
				break;
			case 3:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(getTopStack(&s,&e)==SUCCESS){
					printf("栈顶元素为%d，getTopStack测试成功\n",e);
					printf("-----------------\n");
				}
				else{
					printf("顺序栈为空，无栈顶元素，getTopStack测试成功\n");
					printf("-----------------\n");
				}
				break;
			case 4:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(clearStack(&s)==SUCCESS){
					printf("clearStack测试成功\n");
					printf("-----------------\n");
				}
				break;
			case 5:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(destroyStack(&s)==SUCCESS){
					printf("destroyStack测试成功\n");
					printf("-----------------\n");
					flag=0;
				}
				break;
			case 6:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(stackLength(&s,&e)==SUCCESS){
					printf("顺序栈的长度为%d,stackLength测试成功\n",e);
					printf("-----------------\n");
				}
				break;
			case 7:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				printf("请输入要入栈的栈的个数：\n");
				scanf("%d",&e);
				if(e>s.size){
					printf("输入错误：要输入的栈的个数大于栈的大小\n");
					continue;
				}
				else{
					printf("请输入要入栈的数据：\n");
					while(e-->0){
						scanf("%d",&i);
						pushStack(&s,i);
					}
					printf("遍历顺序栈得到：");
					StackTraverse(&s);
					printf("pushStack测试成功\n");
					printf("-----------------\n");
					break;
				}
			case 8:
				if(flag==0){
					printf("请先对链栈进行初始化\n");
			    	continue;
				}
				if(s.top==-1){
					printf("当前顺序栈为空栈，无法进行出栈操作\n");
					continue;
				}
				printf("请输入要出栈的栈的个数：\n");
				scanf("%d",&e);
				if(e>s.top+1){
					printf("输入错误：出栈的栈的个数多于现有的栈\n");
				}
				else{
					while(e-->0){
						popStack(&s,&i);
					}
					printf("遍历顺序栈得到：");
					StackTraverse(&s);
					printf("popStack测试成功\n");
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
