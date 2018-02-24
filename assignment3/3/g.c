#include<stdio.h>
int two_pairs(int *b1,int *c1)
{
	int co1=0,co2=0,x1,x2,x3,y1,y2,y3;
	if((b1[0]==b1[1])&&(b1[2]==b1[3]))
	{
		co1++;
		if(b1[0]>b1[2])		// value of highest of both pair
		{
			x1=b1[0];
			x2=b1[2];
		}
		else
		{
			x1=b1[2];
			x2=b1[0];
		}
		x3=b1[4];			//store value other than pair
	}
	else if((b1[1]==b1[2])&&(b1[3]==b1[4]))
	{
		co1++;	
		if(b1[1]>b1[3])
		{
			x1=b1[1];
			x2=b1[3];
			
		}
		else
		{
			x1=b1[3];
			x2=b1[1];
		}
		x3=b1[0];
	}
	else if((b1[0]==b1[1])&&(b1[3]==b1[4]))
	{
		co1++;
		if(b1[1]>b1[3])
		{
			x1=b1[1];
			x2=b1[3];
			
		}
		else
		{
			x1=b1[3];
			x2=b1[1];
		}
		x3=b1[2];
	}
	if((c1[0]==c1[1])&&(c1[2]==c1[3]))
	{
		co2++;
		if(c1[0]>c1[2])
		{
			y1=c1[0];
			y2=c1[2];
		}
		else
		{
			y1=c1[2];
			y2=c1[0];
		}
		y3=c1[4];
	}
	else if((c1[1]==c1[2])&&(c1[3]==c1[4]))
	{
		co2++;	
		if(c1[1]>c1[3])
		{
			y1=c1[1];
			y2=c1[3];
			
		}
		else
		{
			y1=c1[3];
			y2=c1[1];
		}
		y3=c1[0];
	}
	else if((c1[0]==c1[1])&&(c1[3]==c1[4]))
	{
		co2++;
		if(c1[1]>c1[3])
		{
			y1=c1[1];
			y2=c1[3];
			
		}
		else
		{
			y1=c1[3];
			y2=c1[1];
		}
		y3=c1[2];
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
	if(co1==1&&co2==1)
	{
		if(x1>y1)
		{
			printf("Black wins\n");
			return 1;
		}
		else if(x1<y1)
		{
			printf("White wins\n");
			return 1;
		}
		if(x2>y2)
		{
			printf("Black wins\n");
			return 1;
		}
		else if(x2<y2)
		{
			printf("White wins\n");
			return 1;
		}
		if(x3>y3)
		{
			printf("Black wins\n");
			return 1;
		}
		else if(x3<y3)
		{
			printf("White wins\n");
			return 1;
		}
		printf("Tie\n");
		return 1;
	}	
}
