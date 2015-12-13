#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE* f;
	char *filename="lastnlines.c";
	int num,count=0;
	char ch;
	printf("enter nof lines:");
	scanf("%d", &num);
	f = fopen(filename, "r");
	while ((ch = fgetc(f)) != EOF)
	{
		if (ch == '\n')
			count++;
	}
	int i = 0;
	count = count - num;
	rewind(f);
	while (i < count)
	{
		ch = fgetc(f);
		if (ch == '\n')
			i++;
	}
	while ((ch = fgetc(f)) != EOF)
		fprintf(stdout, "%c", ch);
	_getch();
}