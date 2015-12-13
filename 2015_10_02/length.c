#include<stdio.h>
struct array
{
	int *a;
	int result;//length of array
}testcase[6] = {
	{ (int[6]){1,2,3,2,0,0},6 },
	{ (int[10]){3,4,6,8,9,2,0,0,0,0},10 },
	{ (int[12]){1,2,5,7,8,9,1,0,0,0,0,0},12 },
	{ (int[14]){12,34,56,66,69,88,96,21,0,0,0,0,0,0},14 },
	{ (int[20]){1,2,4,6,8,12,32,64,77,88,55,0,0,0,0,0,0,0,0,0},20 },
	{ (int[16]){12,34,56,78,79,81,83,89,45,0,0,0,0,0,0,0},16 }
};


int search(int, int,int);
int method1(int);
int method2(int);
void start();
void checkresult(int, int);


void main()
{
	start();
	getch();
}

void start()
{
	int  x, output1, output2;
	for (x = 0; x<6; x++)
	{
		output1 = method1(x);
		output2 = method2(x);
		printf("\ntestcase %d method1:", x);
		checkresult(testcase[x].result, output1);
		printf("\ntestcase %d method2:", x);
		checkresult(testcase[x].result, output2);
	}

}

void checkresult(int result, int output)
{
	if (result == output)
		printf("sucess\n");
	else
		printf("Fail\n");
}

int method1(int x)
{
	int i,n,j = 1;
	for (i = 0; testcase[x].a[j]>0;)
	{
		j *= 2;
		i++;
	}
	n = search(i, j, x);
	return (n * 2);
}


int search(int i, int j,int x)
{
	int m= (i + j) / 2;
	if (i <= j)
	{
		if (testcase[x].a[m] > 0)
			return search(m+1,j,x);
		else
			return search(i, m-1,x);
	}
	else
		return m;
}

int method2(int i)
{
	int j = 1,x;
	for (x = 0; testcase[i].a[x] > 0;x++)
	{
		if (testcase[i].a[x] < testcase[i].a[x + 1])
		{
			j++;
		}
	}
	return j*2;
}