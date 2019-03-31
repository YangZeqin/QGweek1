#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX 100

//说明：
//在小黑窗中只能识别英文输入法下的小括号
//负数如果不出现在第一个数的位置，必须包含在括号里面 
typedef struct SqStack1{
	double num[100];
	int top;
}SqStack1;

typedef struct SqStack2{
	char ope[100];
	int top;
}SqStack2;

SqStack1 NumStack;
SqStack2 OpeStack;
	
void pushNumStack(SqStack1 *s,double e);
void pushOpeStack(SqStack2 *s,char e);
void popNumStack(SqStack1 *s,double *e);
void popOpeStack(SqStack2 *s,char *e);
double count(double x,double y,char ope);
char compare(char ch1,char ch2);


int main(){
	//初始化工作 
	char line[MAX];
	char t[MAX];   //暂时存储数字
	scanf("%s",line);
	int len=strlen(line);
	NumStack.top=-1;
	OpeStack.top=-1;
	int i=0;       //遍历line
	int j=0;       //移动t数组 
	double a;      //将字符串转换为数据入栈 
	double x,y;
	char ope;
	while(line[i]!='\0'){
		//数字 
		if(line[i]>='0'&&line[i]<='9'){
			//读取数字 
			j=0;
			while((line[i]>='0'&&line[i]<='9')||line[i]=='.'){
				t[j++]=line[i];
				i++;
			}
			//数字入栈
			t[j]='\0';
			a=atof(t);
//			printf("%f",a);
			pushNumStack(&NumStack,a);
		}
		//符号 
		else if(line[i]=='+'||line[i]=='-'||line[i]=='*'||line[i]=='/'||line[i]=='('||line[i]==')'){
			//'-'表示负数
			if(line[i]=='-'&&(i==0||line[i-1]=='(')){
				pushNumStack(&NumStack,0);  //把0弹入数字栈
				pushOpeStack(&OpeStack,line[i]);  //把'-'弹入符号栈
				i++; 
			} 
			//普通运算符的情况 
			else{
				//入栈 
				if(compare(OpeStack.ope[OpeStack.top],line[i])=='>'||OpeStack.top==-1){   
					pushOpeStack(&OpeStack,line[i]);
					i++;
				}
				//括号的特殊情况 
				else if(compare(OpeStack.ope[OpeStack.top],line[i])=='='){
					i++;
					OpeStack.top--;
				}
				else{
					while(compare(OpeStack.ope[OpeStack.top],line[i])=='<'){
						popNumStack(&NumStack,&x);
						popNumStack(&NumStack,&y);
						popOpeStack(&OpeStack,&ope);
						countnum(y,x,ope);
					}
				}
			}
		}
	}
	while(OpeStack.top!=-1){
		popNumStack(&NumStack,&x);
		popNumStack(&NumStack,&y);
		popOpeStack(&OpeStack,&ope);
		countnum(y,x,ope);
	}
	printf("the result is %f",NumStack.num[NumStack.top]);
	return 0;
}


void pushNumStack(SqStack1 *s,double e){           //传入指针才能修改！！！！！！ 
	s->top++;
	s->num[s->top]=e;
}

void pushOpeStack(SqStack2 *s,char e){
	s->top++;
	s->ope[s->top]=e;
}

void popNumStack(SqStack1 *s,double *e){
		*e=s->num[s->top];
		s->top--;
}

void popOpeStack(SqStack2 *s,char *e){
		*e=s->ope[s->top];
		s->top--;
}

void countnum(double x,double y,char ope){
	double res;
	if(ope=='+') res=x+y;
	else if(ope=='-') res=x-y;
	else if(ope=='*') res=x*y;
	else if(ope=='/') res=x/y;
	pushNumStack(&NumStack,res);
}

char compare(char ch1,char ch2){
	char ope[]="+-*/()";
	int i,j;
	char table[6][7]={
		"<<>>><",
		"<<>>><",
		"<<<<><",
		"<<<<><",
		">>>>>=",
		"<<<<=<",
	};
	for(i=0;i<7;i++) if(ope[i]==ch1) break;
	for(j=0;j<7;j++) if(ope[j]==ch2) break;
	return table[i][j];
}

