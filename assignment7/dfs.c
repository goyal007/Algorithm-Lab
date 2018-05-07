#include<stdio.h>
#include<stdlib.h>
int time=0;
struct dfs
{
	int start;
	int end;
	int status;
	int parent;
	int node;
};
void dfs(int n,int arr[n][n],struct dfs *list[n],int u)
{   
	list[u]->status=1;
	(time)=(time)+1;
	list[u]->start=time;
	list[u]->node=u;
	int i=0;
	for(i=0;i<n;i++)
	{
		if(arr[u][i]==1)
		{
			if(list[i]->status==0)
			{
				list[i]->parent=u;
				dfs(n,arr,list,i);
			}
		}
	}
	list[u]->status=2;
	(time)=(time)+1;
	list[u]->end=time;
}


int main()
{
	int n,i,j;
	FILE *fp=fopen("dfsinput .txt","r");
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
	
	
	//DFS
	struct dfs *list[n];
	printf("DFS OF THE GRAPH\n");
	for(i=0;i<n;i++)
	{   
	    list[i] = (struct dfs*) malloc( sizeof(struct dfs) );//memory allocation
		list[i]->start=0;
		list[i]->end=0;
		list[i]->parent=-1;
		list[i]->status=0;
		list[i]->node=0;
	}
	for(i=0;i<n;i++)
	{   
		if(list[i]->status==0)
			dfs(n,arr,list,0);
	}
	for(i=0;i<n;i++)
	{
	printf("%d->  %-5d %-5d %-5d\n",list[i]->node,list[i]->start,list[i]->end,list[i]->parent);
	}
	return 0;
}

