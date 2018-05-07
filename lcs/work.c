#include"argum.h"
#include<string.h>
#include<stdio.h>
void func(char *a,char *b)
{
	int i,j,k,l1,l2;
	l1=strlen(a);
	l2=strlen(b);
	int arr[l1+1][l2+1],arr2[l1+1][l2+1];
	for(i=0;i<=l1;i++)
	{
		for(j=0;j<=l2;j++)
		{
				if(i==0||j==0)
				{
					arr[i][j]=0;
				}
				else
				{
					if(a[i-1]==b[j-1])
					{
						arr[i][j]=arr[i-1][j-1]+1;
						arr2[i][j]=4;
					}
					else
					{
						if(arr[i-1][j]>arr[i][j-1])//max of arr[i-1[[j] and arr[i][j-1]
						{
							arr2[i][j]=1;
							arr[i][j]=arr[i-1][j];
						}
						else
						{
							arr2[i][j]=2;
							arr[i][j]=arr[i][j-1];
						}
					}
				}
			
		}
	}
	printf("maximum=%d\n",arr[l1][l2]);
	func2(l1,l2,arr2,a);
}

