#include<stdio.h>
#include"argument.h"
void printfun(int n,int s[n+1][n+1],int i,int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		printfun(n,s,i,s[i][j]);
		printfun(n,s,s[i][j]+1,j);
		printf(")");
	}
}
