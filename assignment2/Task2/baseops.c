#include<stdio.h>
int initializebase(FILE *p,char *a)
{
	int c=0;
	char ch=fgetc(p);
	while(ch!=EOF)
	{
		if(ch!=' ')
		{
			a[c]=ch;
			c++;
		}
		ch=fgetc(p);
	}
	return (c-1);
}
int lookup(char *a,char c)
{
	int index=0;
	while(a[index]!=c)
	{
		index++;
	}
		return(index);
}

