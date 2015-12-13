struct string
{
	char *a;
	char *b;
}
testcases[2]={
	{"welcome","welcome"},
	{"well","wel"}
};

void start();
void main()
{
	start();
}

void start()
{
	for(i=0;i<2;i++)
	{
		int c = 0;
		while (testcases[i].a[c]==testcases[i].b[c]) 
		{
			if (testcases[i].a[c]=='\0'||testcases[i].b[c] == '\0')
				break;
			c++;
		}
		if (testcases[i].a[c]=='\0'&&testcases[i].b[c] == '\0')
			printf("equal");
		else
			printf("notequal");
	}
		
}