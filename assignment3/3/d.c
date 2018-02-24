#include<stdio.h>
int flush(int *b1,char *b2,int *c1,char *c2)
{
	int i,j,k,l,co1=0,co2=0,co3=0,co4=0;
	if((b2[0]==b2[1])&&(b2[1]==b2[2])&&(b2[2]==b2[3])&&(b2[3]==b2[4]))
	{
		co1++;
	}
	if((c2[0]==c2[1])&&(c2[1]==c2[2])&&(c2[2]==c2[3])&&(c2[3]==c2[4]))
	{
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
		for(i=4;i>=0;i--)
		{
			if(b1[i]==c1[i])
				continue;
			else if(b1[i]>c1[i])
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
		printf("Tie\n");
	}
}
