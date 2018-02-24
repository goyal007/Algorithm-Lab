#include<stdio.h>
int main()
{
	int i,j,n,max=1;
	printf("enter input\n");
	scanf("%d",&n);
	int arr[n],longest[n];
	for(i=0;i<n;i++)
	{
		longest[i]=1;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if((arr[i]>arr[j])&&((longest[j]+1)>longest[i]))
			{
				longest[i]=longest[j]+1;
			}
		}
	}
	for(i=1;i<n;i++)
	{
		if(longest[i]>longest[i-1])
		{
			max=longest[i];
		}
	}
	printf("longest increasing subsequences:%d",max);
	return 0;
}
