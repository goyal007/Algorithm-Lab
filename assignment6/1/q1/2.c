#include"arg.h"
#include<stdio.h>
void head(float *arr,int data[][2],int item,int m)
{
	int i;
	float val=0;
	//for(i=1;i<item+1;i++)
	//printf("%f\n",arr[i]);
	while(m!=0)
	{
		int max_index;
		max_index=1;
		for(i=2;i<item+1;i++)
		{
			if(arr[i]>arr[max_index])
			{
				max_index=i;
			}
		}
		arr[max_index]=-1;
		//for(i=1;i<item+1;i++)
			//printf("%f\t",arr[i]);
		if(m>=data[max_index][0])
		{
			m=m-data[max_index][0];
			printf("item %d with fraction%d/%d\n",max_index,data[max_index][0],data[max_index][0]);
			val=val+data[max_index][1];
		}
		else
		{
			
			printf("item %d with fraction%d/%d\n",max_index,m,data[max_index][0]);
			val=val+data[max_index][1]*(m)*1.0/(data[max_index][0]);
			m=0;
		}
	}
	printf("total value=%f\n",val);
}

