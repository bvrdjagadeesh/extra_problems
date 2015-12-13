#include<stdio.h>
#include<stdlib.h>
struct decimal
{
	int decimal;
	int octal;
}
testcase[9]=
{
	{ 100, 144},
	{ 8,10},
	{9,11},
	{64,100},
	{96,140},
	{32,40},
	{424,650},
	{36,44},
	{1255,2347}
};

void start();
int dectooct(int);
void checkresult(int,int);


void main()
{
	start();
	getch();
}

void start()
{
	int i,octal;
	for(i=0;i<9;i++)
	{
		octal=dectooct(i);
		checkresult(i,octal);
	}
}


int dectooct(int i)
{
	int decimal=testcase[i].decimal,octal=0,remainder, b = 1;
	while (decimal>0)
	{
		remainder = decimal % 8;
		octal = octal + remainder*b;
		decimal = decimal / 8;
		b = b * 10;
	}
	return octal;
}


void checkresult(int i,int octal)
{
	if(octal==testcase[i].octal)
		printf("sucess\n");
	else
		printf("Fail\n");
}

