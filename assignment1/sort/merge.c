#include"variable.h"
#include"signature.h"
#include<stdio.h>
void merge(int arr[],int beg,int mid,int end,int n)
{
	i=beg;
	j=mid+1;
	int indx=beg;
	int temp[n];
	while(i<=mid && j<=end)
	{
		if(arr[i]<arr[j])
		{
			temp[indx]=arr[i];
			i++;
			indx++;
		}
		else
		{
			temp[indx]=arr[j];
			j++;
			indx++;
		}
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[indx]=arr[j];
			j++;
			indx++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[indx]=arr[i];
			i++;
			indx++;
		}
	}
	for(k=beg;k<indx;k++)
		arr[k] = temp[k];
}
void mergesort(int arr[],int beg,int end,int n)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergesort(arr,beg,mid,n);
		mergesort(arr,mid+1,end,n);
		merge(arr,beg,mid,end,n);
	}
}