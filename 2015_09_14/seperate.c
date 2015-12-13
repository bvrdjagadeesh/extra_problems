#include<stdlib.h>
#include<stdio.h>
typedef char* string;
struct arrray
{
	char *str;
	string *res;
}
testcase[2]=
{
	{"please save trees",{"please","save","trees"}},
	{"2131 14 14",{"2131","14","14"}}
};

void start();
char* append(char*,char);
void main()
{
	start();
}

void start()
{
	for(h=0;h<2;h++)
	{
		seperate(h);
	}
}
void seperate(int h)
{
	int counter=0,j=0,i=0;
	string *result = (string *)malloc(sizeof(string));
	result[i] = (string)malloc(sizeof(char));
	while (testcase[h].str[counter] == ' ')
		counter++;
	while (testcase[h].str[counter] != '\0'){
		if (testcase[h].str[counter] != ' '){
			result[i] = (string)realloc(result[i],(j+1)*sizeof(char));
			result[i][j] =testcase[h].str[counter];
			counter++;
			j++;
		}
		else
		{
			result[i][j] = '\0';
			counter++;
			j = 0;
			i++;
			result[i] = (string)malloc(sizeof(char));
		}
	}
	result[i][j] = '\0';
	check(result,h);
}		
			
void check(string *result,int h){
	int i,j,c=0;
	int length=(sizeof(result)/sizeof(testcase[h].res[0]));
	for (i= 0;j<length;i++){
		while (result[i][j] !='\0'&&testcase[h].res[i][j]=='\0'){
			if (result[i][j] !=testcase[h].res[i][j])
				c++;
			}
	}
	if(c!=0)
		printf("sucess");
	else
		printf("fail");
}