#include"argum.h"
#include<stdio.h>
void func2(int l1,int l2,int l3,int arr2[l1+1][l2+1][l3+1],char *a)
{
	int i,j,k,index=0;
	i=l1;
	j=l2;
	k=l3;
	char charr[l1+1];
	while(1)
	{
		if(i==0 || j==0 || k==0)
			break;
		else if(arr2[i][j][k]==4)
		{
			//printf("%c ",a[i-1]);
			charr[index]=a[i-1];
			index++;
			i--;
			j--;
			k--;
		}
		else if(arr2[i][j][k]==3)
			k--;
		else if(arr2[i][j][k]==2)
			j--;
		else if(arr2[i][j][k]==1)
			i--;
	}
	//charr[index]='\0';
	//printf("%d ",index);
	for(i=index-1;i>=0;i--)
	{
		printf("%c ",charr[i]);
	}
}
