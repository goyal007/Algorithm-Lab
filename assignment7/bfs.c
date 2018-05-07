#include<stdio.h>
int main()
{
	int n,i,j;
	FILE *fp=fopen("bfsinput.txt","r");
	fscanf(fp,"%d\n",&n);
	int arr[n][n];
	//taking graph from file
	while(!feof(fp))
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				fscanf(fp,"%d\n",&arr[i][j]);
	}
	printf("given matrix\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		
		}
	printf("\n");
	}
	//BFS
	printf("BFS OF THE GRAPH\n");
	int dist[n],temp[n],front=0,rear=0,source_dis=1,poped;//temp for queue
	for(i=0;i<n;i++)
	{
		dist[i]=0;
	}
	dist[0]=1;//for source node
	temp[0]=0;//insert in queue
	rear++;
	while(front!=rear)
	{
		poped=temp[front];
		front++;
		source_dis++;
		for(i=0;i<n;i++)
		{
			if(arr[poped][i]==1 && dist[i]==0)//dist=0 means unvisited
			{
				temp[rear]=i;
				dist[i]=dist[poped]+1;// parent dist+1==child distance
				rear++;
			}
		}
		printf("%d and distance %d\n",poped,dist[poped]-1);//minus 1 for exact distance
	}
	/////////////////////////////////////////
	return 0;
}
/*
6
0 1 1 1 0 0
1 0 0 0 1 0
1 0 0 0 1 1
1 0 0 0 0 1
0 1 1 0 0 1
0 0 1 1 1 0
*/
