#include <sys/time.h>
#include<stdio.h>
#include"argu.h"
void selecttionsort(int *b1,char *b2)		//sorted order of the cards and respectively their suits
{
	int lowindex=0,i,j,t;
	char a;
		for(i=0;i<5;i++)
		{
			lowindex=i;
			for(j=i;j<5;j++)
			{
				if(b1[lowindex]>b1[j])
				lowindex=j;
			}
			t=b1[lowindex];
			b1[lowindex]=b1[i];
			b1[i]=t;
			a=b2[lowindex];
			b2[lowindex]=b2[i];
			b2[i]=a;
		}
}
int main(int argc,char **argv)
{
	long time_start, time_end;
	struct timeval tv;
	FILE *fp=fopen("1.txt","r+");
	char a[2],b2[5],c2[5];
	int b1[5],c1[5],i,j,k,c;
	
	
	gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	
	
	while(!feof(fp))
	{
		c=0;
		for(i=0;i<5;i++)					
		{									// storing card value and suits for player 1
			fscanf(fp,"%s\n",a);			
			if(a[0]=='A')
				b1[i]=14;					//assign value to cards T,J,Q,K,A
			else if(a[0]=='K')
				b1[i]=13;
			else if(a[0]=='Q')
				b1[i]=12;
			else if(a[0]=='J')
				b1[i]=11;
			else if(a[0]=='T')
				b1[i]=10;
			else
				b1[i]=a[0]-'0';			//convert into decimal(integer) from their char value
			b2[i]=a[1];					// storing suits
			//printf("%d\t",b1[i]);
		}
		for(i=0;i<5;i++)
		{
			fscanf(fp,"%s\n",a);		// storing card value and suits for player 2
			if(a[0]=='A')
				c1[i]=14;
			else if(a[0]=='K')
				c1[i]=13;
			else if(a[0]=='Q')
				c1[i]=12;
			else if(a[0]=='J')
				c1[i]=11;
			else if(a[0]=='T')
				c1[i]=10;
			else
				c1[i]=a[0]-'0';
			c2[i]=a[1];
		}
		selecttionsort(b1,b2);
		selecttionsort(c1,c2);
		/*for(i=0;i<5;i++)
			printf("\n%d\t%c\n",b1[i],b2[i]);
		for(i=0;i<5;i++)
			printf("\n%d\t%c\n",c1[i],c2[i]);*/
		c=str_flush(b1,b2,c1,c2);
		if(c==1)
			continue;
		c=four_kind(b1,c1);
		if(c==1)
			continue;
		c=full_house(b1,c1);
		if(c==1)
			continue;
		c=flush(b1,b2,c1,c2);
		if(c==1)
			continue;
		c=straight(b1,c1);
		if(c==1)
			continue;
		c=three_kind(b1,c1);
		if(c==1)
			continue;
		c=two_pairs(b1,c1);
		if(c==1)
			continue;
		c=pair(b1,c1);
		if(c==1)
			continue;
		high_card(b1,c1);
	}
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("Total execution time::%ld\n",time_end-time_start);
	fclose(fp);
	return 0;
}
