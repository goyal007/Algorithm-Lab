#include<stdio.h>
#include"arg.h"
int main()
{
	int i,j;
	int m,item;
	FILE *fp=fopen("file.txt","r");
	fscanf(fp,"%d\n",&m);
	fscanf(fp,"%d\n",&item);
	int data[item+1][2];
	for(i=1;i<item+1;i++)
	{
		fscanf(fp,"%d\n",&data[i][0]);// weight
	}
	for(i=1;i<item+1;i++)
	{
		fscanf(fp,"%d\n",&data[i][1]);// value 
	}
	display(data,item);//1.c
	
	float arr[item+1];//store result for value/weight
	for(i=1;i<item+1;i++)
	{
		arr[i]=(data[i][1]*1.0)/data[i][0];
	}
	head(arr,data,item,m);
	fclose(fp);
	return 0;
}
