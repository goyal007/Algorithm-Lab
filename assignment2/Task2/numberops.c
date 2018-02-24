#include<stdio.h>
#include"base.h"
int createnumber(char* ch,int l1,int b,char *a)// b==base
{
	int i=0,pil=0,k=1;
	for(i=0;i<l1;i++)
	{
		pil=pil+((lookup(a,ch[l1-1-i]))*k);//convert to base 10
		k=k*b;
	}
	return pil;
}
void convert(int re,int a,int b,char *ch)// ch is array of all character i.e 0,1....A,B,C,D,E
{
	char result[100];
	int i=0,d,j;
	if(a>b)
	{
		while(re!=0)
		{
			result[i]=ch[re%a];
			i++;
			re=re/a;
		}
		//result[i]='\0';
		for(j=i-1;j>=0;j--)
		{
			printf("%c",result[j]);
		}
		printf("(%d)\n",a);
	}
	else
	{
		while(re!=0)
		{
			result[i]=ch[re%b];
			i++;
			re=re/b;
		}
		//result[i]='\0';
		for(j=i-1;j>=0;j--)
		{
			printf("%c",result[j]);
		}
		printf("(%d)\n",b);
	}
}
void subtract(int b1,int b2,int a,int b,char *ch)
{
	int re;
	re=b1-b2;
	convert(re,a,b,ch);
}
void add(int b1,int b2,int a,int b,char *ch)
{
	int re;
	re=b1+b2;
	convert(re,a,b,ch);
}
