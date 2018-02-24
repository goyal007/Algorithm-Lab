#include<stdio.h>
int straight(int *b1,int *c1)
{
	int co1=0,co2=0;
	if(b1[0]==2 && b1[4]==14)//case when 2 and A can be consecutive
	{
		if((b1[1]==3)&&(b1[2]==4)&&(b1[3]==5))
			co1++;
	}
	else
	{
		if((b1[0]+1==b1[1])&&(b1[1]+1==b1[2])&&(b1[2]+1==b1[3])&&(b1[3]+1==b1[4]))
			co1++;
	}
		
	if(c1[0]==2 && c1[4]==14)
	{
		if((c1[1]==3)&&(c1[2]==4)&&(c1[3]==5))
			co2++;
	}
	else
	{
		if((c1[0]+1==c1[1])&&(c1[1]+1==c1[2])&&(c1[2]+1==c1[3])&&(c1[3]+1==c1[4]))
			co2++;
	}
	
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
	if(co1==1 && co2==1)
	{
		if(b1[4]==c1[4])
		{
			printf("Tie\n");
			return 1;
		}
		else if(b1[4]>c1[4])
		{
			printf("Black wins\n");
			return 1;
		}
		else
		{
			printf("White wins\n");
			return 1;
		}
	}
}
