#include<stdio.h>
#include"argument.h"
int main()
{
	FILE *fp;
	fp=fopen("matrix.txt","r");
	int p,i,n;
	fscanf(fp,"%d\n",&p);
	int arr[p];
	i=0;
	while(!feof(fp))
	{
		fscanf(fp,"%d\n",&arr[i]);
		i++;
	}
	printf("Input is\n");
	for(i=0;i<p;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	function1(arr,p);
	fclose(fp);
}
