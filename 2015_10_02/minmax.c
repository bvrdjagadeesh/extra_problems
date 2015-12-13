struct array
{
	int a[4];
	int min;
	int max;
}
testcases[1]=
{
	{{23,1,5,3},1,99}
};

void start();
int findmin(int);
int findmax(int);

void main()
{
	start();
}

void start()
{
	int i,min,max;	
	for(i=0;i<1;i++)
	{
		min=findmin(i);
		max=findmax(i);
	}
	printf("%d",min);
	printf("%d",max);
}

int findmin(int i)
{
	int min=testcases[i].a[0],j;
	for(j=1;j<4;j++)
	{
		if(testcases[i].a[j]<min)
			min=testcases[i].a[j];
	}
	return min;
}

int findmax(int i)
{
	int max=testcases[i].a[0],j;
	for(j=1;j<5;j++)
	{
		if(testcases[i].a[j]>max)
			max=testcases[i].a[j];
	}
	return max;
}