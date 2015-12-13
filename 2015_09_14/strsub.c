#include<stdio.h>
#include<stdlib.h>
struct string
{
	char *s;
}
testcases[1]={
	"welcome"
};

void start();

void main()
{
	start();
}

void start()
{
	  char  *sub;
   int position, length,c= 0;
   printf("Enter the position and length of substring\n");
   scanf("%d%d", &position, &length);
   sub=(char*)malloc(sizeof(char)*length);
   while (c < length) {
      sub[c]=testcases[0].s[position+c];
      c++;
   }
   sub[c] = '\0';
 
   printf("Required substring is %s", sub);
   
 }