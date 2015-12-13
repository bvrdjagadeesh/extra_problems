#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct string
{
	int len1;
	int len2;
	char *str1;
	char *str2;
	char *result;
};
typedef struct string str;
str* intializetestcase()
{
	str *testcase;
	testcase=(str*)malloc(6*sizeof(str));
	testcase[0].len1=1;
	testcase[0].len2=2;
	testcase[0].str1=(char*)malloc(sizeof(char)*testcase[0].len1);
	testcase[0].str1="1";
	testcase[0].str2=(char*)malloc(sizeof(char)*testcase[0].len2);
	testcase[0].str2="12";
	testcase[0].result="13";
	testcase[1].len1=2;
	testcase[1].len2=2;
	testcase[1].str1=(char*)malloc(sizeof(char)*testcase[1].len1);
	testcase[1].str1="99";
	testcase[1].str2=(char*)malloc(sizeof(char)*testcase[1].len2);	
	testcase[1].str2="99";
	testcase[1].result="198";
	testcase[2].len1=3;
	testcase[2].len2=2;
	testcase[2].str1=(char*)malloc(sizeof(char)*testcase[2].len1);
	testcase[2].str1="101";
	testcase[2].str2=(char*)malloc(sizeof(char)*testcase[2].len2);	
	testcase[2].str2="98";
	testcase[2].result="199";	
	testcase[3].len1=2;
	testcase[3].len2=3;
	testcase[3].str1=(char*)malloc(sizeof(char)*testcase[3].len1);
	testcase[3].str1="11";
	testcase[3].str2=(char*)malloc(sizeof(char)*testcase[3].len2);	
	testcase[3].str2="111";
	testcase[3].result="122";
	testcase[4].len1=3;
	testcase[4].len2=3;
	testcase[4].str1=(char*)malloc(sizeof(char)*testcase[4].len1);
	testcase[4].str1="261";
	testcase[4].str2=(char*)malloc(sizeof(char)*testcase[4].len2);	
	testcase[4].str2="121";
	testcase[4].result="382";
	testcase[5].len1=4;
	testcase[5].len2=3;
	testcase[5].str1=(char*)malloc(sizeof(char)*testcase[5].len1);
	testcase[5].str1="2611";
	testcase[5].str2=(char*)malloc(sizeof(char)*testcase[5].len2);	
	testcase[5].str2="121";
	testcase[5].result="2732";
	return testcase;
}

void start();
int getlen(int,int);
char* strcat(char*,char*);
void addstr(int,int,char*,char*,char*);
void strcm(char*,char*);


void main()
{
	start();
}

void start()
{
	str *testcase=intializetestcase();
	int i;
	for(i=0;i<5;i++)
	{
		addstr(testcase[i].len1,testcase[i].len2,testcase[i].str1,testcase[i].str2,testcase[i].result);
	}
}


char* strcat(char* s1,char* s2)
{
	int i,j;
	for(i=0; s1[i]!='\0'; ++i); 
		for(j=0; j<2; ++j, ++i)
		{
			s1[i]=s2[j];
		}
	s1[i]='\0';
	return s1;
}


int getlen(int len1,int len2)
{
	if(len1==len2)
		return len1;
	else if(len1>len2)
		return len1;
	else 
		return len2;
}

void addstr(int len1,int len2,char *a,char *b,char *result)
{
	char *c,*res;
	char w,o=0;
	int len=getlen(len1,len2);
	int s=len-1;
	int i=len1-1;
	int j=len2-1;
	c=(char*)malloc(sizeof(char)*len);
	while(i>=0&&j>=0)
	{
		w=(a[i]+b[j])+o;
		if(w>='j')
		{
			o=1;
			c[s]=w-58;
		}
		else
		{
			c[s]=w-48;
		}
		s--;
		i--;
		j--;
	}
	while(i>=0)
	{
		if(o==1)
		{
			w=a[i]+o;
			if(w>='j')
			{
				o=1;
				c[s]=w-58;
			}
			else
			{
				c[s]=w;
			}
		}
		else
		{
			c[s]=a[i];
		}
		s--;
		i--;
	}
	while(j>=0)
	{
		if(o==1)
		{
			w=b[j]+o;
			if(w>='j')
			{
				o=1;
				c[s]=w-58;
			}
			else
			{
				c[s]=w;
			}
		}
		else
		{
			c[s]=b[j];
		}
		s--;
		j--;
	}
	if(o!=0)
	{
		res=(char*)malloc(sizeof(char)*4);
		res="1";
		res=strcat(res,c);
		strcm(res,result);
	}
	else
	{
			strcm(c,result);
	}
}

void strcm(char *a,char *b)
{
	int c = 0;
		while (a[c]==b[c]) 
		{
			if (a[c]=='\0'||b[c] == '\0')
				break;
			c++;
		}
		if (a[c]=='\0'&&b[c] == '\0')
			printf("sucess\n");
		else
			printf("Fail\n");
}