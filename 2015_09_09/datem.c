struct date{
	char *str;
	char *result;
}testcases[2]={

	{"22/10/1995","twentytwoofoctobernineteennintyfive"},
	{"24/11/1986","twentyfourofnovembernineteeneightysix"}

};

void start(int);
char* strconcat(char*,char*);
void getdate(int,int,int,int);
void checkresult(char*,int);
int main()
{
	int i;
	for(i=0;i<2;i++)
		start(i);
}

void start(int i)
{
	int len=strlen(testcases[0].str);
	int a=0,b=0,count=0,k=1,n=1,v=1,j,c=0;
	for(j=len-1;j>=0;j--)
	{
		if(testcases[i].str[j]!='/'&&count==0)
		{
			a+=(testcases[i].str[j]-48)*k;
			k=k*10;
		}
		if(testcases[i].str[j]=='/')
		{
			count++;
		}
		if(testcases[i].str[j]!='/'&&count==1)
		{
			b+=(testcases[i].str[j]-48)*n;
			n=n*10;
		}
		if(testcases[i].str[j]!='/'&&count==2){
			c+=(testcases[i].str[j]-48)*v;
			v=v*10;
		}
	}
	getdate(c,b,a,i);
}

char* strconcat(char *s1,char *s2)
{
	int i,j,k=1;
	 for(i=0; s1[i]!='\0'; ++i);  /* i contains length of string s1. */
    for(j=0; s2[j]!='\0'; ++j, ++i)
    {
        s1[i]=s2[j];
    }
    s1[i]='\0';
	return s1;
}

void getdate(int a,int b,int c,int i)
{
	int t=a,r,j=0,e=0,u=0;
	int x[2],q[2],k[2];
		char *res;
		char m[12][15]={"ofjanuary","offebravary","ofmarch","ofapril","ofmay","ofjune","ofofjuly","ofaugust","ofseptember","ofoctober","ofnovember","ofdecember"};
	char d[10][7]={"one","two","three","four","five","six","seven","eight","nine"};
	char p[10][10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	char w[10][10]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninty"};
	while(t!=0)
	{
		r=t%10;
		x[j]=r;
		t=t/10;
		j++;
	}
	if(j==1)
		res=d[a-1];
	else if(x[0]!=1)
	{
		res=w[x[1]-2];
		res=strconcat(res,d[x[0]-1]);
	}
	else if(x[1]==1)
			res=p[x[1]-1];
	res=strconcat(res,m[b-1]);
	t=c,j=0;
	while(t!=0)
	{
		r=t%10;
		if(j!=2){
			
			k[e]=r;
			e++;
			j++;
		}
		else
		{
			q[u]=r;
			u++;
		}
		t=t/10;
	}
	if(q[1]==1)
		res=strconcat(res,p[q[0]]);
	res=strconcat(res,w[k[1]-2]);
	res=strconcat(res,d[k[0]-1]);
	checkresult(res,i);

}

void checkresult(char *res,int i)
{
	int j,c=0;
	for(j=0;j<strlen(testcases[i].result);j++){
		if(testcases[i].result[j]!=res[j]){
			c++;
		}
	}
	if(c==0){
		printf("Success\n");
	}
	else
		printf("Fail\n");
}