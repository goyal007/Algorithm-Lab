#include <sys/time.h>
#include<stdio.h>
int main(int argc,char **argv)
{ 
	int i=0,j,n,m,c=0;
	n = strtol(argv[1], NULL, 0);
	m = strtol(argv[2], NULL, 0);
	long long int arr[n][m];
	if(n<m)
	{
	if(n%2==0)
		c=n/2;
	else
		c=n/2+1;
	}
	else
	{
	if(m%2==0)
		c=m/2;
	else
		c=m/2+1;
	}
long time_start, time_end;
struct timeval tv;
gettimeofday(&tv,NULL); 
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
for(i=0;i<c;i++)
	{
		for(j=i;j<m-i;j++)
		{
			arr[i][j]=i;
			arr[n-1-i][j]=i;
		}
	}
for(i=0;i<c;i++)
	{
		for(j=i;j<n-i;j++)
		{
			arr[j][i]=i;
			arr[j][m-i-1]=i;
		}
	}
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%lld ",arr[i][j]);
		}
		printf("\n");
	}
printf("execution time==%ld\n",time_end-time_start);
return (0);
}
