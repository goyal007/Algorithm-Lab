#include <sys/time.h>
#include<stdio.h>
int main(int argc,char **argv)
{ 
	FILE *fp=fopen("1.txt","r");
	int arr[8][8],i,j,k,count=0,fin=0,small;
	while(!feof(fp))
	{
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				fscanf(fp,"%d\n",&arr[i][j]);	
	}
	for(i=0;i<8;i++)
	{
			for(j=0;j<8;j++)
				printf("%d\t",arr[i][j]);	
			printf("\n");
	}
	printf("\n");
	int hash[8];	//for double the ''row''(prevent from multiple doubling)
long time_start, time_end;
struct timeval tv;
gettimeofday(&tv,NULL); 
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
	while(fin!=8)
	{
		fin=0;
		for(i=0;i<8;i++)	
		{
			hash[i]=0;
		}
		//subtract smallest-1 from all 'column' respectively
		for(i=0;i<8;i++)
		{
			small=arr[0][i];
			count=0;
			for(j=0;j<8;j++)
			{
				if(arr[j][i]<=small)
				{
					small=arr[j][i];
				}
			}
			for(j=0;j<8;j++)
			{
				if(arr[j][i]==small)
				{
					hash[j]=1;
					count++;
				}
			}
			if(small>1 && count!=8)
			{
				for(j=0;j<8;j++)
				{
					arr[j][i]=arr[j][i]-(small-1);//as we have to make ot 1 not 0
				}
			}
			else if(count==8)
			{
				for(j=0;j<8;j++)
				{
					arr[j][i]=arr[j][i]-(small);//make whole column zero
				}
			}
		}
		
		//now double of rows
		for(j=0;j<8;j++)
		{
			if(hash[j]==1)
			{
				for(k=0;k<8;k++)
				{
					arr[j][k]=arr[j][k]*2;
				}
			}
		}
		for(k=0;k<8;k++)
		{
			if(arr[0][k]==0)	//if first element is 0 then entire column must be zero as per condition
			{
				fin++;
			}
		}
	}
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	for(i=0;i<8;i++)
	{
			for(j=0;j<8;j++)
				printf("%d\t",arr[i][j]);	
			printf("\n");
	}
printf("\n\nexecution time==%ld\n",time_end-time_start);
return (0);
}
