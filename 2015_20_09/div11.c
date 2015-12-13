#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct string
{
	int len;
	char *no;
	int result;//0 if divisible by 11
};
typedef struct string array;

array* intializetestcase()
{
	array *testcase;
	testcase=(array *)malloc(8*sizeof(array));
	testcase[0].len=7;
	testcase[0].no=(char *)malloc(sizeof(char)*testcase[0].len);
	testcase[0].no="7110631";
	testcase[0].result=0;
	testcase[1].len=6;
	testcase[1].no=(char *)malloc(sizeof(char)*testcase[1].len);
	testcase[1].no="291731";
	testcase[1].result=0;
	testcase[2].len=4;
	testcase[2].no=(char *)malloc(sizeof(char)*testcase[2].len);
	testcase[2].no="2035";
	testcase[2].result=0;
	testcase[3].len=9;
	testcase[3].no=(char *)malloc(sizeof(char)*testcase[3].len);
	testcase[3].no="278589465";
	testcase[3].result=0;
	testcase[4].len=2;
	testcase[4].no=(char *)malloc(sizeof(char)*testcase[4].len);
	testcase[4].no="11";
	testcase[4].result=0;
	testcase[5].len=1;
	testcase[5].no=(char *)malloc(sizeof(char)*testcase[5].len);
	testcase[5].no="0";
	testcase[5].result=0;
	testcase[6].len=3;
	testcase[6].no=(char *)malloc(sizeof(char)*testcase[6].len);
	testcase[6].no="-33";
	testcase[6].result=0;
	testcase[7].len=7;
	testcase[7].no=(char *)malloc(sizeof(char)*testcase[7].len);
	testcase[7].no="-291731";
	testcase[7].result=0;
	testcase[8].len=6;
	testcase[8].no=(char *)malloc(sizeof(char)*testcase[8].len);
	testcase[8].no="-60104";
	testcase[8].result=0;
	return testcase;
}


void start();
int getno(int,char*);
int method2(int);
int* seperate(int);
int diff(int*);
int method1(int);
void checkresult(int,int);

void main()
{
	start();
}

void start()
{
	int i;
	int no,output1,output2;
	array *testcase=intializetestcase();
	for(i=0;i<9;i++)
	{
		no=getno(testcase[i].len,testcase[i].no);
		output1=method1(no);
		output2=method2(no);
		printf("\ntestcase %d method1",i);
		checkresult(testcase[i].result,output1);
		printf("\ntestcase %d method2",i);
		checkresult(testcase[i].result,output2);
	}
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



int getno(int len,char *no)
{
	int a=0,i,j=0;
	int x;
	int k=1;
	for(i=0;i<len-1;i++)
		k=k*10;
	while(no[j]!='\0')
	{
		if(no[j]=='-')
		{
			j++;
			k/=10;
		}
		else
		{
			a=a+(no[j]-48)*k;
			j++;
			k/=10;
		}
	}
	return a;
}

int method2(int no)
{
	int *b,n;
	b=(int*)malloc(sizeof(int)*2);
	b=seperate(no);
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