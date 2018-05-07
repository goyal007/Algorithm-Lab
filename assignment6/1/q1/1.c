#include"arg.h"
#include<stdio.h>
void display(int data[][2],int item)
{
	int i;
	for(i=1;i<item+1;i++)
	{
		printf("item%d->weight=%d and value=%d\n",i,data[i][0],data[i][1]);// weight and value respectively
	}
}
