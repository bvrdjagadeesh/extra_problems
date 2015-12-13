#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct array
{
	int len;
	char *no;
	int k;
	int result;
};
typedef struct array string;
string* intializetestcase()
{
	string *testcase;
	testcase=(string *)malloc(1*sizeof(string));
	testcase[0].len=2;
	testcase[0].no=(char *)malloc(sizeof(char)*testcase[0].len);
	testcase[0].no="22";
	testcase[0].k=2;
	testcase[0].result=0;
	testcase[1].len=9;
	testcase[1].no=(char *)malloc(sizeof(char)*testcase[1].len);
	testcase[1].no="288944392";
	testcase[1].k=1;
	testcase[1].result=0;
	testcase[2].len=1;
	testcase[2].no=(char *)malloc(sizeof(char)*testcase[2].len);
	testcase[2].no="0";
	testcase[2].k=3;
	testcase[2].result=0;
	testcase[3].len=3;
	testcase[3].no=(char *)malloc(sizeof(char)*testcase[3].len);
	testcase[3].no="555";
	testcase[3].k=2;
	testcase[3].result=0;
	testcase[4].len=4;
	testcase[4].no=(char *)malloc(sizeof(char)*testcase[4].len);
	testcase[4].no="6532";
	testcase[4].k=0;
	testcase[4].result=0;
	testcase[5].len=3;
	testcase[5].no=(char *)malloc(sizeof(char)*testcase[5].len);
	testcase[5].no="-22";
	testcase[5].k=2;
	testcase[5].result=0;
	testcase[6].len=4;
	testcase[6].no=(char *)malloc(sizeof(char)*testcase[6].len);
	testcase[6].no="-555";
	testcase[6].k=0;
	testcase[6].result=0;
	testcase[7].len=2;
	testcase[7].no=(char *)malloc(sizeof(char)*testcase[7].len);
	testcase[7].no="-22";
	testcase[7].k=2;
	testcase[7].result=0;
	return testcase;
}


void start();
int getno(int,char*,int);
int method1(int);
int method2(int);
int* seperate(int);
int diff(int*);
void checkresult(int,int);

void main()
{
	start();
}

void start()
{
	string *testcase=intializetestcase();
	int i,no,output1,output2;
	for(i=0;i<8;i++)
	{
		if(testcase[i].k!=0||testcase[i].no!="0")
		{
			no=getno(testcase[i].len,testcase[i].no,testcase[i].k);
			printf("%d",no);
			output1=method1(no);
			output2=method2(no);
		}
		else
		{
			output1=output2=0;
		}
		printf("\ntestcase %d method1",i);
		checkresult(testcase[i].result,output1);
		printf("\ntestcase %d method2",i);
		checkresult(testcase[i].result,output2);
	}
}


int getno(int len,char *no,int k)
{
	int a=0,s=k;
	int h=1,x;
	for(x=0;x<(len*k)-1;x++)
		h=h*10;
	while(s!=0)
	{
		int j=0;
		while(no[j]!='\0')
		{
			if(no[j]=='-')
			{
				j++;
				h/=10;
			}
			else
			{
				a=a+(no[j]-48)*h;
				printf("%d",a);
				j++;
				h=h/10;
			}
		}
		s--;
	}
	return a;
}


int method1(int no)
{
	int lastno;
	int temp=no;
	while(no>0)
	{
		lastno=temp%10;
		temp=temp/10;
		temp=temp-lastno;
		no=no/10;
	}
	if(temp==0)
		return 0;
	else
		return 1;
}


int method2(int a)
{
	int *b,n;
	b=(int*)malloc(sizeof(int)*2);
	b=seperate(a);
	n=diff(b);
	if(n%10<=9)
	{
		if(n==11||n==0)
			return 0;
		else
			return 1;
	}
	else
		return method2(n);
}

int* seperate(int a)
{
	int *b;
	int n=a,k=0,r,j=0;
	b=(int*)malloc(sizeof(int)*2);
	b[0]=0;
	b[1]=0;
	while(n>0)
	{
		r=n%10;
		b[j]+=r;
		n/=10;
		k++;
		if(k%2==0)
			j=0;
		else
			j=1;
	}
	return b;
}

int diff(int *b)
{
	if(b[0]>b[1])
		return b[0]-b[1];
	if(b[0]<=b[1])
		return b[1]-b[0];
}

void checkresult(int result,int output)
{
		if(result==output)
			printf("sucess\n");
		else
			printf("Fail\n");
}