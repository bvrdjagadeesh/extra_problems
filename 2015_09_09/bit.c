
struct variables{
	int x,y,output;
}
testcases[6]={
	{4,5,20},
	{2,3,6},
	{1,4,4},
	{1,0,0},
	{0,0,0},
	{0,1,0}
};

void start();
void shift(int);
int product(int,int);
void checkresult(int,int);

int main()
{
	start();
}

void start()
{
	int i;
	for(i=0;i<6;i++)
		shift(i);
}

void shift(int i)
{
	int z=0;
	while(testcases[i].y!=0)
	{
		if (testcases[i].y&01){
			z=product(z,testcases[i].x);
		}
        testcases[i].x<<=1;
        testcases[i].y>>=1; 
	}
	checkresult(i,z);
}


int product(int x, int y)
{
    if (y == 0)
        return x;
    else
        return product( x ^ y, (x & y) << 1);
}


void checkresult(int i,int z)
{
	if(testcases[i].output==z)
		printf("Success\n");
	else
		printf("Fail\n");
}