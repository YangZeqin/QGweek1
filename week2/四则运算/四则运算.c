#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX 100

//˵����
//��С�ڴ���ֻ��ʶ��Ӣ�����뷨�µ�С����
//��������������ڵ�һ������λ�ã������������������ 
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
	//��ʼ������ 
	char line[MAX];
	char t[MAX];   //��ʱ�洢����
	scanf("%s",line);
	int len=strlen(line);
	NumStack.top=-1;
	OpeStack.top=-1;
	int i=0;       //����line
	int j=0;       //�ƶ�t���� 
	double a;      //���ַ���ת��Ϊ������ջ 
	double x,y;
	char ope;
	while(line[i]!='\0'){
		//���� 
		if(line[i]>='0'&&line[i]<='9'){
			//��ȡ���� 
			j=0;
			while((line[i]>='0'&&line[i]<='9')||line[i]=='.'){
				t[j++]=line[i];
				i++;
			}
			//������ջ
			t[j]='\0';
			a=atof(t);
//			printf("%f",a);
			pushNumStack(&NumStack,a);
		}
		//���� 
		else if(line[i]=='+'||line[i]=='-'||line[i]=='*'||line[i]=='/'||line[i]=='('||line[i]==')'){
			//'-'��ʾ����
			if(line[i]=='-'&&(i==0||line[i-1]=='(')){
				pushNumStack(&NumStack,0);  //��0��������ջ
				pushOpeStack(&OpeStack,line[i]);  //��'-'�������ջ
				i++; 
			} 
			//��ͨ���������� 
			else{
				//��ջ 
				if(compare(OpeStack.ope[OpeStack.top],line[i])=='>'||OpeStack.top==-1){   
					pushOpeStack(&OpeStack,line[i]);
					i++;
				}
				//���ŵ�������� 
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


void pushNumStack(SqStack1 *s,double e){           //����ָ������޸ģ����������� 
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

