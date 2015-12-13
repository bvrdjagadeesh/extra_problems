#include<stdib.h>
struct string{
	char *String;
	char *output;
}
testcases[3]={
	{" jagadeesh ","jagadeesh"},
	{"  cse","cse"},
	{"cse ","cse"}
};

void start();
void trim(int);
void check(char*,int);


void main()
{
	start();
}

void start()
{
	for(h=0;h<3;h++)
	{
		trim(h);
	}
}

void trim(int h)
{
	int i=0,j=0;
	char c;
	char *s;
	s=(char*)malloc(sizeof(char)*strlen(testcases[h].String));
	while(testcases[h].String[i])
	{
	   c=testcases[h].String[i];
	   if(c!=' ')
	   {
		 s[j]=c;
		 j++;
	   }
	   i++;
	}
	check(s,h);

}

void check(char *s,int i)
{
	
	int j,c=0;
	for(j=0;j<strlen(testcases[i].output);j++){
		if(testcases[i].output[j]!=s[j]){
			c++;
		}
	}
	if(c==0){
		printf("Success\n");
	}
	else
		printf("Fail\n");
}
	