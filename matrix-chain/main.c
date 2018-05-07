#include"argument.h"
void function1(int *arr,int p)
{
	int n,i,j,k,l,q;
	n=p-1;
	int m[p][p],s[p][p];
	for(i=1;i<p;i++)
		m[i][i]=0;
	for(l=2;l<p;l++)//minimum pair is of length 2
	{
		for(i=1;i<(p-l+1);i++)//maintain i<j
		{
			j=i+l-1;
			m[i][j]=99999;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;//k tells us the point where bracket has to be inserted
				}
			}
		}
	}
	printfun(n,s,1,n);
}
