#include<stdio.h>
#include"argu.h"
int main()
{
	int value[50],weight[50];
	FILE *fp=fopen("file.txt","r");
	int i,j,m,n;
 	while(!feof(fp))//for multiple input set
 	{
 			fscanf(fp,"%d\n",&m);
 			fscanf(fp,"%d\n",&n);
 			for(i=0;i<n;i++)
	 			fscanf(fp,"%d\n",&weight[i]);
	 		for(i=0;i<n;i++)
	 			fscanf(fp,"%d\n",&value[i]);
 	
 		printf("m=%d\n",m);
		printf("n=%d\n",n);
		for(i=0;i<n;i++)
		{
			printf("%d,%d\n",weight[i],value[i]);
		}
    	printf("maximim value=%d\n", knap(m,n,weight,value));
    	printf("\n\n");
    }
    fclose(fp);
    return 0;
}

