#include "linkedList.c"
#include <stdio.h>
#include <stdlib.h>

LNode *create();
void visit(ElemType e);

int main(){
	int i;
	int flag=0;
	ElemType e;
	LNode *L=NULL;
	printf("1.InitList\n");
	printf("2.DestroyList\n");
	printf("3.InsertList\n");
	printf("4.DeleteList\n");
	printf("5.TraverseList\n");
	printf("6.SearchList\n");
	printf("7.ReverseList\n");
	printf("8.IsLoopList\n");
	printf("9.ReverseEvenList\n");
	printf("10.FindMidNode\n");
	printf("==================\n");
	while(1){
		printf("请输入要测试的函数的编号：\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				flag=1;
				if(InitList(&L)==SUCCESS) {
					printf("InitList测试成功\n");
				}
				else printf("InitList测试失败\n");
				break;
			case 2:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1->2->3->4->5的链表以供测试\n");
				L=create();
//				TraverseList(L,visit);
				DestroyList(&L);
				if(L==NULL) printf("DestroyList测试成功\n");
				break;
			case 3:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1->2->3->4->5的链表以供测试\n");
				L=create();
				printf("请输入你想插入在第几个位置之后：\n");
				int position1;
				scanf("%d",&position1);
				LNode *p1=L;
				int j1=1;
				while(j1<position1){
					p1=p1->next;
					j1++;
				}
				printf("请输入你要插入的数据：\n");
				int data;
				scanf("%d",&data);
				LNode *q=(LNode *)malloc(sizeof(LNode));
				q->data=data;
				InsertList(p1,q);
				TraverseList(L,visit);
				printf("InsertList测试成功\n");

				break;
			case 4:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1->2->3->4->5的链表以供测试\n");
				L=create();
				printf("请选择你想删除第几个位置之后的第一个结点:\n");
				int position2;
				scanf("%d",&position2);
				LNode *p2=L;
				int j2=1;
				while(j2<position2){
					p2=p2->next;
					j2++;
				}
				if(DeleteList(p2,&e)==SUCCESS) printf("DeleteList测试成功:\n");
				break;
			case 5:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1->2->3->4->5的链表以供测试\n");
				L=create();
				TraverseList(L,visit);
				printf("TraverseList测试成功\n");
				break;
			case 6:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1->2->3->4->5的链表以供测试\n");
				L=create();
				printf("请输入要寻找的节点的数据:\n");
				int e1;
				scanf("%d",&e1);
				if(SearchList(L,e1)==SUCCESS) printf("SearchList测试成功\n");
				break;	
			case 7:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1->2->3->4->5的链表以供测试\n");
				L=create();
//				TraverseList(L,visit);
				if(ReverseList(&L)==SUCCESS)	printf("ReverseList测试成功\n");
				break;
			case 8:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1->2->3->4->5的链表以供测试\n");
				L=create();
				if(IsLoopList(L)==ERROR) printf("IsLoopList测试成功\n");
				break;
			case 9:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1->2->3->4->5的链表以供测试\n");
				L=create();
				LNode *new=ReverseEvenList(&L);
//				TraverseList(new,visit);
				printf("ReverseEvenList测试成功\n");
				break;
			case 10:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1->2->3->4->5的链表以供测试\n");
				L=create();
				if((FindMidNode(&L))->data==3) printf("FindMidNode测试成功\n");
				break;
		}
	}
	return 0;
}

LNode *create(){                                  //返回一个数据为1->2->3->4->5的带头指针的链表 
	LNode *p1=(LNode *)malloc(sizeof(LNode));
	LNode *p2=p1;
	LNode *head;
	for(int a=1;a<=5;a++){
		if(a==1){
			head=p1;
			p2->next=NULL;
		}
		else{
			p2->next=p1;
		}
		p2=p1;
		p2->data=a;
		p1=(LNode *)malloc(sizeof(LNode));
	}
	p2->next=NULL;
	free(p1);
	p1=NULL;
	return head;
}

void visit(ElemType e){
	printf("%d ",e);
}



