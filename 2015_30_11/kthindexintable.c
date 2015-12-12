#include<stdio.h>
struct testcases{

	int n1;
	int n2;
	int r;
	int res;
}
testcase[8] = {
	{ 4, 6, 7, 20 },
	{ 6, 2, 5, 10 },
	{ 5, 8, 1, 5 },
	{ 7, 5, 7, 21 },
	{ 5, 7, 7, 21 },
	{ 3, 3, 3, 9 },
	{ 3, 6, 5, 15 }
};
void start(int);
int getres(int);
int gcd(int, int);
void checkresult(int, int);
void main()
{
	for (int i = 0; i < 7; i++)
		start(i);
	getchar();
}

void start(int i)
{
	int r = getres(i);
	checkresult(r, i);
}

void checkresult(int r, int i)
{
	if (r == testcase[i].res)
		printf("\nPass");
	else
		printf("\nFail");
}
int getres(int i)
{
	int n1 = testcase[i].n1;
	int n2 = testcase[i].n2;
	int r = testcase[i].r;
	int k, flag, lcm, num, x, y;
	if (r == 1)
		return (n1 < n2 ? n1 : n2);
	else if (n1%n2 == 0)
		return n2*r;
	else if (n2%n1 == 0)
		return n1*r;
	else
	{
		lcm = n1*n2 / gcd(n1, n2);
		num = lcm / n1 + lcm / n2 - 1;
		x = y = lcm * (r / num);
		r = r % num;

		if (x == 0)
		{
			x = n1;
			y = n2;
		}
		else
		{
			r++;
		}
		for (k = 0; k < r; k++)
		{
			if (x < y)
			{
				x = x + n1;
				flag = 1;
			}
			else if (x > y)
			{
				y = y + n2;
				flag = 0;

			}
			else
			{
				y = y + n2;
				x = x + n1;
			}
		}
		if (flag)
			return x - n1;
		else
			return y - n2;
	}
}
int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			return gcd(a - b, b);
		else
			return gcd(a, b - a);
	}
	return a;
}