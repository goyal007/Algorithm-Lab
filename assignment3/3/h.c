#include<stdio.h>
int pair(int *b1,int *c1)
{
	int co1=0,co2=0,arr1[3],arr2[3],x,y;
	if(b1[0]==b1[1])		// store pair value in x and other value in ascending order in arr1
	{
		x=b1[0];
		arr1[0]=b1[2];
		arr1[1]=b1[3];
		arr1[2]=b1[4];
		co1++;
	}
	else if(b1[1]==b1[2])
	{
		x=b1[1];
		arr1[0]=b1[0];
		arr1[1]=b1[3];
		arr1[2]=b1[4];
		co1++;
	}
	else if(b1[2]==b1[3])
	{
		x=b1[2];
		arr1[0]=b1[0];
		arr1[1]=b1[1];
		arr1[2]=b1[4];
		co1++;
	}
	else if(b1[3]==b1[4])
	{
		x=b1[3];
		arr1[0]=b1[0];
		arr1[1]=b1[1];
		arr1[2]=b1[2];
		co1++;
	}
	//////////////////
	if(c1[0]==c1[1])
	{
		y=c1[0];
		arr2[0]=c1[2];
		arr2[1]=c1[3];
		arr2[2]=c1[4];
		co2++;
	}
	else if(c1[1]==c1[2])
	{
		y=c1[1];
		arr2[0]=c1[0];
		arr2[1]=c1[3];
		arr2[2]=c1[4];
		co2++;
	}
	else if(c1[2]==c1[3])
	{
		y=c1[2];
		arr2[0]=c1[0];
		arr2[1]=c1[1];
		arr2[2]=c1[4];
		co2++;
	}
	else if(c1[3]==c1[4])
	{
		y=c1[3];
		arr2[0]=c1[0];
		arr2[1]=c1[1];
		arr2[2]=c1[2];
		co2++;
	}
	////
	if(co1==0&&co2==0)
		return 0;
	if(co1==0&&co2==1)
	{
		printf("White wins\n");
		return 1;
	}
	if(co1==1&&co2==0)
	{
		printf("Black wins\n");
		return 1;
	}
	if(co1==1&&co2==1)
	{
		if(x>y)
		{
			printf("Black wins\n");
			return 1;
		}
		else if(x<y)
		{
			printf("White wins\n");
			return 1;
		}
		int j;
		for(j=2;j>=0;j--)
		{
			if(arr1[j]>arr2[j])
			{
				printf("Black wins\n");
				return 1;
			}
			else if(arr1[j]<arr2[j])
			{
				printf("White wins\n");
				return 1;
			}
		}
		printf("Tie\n");
		return 1;
	}	
	
}
