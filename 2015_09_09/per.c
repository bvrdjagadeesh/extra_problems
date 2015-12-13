struct array{
	int no;
	int index;
}
testcases[2]={
	{213,2},
	{12,1}
};

void start();
void getarray(int);
void getpermutations(int*,int,int,int,int);
void swap(int*,int*);
void printArray(int*,int,int,int);
void sort(int *,int,int);
int fact(int);
void checkresult(int*,int,int);

int main()
{
	start();
}

void start()
{
	int i;
	for(i=0;i<2;i++)
	{
		getarray(i);
	}
}


void getpermutations(int *array,int i,int length,int d,int g)
 { 
	int j=i;
	if (length==i){
		printArray(array,length,d,g);
		return;
	}
	for ( j= i; j < length; j++) 
	{ 
		swap(&array[i],&array[j]);
		getpermutations(array,i+1,length,d,g);
		swap(&array[i],&array[j]);
	}
}


void getarray(int i)
{
	int t=testcases[i].no,r,j=0,d;
	int a[4];
	while(t!=0)
	{
		r=t%10;
		a[j]=r;
		t=t/10;
		j++;
	}
	d=fact(j);
	getpermutations(a,0,j,d,i);
}

int fact(int j)
{
	if(j==1)
		return j;
	else
		return j*fact(j-1);
}

void swap(int *x,int *y){
		int t=*x;
		*x=*y;
		*y=t;
}

void printArray(int *array,int l,int d,int g)
{
	int x,j=0,sum=0,res[6],i;
	for(x=0;x<l;x++)
		sum=sum*10+array[x];
	res[j++]=sum;
	sort(res,j,g);
	
}

void sort(int *array,int n,int g)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(array[i]>array[j])
			{
				int t=array[i];
				array[i]=array[j];
				array[j]=t;
			}
		}
	}
	checkresult(array,g,n);

}

void checkresult(int *array,int i,int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(array[j]==testcases[i].no)
			printf("sucess\n");
	}
}