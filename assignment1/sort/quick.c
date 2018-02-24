#include"variable.h"
#include"signature.h"
#include<stdio.h>
int partition(int arr[],int beg,int end)
{
	int pivot=arr[end],t;
	int partionind=beg;
	for(i=beg;i<end;i++)
	{
		if(arr[i]<=pivot)
		{
			t=arr[i];
			arr[i]=arr[partionind];
			arr[partionind]=t;
			partionind++;
		}
	}
	t=arr[end];					//swap pivot with partionind
	arr[end]=arr[partionind];
	arr[partionind]=t;
	return partionind;
}
void quicksort(int arr[],int beg,int end)
{
	int part;
	if(beg<end)
	{
		part=partition(arr,beg,end);
		quicksort(arr,beg,part-1);
		quicksort(arr,part+1,end);
	}
}

