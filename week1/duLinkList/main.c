#include "duLinkedList.c"
#include <stdio.h>
#include <stdlib.h>

DuLNode *create();
void visit(ElemType e);

int main(){
	int i;
	int flag=0;
	ElemType e;
	DuLNode *L=NULL;
	printf("1:InitList_DuL\n");
	printf("2:DestroyList_Du\n");
	printf("3:InsertBeforeList_Du\n");
	printf("4:InsertAfterList_DuL\n");
	printf("5:DeleteList_DuL\n");
	printf("6:TraverseList_DuL\n");
	printf("==================\n");
	while(1){
		printf("请输入要测试的函数的编号：\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				flag=1;
				if(InitList_DuL(&L)==SUCCESS) {
					printf("InitList测试成功\n");
				}
				else printf("InitList测试失败\n");
				break;
			case 2:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1-><-2-><-3-><-4-><-5的链表以供测试\n");
				L=create();
//				TraverseList_DuL(L,visit);
				DestroyList_DuL(&L);
				if(L==NULL) printf("DestroyList测试成功\n");
				break;
			case 3:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1-><-2-><-3-><-4-><-5的链表以供测试\n");
				L=create();
				printf("请输入你想插入在第几个位置之前：\n");
				int position1;
				scanf("%d",&position1);
				DuLNode *p1=L;
				int j1=1;
				while(j1<position1){
					p1=p1->next;
					j1++;
					}
				printf("请输入你要插入的数据：\n");
				int data;
				scanf("%d",&data);
				DuLNode *q=(DuLNode *)malloc(sizeof(DuLNode));
				q->data=data;				
				if(InsertBeforeList_DuL(p1,q)==SUCCESS){
					printf("InsertBeforeList_DuL测试成功\n");
					TraverseList_DuL(L,visit);	
					}
				break;
			case 4:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1-><-2-><-3-><-4-><-5的链表以供测试\n");
				L=create();
				printf("请输入你想插入在第几个位置之后：\n");
				int position2;
				scanf("%d",&position2);
				DuLNode *p2=L;
				int j2=1;
				while(j2<position2){
					p2=p2->next;
					j2++;
				}
				printf("请输入你要插入的数据：\n");
				int data2;
				scanf("%d",&data2);
				DuLNode *q2=(DuLNode *)malloc(sizeof(DuLNode));
				q2->data=data2;
				if(InsertAfterList_DuL(p2,q2)==SUCCESS){
					printf("InsertAfterList_DuL测试成功\n");
					TraverseList_DuL(L,visit);
				}
				break;
			case 5:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1-><-2-><-3-><-4-><-5的链表以供测试\n");
				L=create();
				printf("请选择你想删除第几个位置之后的第一个结点:\n");
				int position3;
				scanf("%d",&position3);
				DuLNode *p3=L;
				int j3=1;
				while(j3<position3){
					p3=p3->next;
					j3++;
				}		
				if(DeleteList_DuL(p3,&e)==SUCCESS) printf("DeleteList_DuL测试成功:\n");
				TraverseList_DuL(L,visit);
				break;
			case 6:
				if(flag==0){
					printf("请先对函数进行初始化\n");
			    	continue;
				}
				printf("已为你生成一个1-><-2-><-3-><-4-><-5的链表以供测试\n");
				L=create();
				TraverseList_DuL(L,visit);
				printf("TraverseList_DuL测试成功\n");
				break;
		}
	}
	return 0;
}

DuLNode *create(){                                  //返回一个数据为1-><-2-><-3-><-4-><-5的带头指针的链表 
	DuLNode *p1=(DuLNode *)malloc(sizeof(DuLNode));
	DuLNode *p2=p1;
	DuLNode *head;
	for(int a=1;a<=5;a++){
		if(a==1){
			head=p1;
			p2->next=NULL;
			p2->prior=NULL;
		}
		else{
			p2->next=p1;
		}
		p2=p1;
		p2->data=a;
		p1=(DuLNode *)malloc(sizeof(DuLNode));
		p1->prior=p2;
	}
	p2->next=NULL;
	free(p1);
	p1=NULL;
	return head;
}

void visit(ElemType e){
	printf("%d ",e);
}


