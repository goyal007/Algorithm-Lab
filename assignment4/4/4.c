#include<stdio.h>
int main()
{
	int i,j,n,max=1,x,y;
	printf("enter input\n");
	scanf("%d",&n);
	int longest[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&longest[i]);
	}
	x=0;
	for(i=1;i<n;i++)
	{
			if((longest[i]+longest[i-1])>=0)
			{
				longest[i]=longest[i-1]+longest[i];
			}
	}
	max=longest[0];
	for(i=1;i<n;i++)
	{
		if(longest[i]>longest[i-1])
		{
			max=longest[i];
		}
	}
	if(max==longest[0])
	{
		printf("X(%d,%d)\n",0,0);
	}
	for(i=1;i<n;i++)
	{
		if(longest[i]==max)
		{
			printf("X(%d,%d)\n",x,i);
		}
		else if(longest[i]<0)
		{
			x=i+1;
		}
	}
	return 0;
}

