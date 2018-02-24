#include <sys/time.h>
#include<stdio.h>
#include<stdlib.h>		//for random function
#include"variable.h"
#include"signature.h"
int main(int argc,char **argv)
{
// Declaration of timeval variables which will capture the system time
long time_start, time_end;
struct timeval tv;
int k,n;
	printf("input array size\n");
	scanf("%d",&n);
	int arr[n],b[n];
	for(k=0;k<n;k++)
	{
		arr[k]=rand();
		b[k]=arr[k];		//extra array for reusing the same set of values for all the sorting method
	}

gettimeofday(&tv,NULL); /*gets the current system time into variable tv */
time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
// calculating start time in seconds
printf("bubble sorting...\n");
	bubble(arr,n);
	for(k=0;k<n;k++)
	{
		arr[k]=b[k];
	}
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
// (time_end-time_start) gives the total execution time
printf("time for bubble sorting is =%ld microsec\n\n",time_end-time_start);


time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("\nselection sorting ...\n");
	selection(arr,n);
	for(k=0;k<n;k++)
	{
		arr[k]=b[k];
	}
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("time for selection sorting is =%ld microsec\n\n",time_end-time_start);


time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("\ninsertion sorting ...\n");
	insertion(arr,n);
	for(k=0;k<n;k++)
	{
		arr[k]=b[k];
	}
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("time for insertion sorting is =%ld microsec\n\n",time_end-time_start);


time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("\nmerge sorting ...\n");
	mergesort(arr,0,n-1,n);
	for(k=0;k<n;k++)
	{
		printf("%d\t",arr[k]);
	}
	for(k=0;k<n;k++)
	{
		arr[k]=b[k];
	}
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("time for merge sorting is =%ld microsec\n\n",time_end-time_start);


time_start = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("\nquick sorting...\n");
	quicksort(arr,0,n-1);
	for(k=0;k<n;k++)
	{
		printf("%d\t",arr[k]);
	}
	for(k=0;k<n;k++)
	{
		arr[k]=b[k];
	}
gettimeofday (&tv, NULL);
time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
printf("time for quick sorting is =%ld microsec\n\n",time_end-time_start);

return (0);
}
