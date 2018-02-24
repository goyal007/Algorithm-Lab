#include"variable.h"
#include"signature.h"
#include<stdio.h>
void bubble(int arr[],int n)
{
	int c=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
				c++;
			}
		}
		if(c==0)
			break;
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
