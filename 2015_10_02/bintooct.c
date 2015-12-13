 #include<stdio.h>
#include<stdlib.h>
 struct binary
{
	int len;
	char *binary;
	int octal;
};
typedef struct binary array;

array* intializetestcase()
{
	array *testcase;
	testcase=(array *)malloc(sizeof(array)*6);
	testcase[0].len=4;
	testcase[0].binary=(char*)malloc(sizeof(char)*testcase[0].len);
	testcase[0].binary="1001";
	testcase[0].octal=11;
	testcase[1].len=5;
	testcase[1].binary=(char*)malloc(sizeof(char)*testcase[1].len);
	testcase[1].binary="10010";
	testcase[1].octal=22;
	testcase[2].len=1;
	testcase[2].binary=(char*)malloc(sizeof(char)*testcase[2].len);
	testcase[2].binary="1";
	testcase[2].octal=1;
	testcase[3].len=3;
	testcase[3].binary=(char*)malloc(sizeof(char)*testcase[3].len);
	testcase[3].binary="111";
	testcase[3].octal=7;
	testcase[4].len=2;
	testcase[4].binary=(char*)malloc(sizeof(char)*testcase[4].len);
	testcase[4].binary="11";
	testcase[4].octal=3;
	testcase[5].len=1;
	testcase[5].binary=(char*)malloc(sizeof(char)*testcase[5].len);
	testcase[5].binary="0";
	testcase[5].octal=0;
	testcase[6].len=7;
	testcase[6].binary=(char*)malloc(sizeof(char)*testcase[6].len);
	testcase[6].binary="1010101";
	testcase[6].octal=125;
	return testcase;
}
 
 void start();
 int getno(char*);
 int method2(int);
 int method1(int,int);
 int getoct(int);
 void checkresult(int,int);
 
 void main()
 {
	start();
}

void start()
{
	int i,no,output1,output2;
	array *testcase=intializetestcase();
	for(i=0;i<7;i++)
	{
		no=getno(testcase[i].binary);
		output1=method1(no,testcase[i].len);
		output2=method2(no);
		printf("%d\t",output1);
		printf("%d\t",output2);
		printf("testcase %d method1:",i);
		checkresult(output1,testcase[i].octal);
		printf("testcase %d method2:",i);
		checkresult(output2,testcase[i].octal);
	}
}


void checkresult(int output,int octal)
{
	if(output==octal)
		printf("sucess\n");
	else
		printf("Fail\n");
}


int method1(int binary,int len)
{
	int i,no=0,k=1,r,j=0,octal=0,h=1;
	for(i=0;i<len;i++)
	{
		if(j==3)
		{
			k=1;
			octal=octal*h+getoct(no);
			h*=10;
			no=0;
			j=1;
		}
		r=binary%10;
		if(r==0)
		{
			
			k*=10;;
		}
		else
		{
			no=no+r*k;
			k=k*10;
		}
		binary/=10;
		j++;
	}
	if(j>0||j<3)
		octal=octal*h+getoct(no);
	return octal;
}

int getno(char *a)
{
	int i,b=0,k=10;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='1')
		{
			b=b*k+(a[i]-'0');
		}
		else
		{
			b=b*10;
		}
	}
	return b;
}



int method2(int binary) 
{
    int octal=0,decimal=0,b=1,remainder,i;
    while(binary>0)
    {
		remainder=binary%10;
		decimal=decimal+remainder*b;
        binary/=10;
		b=b*2;
    }
    b=1;
    while (decimal>0)
	{
		remainder = decimal % 8;
		octal = octal + remainder*b;
		decimal = decimal / 8;
		b = b * 10;
	}
    return octal;
}

int getoct(int no)
{
	int remainder,b=1,oct=0;
	 while(no>0)
    {
		remainder=no%10;
		oct=oct+remainder*b;
        no/=10;
		b=b*2;
    }
	return oct;
}