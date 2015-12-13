struct string
{
	char *s;
}
testcases[1]={
	"jagadeesh"
};

void start();
void main()
{
	start();
}

void start()
{
	int i;
	for(i=0; testcases[0].s[i]!='\0'; ++i);
	printf("%d",i);
}