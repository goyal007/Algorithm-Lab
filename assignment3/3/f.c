#include<stdio.h>
int three_kind(int *b1,int *c1)
{
	int co1=0,co2=0,a1,a2;
	if((b1[0]==b1[1])&&(b1[1]==b1[2]))		//checking 3 of same value
		co1++;
	else if((b1[2]==b1[3])&&(b1[3]==b1[4]))
		co1++;
	else if((b1[1]==b1[2])&&(b1[2]==b1[3]))
		co1++;
	if((c1[0]==c1[1])&&(c1[1]==c1[2]))			
		co2++;
	else if((c1[2]==c1[3])&&(c1[3]==c1[4]))
		co2++;
	else if((c1[1]==c1[2])&&(c1[2]==c1[3]))
		co2++;
	
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
		
			a1=b1[2];	//for comparing value of highest of 3 pair
			a2=c1[2];
		if(a1==a2)
		{
			printf("Tie\n");
			return 1;
		}
		else if(a1>a2)
		{
			printf("Black wins\n");
			return 1;
		}
		else if(a1<a2)
		{
			printf("White wins\n");
			return 1;
		}
	}
}
