#include<stdio.h>
int str_flush(int *b1,char *b2,int *c1,char *c2)
{
	int i,j,k,l,co1=0,co2=0,co3=0,co4=0;
	if((b2[0]==b2[1])&&(b2[1]==b2[2])&&(b2[2]==b2[3])&&(b2[3]==b2[4]))//checking suits same or not
	{
		co1++;
	}
	if(co1!=0)
	{
		if(b1[0]==2 && b1[4]==14)//case when 2 and A can be consecutive
		{
			if((b1[1]==3)&&(b1[2]==4)&&(b1[3]==5))
				co2++;
		}
		else
		{
			if((b1[0]+1==b1[1])&&(b1[1]+1==b1[2])&&(b1[2]+1==b1[3])&&(b1[3]+1==b1[4]))
				co2++;
		}
	}
	if((c2[0]==c2[1])&&(c2[1]==c2[2])&&(c2[2]==c2[3])&&(c2[3]==c2[4]))
	{
		co3++;
	}
	if(co3!=0)
	{
		if(c1[0]==2 && c1[4]==14)
		{
			if((c1[1]==3)&&(c1[2]==4)&&(c1[3]==5))
				co4++;
		}
		else
		{
			if((c1[0]+1==c1[1])&&(c1[1]+1==c1[2])&&(c1[2]+1==c1[3])&&(c1[3]+1==c1[4]))
				co4++;
		}
	}
	//basic conditions 
	if(co1==0&&co2==0)
		return 0;
	if(co1==0&&co4==1)
	{
		printf("White wins\n");
		return 1;
	}
	else if(co2==1&&co3==0)
	{
		printf("Black wins\n");
		return 1;
	}
	if(co2==1&&co4==1)
	{
			if(b1[4]>c1[4])
			{
				printf("Black wins\n");
				return 1;
			}
			else if(b1[4]==c1[4])
			{
				printf("Tie\n");
				return 1;
			}
			else
			{
				printf("White wins\n");
				return 1;
			}
	}
	return 0;	
}
