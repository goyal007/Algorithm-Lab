#include"argum.h"
#include<string.h>
#include<stdio.h>
/*int max(int x,int y,int z)
{
	int t;
	t=(x>y?x:y);
	return (t>z?t:z);
}*/
void func(char *a,char *b,char *c)
{
	int i,j,k,l1,l2,l3;
	l1=strlen(a);
	l2=strlen(b);
	l3=strlen(c);
	int arr[l1+1][l2+1][l3+1],arr2[l1+1][l2+1][l3+1];
	for(i=0;i<=l1;i++)
	{
		for(j=0;j<=l2;j++)
		{
			for(k=0;k<=l3;k++)
			{
				if(i==0||j==0||k==0)
				{
					arr[i][j][k]=0;
				}
				else
				{
					if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
					{
						arr[i][j][k]=arr[i-1][j-1][k-1]+1;
						arr2[i][j][k]=4;
					}
					else
					{
						//arr[i][j][k]=max(arr[i-1][j][k],arr[i][j-1][k],arr[i][j][k-1]);
						if(arr[i-1][j][k]>=arr[i][j-1][k] && arr[i-1][j][k]>=arr[i][j][k-1])
						{
							arr2[i][j][k]=1;
							arr[i][j][k]=arr[i-1][j][k];
						}
						else if(arr[i][j-1][k]>=arr[i-1][j][k] && arr[i][j-1][k]>=arr[i][j][k-1])
						{
							arr2[i][j][k]=2;
							arr[i][j][k]=arr[i][j-1][k];
						}
						else if(arr[i][j][k-1]>=arr[i-1][j][k] && arr[i][j][k-1]>=arr[i][j-1][k])
						{
							arr2[i][j][k]=3;
							arr[i][j][k]=arr[i][j][k-1];
						}
					}
				}
			}
		}
	}
	printf("maximum=%d\n",arr[l1][l2][l3]);
	func2(l1,l2,l3,arr2,a);
}

