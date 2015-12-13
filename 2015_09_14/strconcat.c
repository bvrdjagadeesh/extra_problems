struct string
{
	char *s1;
	char *s2;
}
testcases[1]={
	{"Ganugula","Jagadeesh"}
};

void start();

void main()
{
	start();
}

void start()
{
	int i,j,k=1;
	 for(i=0; testcases[0].s1[i]!='\0'; ++i); 
		for(j=0; testcases[0].s2[j]!='\0'; ++j, ++i)
		{
			testcases[0].s1[i]=testcases[0].s2[j];
		}
	testcases[0].s1[i]='\0';
	printf("%s",testcases[0].s1);
}