#include"argu.h"
#include<stdio.h>
int knap(int m, int n, int weight[], int value[])
{
   int i, w;//w ranges from o to m
   int arr[n+1][m+1];
   for(i=0;i<=n;i++)
   		arr[i][0]=0;
   for(i=0;i<=m;i++)
   		arr[0][i]=0;
   for (i = 1; i <= n; i++)// table K[][] in bottom up manner
   {
       for (w = 1; w <= m; w++)
       {
           if(weight[i-1]>w)//means we cant select item so same value as for previous item choosing//[i-1] as index start from 0 for 1st item
           {
           		arr[i][w]=arr[i-1][w];
           }
           	else
           	{
         //max of item selected and not selected//if item selected then its value and addition of remaining value that can be obtained from (m-weight_selected)
           		arr[i][w]=max(arr[i-1][w],arr[i-1][w-weight[i-1]]+value[i-1]);// 															
           	}
       }
   }
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= m; w++)
       {
           printf("%-5d ",arr[i][w]);
       }
       printf("\n");
   }
   i=n;
   w=m;
  while(arr[i][w]!=0)
  {
  	if(arr[i][w]==arr[i-1][w])
  	{	
  			i--;
  	}
  	else
  	{
  		printf("item  %d is selected\n",i);
  		i--;
  		w=w-weight[i];
  	}
  }
   return arr[n][m];
}
