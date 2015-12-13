struct studentdetails{
	char *stdname;
	char *stddept;
	char sec;
	int stdid;
}
testcases[2]={
	{"Jagadeesh","cse",'A',28765},
	{"anil","cse",'A',28766}
};

void print(int);

void main()
{
	int i;
	printf("Enter Studentid to print details");
	scanf("%d",&i);
	print(i);
}

void print(int i)
{
	int j,c=0;
	for(j=0;j<1;j++)
	{
		if(i==testcases[j].stdid)
		{
			c++;
			printf("Studentname:%s\nDepartment:%s\nSection:%c\nStudentid%d",testcases[j].stdname,testcases[j].stddept,testcases[j].sec,testcases[j].stdid);
		}
	}
	if(c==0)
		printf("Invalid StudentID");
}