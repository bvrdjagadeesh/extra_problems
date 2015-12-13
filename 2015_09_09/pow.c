
struct variables{
	unsigned int x,y,z,output;
}
testcases[6]={
	{1,1,1,0},
	{2,1,3,2},
	{3,6,9,0},
	{2,0,3,1},
	{3,4,0,4},
	{0,2,4,0}
};

void start();
void calculate(int);
int power(int,int);
void checkresult(int,int);

int main(){
	start();
}

void start()
{	
	int i;
	for(i=0;i<6;i++)
	{
		calculate(i);
	}
}

void calculate(int i)
{
	int product;
	product=power(testcases[i].x,testcases[i].y);
	if(testcases[i].z!=0)
		checkresult(i,product%testcases[i].z);
	else
		printf("Invalid\n");
}


void checkresult(int i,int result)
{
	if(result==testcases[i].output)
		printf("Success\n");
	else
		printf("Fail\n");
}


	
int power(int x,int y){
	if(y==0)
		return 1;
	else if(y==1)
		return x;
	return x*power(x,y-1);
}