#include<stdio.h>
#include<stdlib.h>
struct array
{
	int a[4];
	int c[3];
}
testcases[1]=
{
	{{4,6,3,9},{4,3,1}},
	{{5,2,9,7},{7,5,2}}
};

void start();
int* cmp(int,int,int*);
int* low(int,int*,int,int);
void check(int*,int);
void main()
{
	start();
}

void start()
{
	int h;
	for(h=0;h<2;h++)
	{
		int i,j;
		int *b;
		b=(int*)malloc(sizeof(int)*3);
		b[0]=testcases[h].a[0];
		b[1]=testcases[h].a[1];
		b[2]=b[0]-b[1];
		for(i=0;i<3;i++)
		{
			for(j=i+1;j<4;j++)
			{
				b=cmp(i,j,b);
			}
		}
		check(b,h);
	}
}

int* cmp(int i,int j,int *b)
{
	int m=testcases[0].a[i]-testcases[0].a[j],n;
	int x=b[2],q=0,w=0,e=0,r=0;
	if(m<0&&x<0)
	{
		n=(0-x)>(0-m)?m:x;
		q++;
	}
	else if(m<0&&x>0){
		w++;
		n=x>(0-m)?m:x;

	}
	else if(x<0&&m>0){
		e++;
		n=(0-x)>m?m:x;

	}
	else if(x>0&&m>0){
		r++;
		n=x>m?m:x;

	}
	return low(n,b,i,j);
}

int* low(int n,int *b,int i,int j)
{
	if(n!=b[2])
	{
		b[0]=testcases[0].a[i];
		b[1]=testcases[0].a[j];
		b[2]=n;
		return b;
	}
	else
		return b;
}

void check(int *b,int i)
{
	int j,c=0;
	for(j=0;j<3;j++)
	{
		if(testcases[i].c[j]==b[j]
			c++;
	}
	if(d==3)
		printf("sucess");
	else
		printf("fail");