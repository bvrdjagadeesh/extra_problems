#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct array
{
	int len;
	char *no;
	int k;
	int result;//0 if divisible by 3
};
typedef struct array number;
number* intializetestcase()
{
	number *testcase;
	testcase=(number *)malloc(8*sizeof(number));
	testcase[0].len=2;
	testcase[0].no=(char *)malloc(sizeof(char)*testcase[0].len);
	testcase[0].no="12";
	testcase[0].k=2;
	testcase[0].result=0;
	testcase[1].len=3;
	testcase[1].no=(char*)malloc(sizeof(char)*testcase[1].len);
	testcase[1].no="243";
	testcase[1].k=1;
	testcase[1].result=0;
	testcase[2].len=7;
	testcase[2].no=(char*)malloc(sizeof(char)*testcase[2].len);	
	testcase[2].no="3961428";
	testcase[2].k=1;
	testcase[2].result=0;
	testcase[3].len=3;
	testcase[3].no=(char*)malloc(sizeof(char)*testcase[3].len);
	testcase[3].no="736";
	testcase[3].k=0;
	testcase[3].result=0;
	testcase[4].len=1;
	testcase[4].no=(char*)malloc(sizeof(char)*testcase[4].len);
	testcase[4].no="9";
	testcase[4].k=1;
	testcase[4].result=0;
	testcase[5].len=3;
	testcase[5].no=(char*)malloc(sizeof(char)*testcase[5].len);
	testcase[5].no="-12";
	testcase[5].k=2;
	testcase[5].result=0;
	testcase[6].len=4;
	testcase[6].no=(char*)malloc(sizeof(char)*testcase[6].len);	
	testcase[6].no="-243";
	testcase[6].k=2;
	testcase[6].result=0;
	testcase[7].len=1;
	testcase[7].no=(char*)malloc(sizeof(char)*testcase[7].len);	
	testcase[7].no="0";
	testcase[7].k=3;
	testcase[7].result=0;
	testcase[8].len=4;
	testcase[8].no=(char*)malloc(sizeof(char)*testcase[8].len);	
	testcase[8].no="-736";
	testcase[8].k=0;
	testcase[8].result=0;
	return testcase;
}


void start();
int method1(int);
int getno(int,char*,int);
int method2(char*,int);
int method3(int);
void checkresult(int,int);


void main()
{
	start();
}

void start()
{
	number *testcase=intializetestcase();
	int i,no,output1,output2,output3,result;
	for(i=0;i<9;i++)
	{
		result=testcase[i].result;
		if(testcase[i].k!=0||testcase[i].no=="0")
		{
			output2=method2(testcase[i].no,testcase[i].len);   //before forming number
			no=getno(testcase[i].len,testcase[i].no,testcase[i].k);   //forming number with k value
			//after forming  number
			printf("%d",no);
			output1=method1(no);
			output3=method3(no);
		}
		else
		{
			output1=output2=output3=0;
		}
		printf("\ntestcase %d method1:",i);
		checkresult(output1,result);
		printf("\ntestcase %d method2:",i);
		checkresult(output2,result);
		printf("\ntestcase %d method3:",i);
		checkresult(output3,result);
	}
}

int method3(int a)
{
	int countodd=0,counteven=0;
	int n=a,r;
	while(n>0)
	{
		r=n%10;
		if(r==1||r==4||r==7)
			countodd++;
		else if(r==2||r==5||r==8)
			counteven++;
		n/=10;
	}
	if(counteven==countodd)
		return 0;
	else
		return 1;
}

void checkresult(int output,int result)
{
	if(output==result)
		printf("sucess\n");
	else
		printf("Fail\n");
}

int method1(int a)
{
	int n,r;
	element:
		n=a;
		a=0;
		while(n>0)
		{
			r=n%10;
			a+=r;
			n/=10;
		}
		if(a/10==0)
			goto next;
		goto element;
	next:
		if(a==3||a==6||a==9||a==0)
			   return 0;
		else
			return 1;
}

int method2(char *no,int len)
{
	int counteven=0,countodd=0,i;
	for(i=0;i<len;i++)
	{
		if(no[i]=='1'||no[i]=='4'||no[i]=='7')
			countodd++;
		else	if(no[i]=='2'||no[i]=='5'||no[i]=='8')
			counteven++;
	}
	if(countodd==counteven)
		return 0;
	else
		return 1;
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
				j++;
				h=h/10;
			}
		}
		s--;
	}
	return a;
}