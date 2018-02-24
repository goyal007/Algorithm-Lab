#include <sys/time.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{ 
	long time_start, time_end;
	int l;
	struct timeval tv;
	char a[2000]="XxxxxxxxqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqXYYYYYYYYYYYYYYYYYYYYYYYYYXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYYYxxxxxxxxxxxxxxxxxxxxxXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqeeeeeeeeeeeeeeeeeeeeeeeetttttttttttttttttttttttttttttttttjfcfghgtyfgygtftufyrftfrdrydfrydfrydfyftugqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqoiiqieowuiohefuigfyiegrfyigerfiyrgfgyifrY";
	//printf("enter string:");
	//scanf("%[^\n]s",a);
	//printf("\ninput string is::%s\n",a);
	l=strlen(a);
	int i,j,c=0,arr[l],index=0,x=0;
	gettimeofday(&tv,NULL); 
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;	//method 1
	for(i=0;i<l;i++)
	{
		if(a[i]=='X')
		{
			for(j=i+1;j<l;j++)
			{
				if(a[j]=='Y')		
				{	
					c++;
				}
			}
		}
	}
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("1)total substrings are:%d\n",c);
	printf("1)total execution time::%ld\n",time_end-time_start);
	c=0;
	gettimeofday(&tv,NULL); 
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;		//method 2
	for(i=0;i<l;i++)
	{
		if(a[i]=='X')
			{
				arr[index]=0;
				index++;
			}
		else if(a[i]=='Y')
		{
			arr[index]=1;
			index++;
		}
	}
	for(i=0;i<index;i++)
	{
	if(arr[i]==0)
	{
		for(j=i+1;j<index;j++)
		{
			if(arr[j]==1)		
			{	
				c++;
			}
		}
	}
	}
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("2)total substrings are:%d\n",c);
	printf("2)total execution time::%ld\n",time_end-time_start);
	c=0;
	gettimeofday(&tv,NULL); 
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;	//method 3
	for(i=0;i<l;i++)
	{
		if(a[i]=='X')
			x++;
		if(a[i]=='Y')
			c=c+x;
	}
	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	printf("3)total substrings are:%d\n",c);
	printf("3)total execution time::%ld\n",time_end-time_start);
	return (0);
}
