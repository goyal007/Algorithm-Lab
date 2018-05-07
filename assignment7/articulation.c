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
	FILE *fp=fopen("articulation.txt","r");
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
	
	/////////////////////////////////////////////////////////////////////////
	//articulation
	int arr2[n][n],new[n][n];
	//copy arr to arr2
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr2[i][j]=arr[i][j];
			//printf("%d ",arr2[i][j]);
		}
	printf("\n");
	}
	
	int temp1[2][n],temp2[2][n];//temp1 and temp2->for making graph to find articulation points after dfs 
	for(i=0;i<n;i++)
	{
		temp1[0][i]=list[i]->node;
		temp1[1][i]=list[i]->start;
		temp2[0][i]=list[i]->node;
		temp2[1][i]=list[i]->end;
	}
	/*for(i=0;i<n;i++)
	{
		printf("%d %d\n",temp1[0][i],temp1[1][i]);
	}*/
	//bubble sort ascending
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(temp1[1][j]>temp1[1][j+1])
				{
					int t=temp1[1][j];
					temp1[1][j]=temp1[1][j+1];
					temp1[1][j+1]=t;
					
					int t2=temp1[0][j];
					temp1[0][j]=temp1[0][j+1];
					temp1[0][j+1]=t2;
				}
		}
		
	}
	//bubble sort descending
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(temp2[1][j]<temp2[1][j+1])
				{
					int t=temp2[1][j];
					temp2[1][j]=temp2[1][j+1];
					temp2[1][j+1]=t;
					
					int t2=temp2[0][j];
					temp2[0][j]=temp2[0][j+1];
					temp2[0][j+1]=t2;
				}
		}
		
	}
	/*//sorted for finding edges involved in dfs except backedge
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",temp1[0][i],temp1[1][i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",temp2[0][i],temp2[1][i]);
	}*/
	//temp1 and temp2 contain sorted order of nodes and there starting and ending time respectively
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			new[i][j]=0;//basic
		}
		
	}
	//////////////////////////////use all dfs edges for new graph
	for(i=0;i<n-1;i++)
	{
		int x,y;
		if((temp1[1][i]+1)==temp1[1][i+1])
		{
			x=temp1[0][i];
			y=temp1[0][i+1];
			arr2[x][y]=0;
			arr2[y][x]=0;
			new[x][y]=1;
		}
		if((temp2[1][i]-1)==temp2[1][i+1])
		{
			x=temp2[0][i];
			y=temp2[0][i+1];
			arr2[x][y]=0;
			arr2[y][x]=0;
			new[x][y]=1;
		}
	}
	
	
	///////////////////////////for dfs_num
	
	int dfs_num[n][2],dfs_low[n][2];
	for(i=0;i<n;i++)
	{	
		dfs_num[i][0]=temp1[0][i];//respective node
		dfs_num[i][1]=i+1;	//main dfs num value
	}
	printf("\n");
	/*for(i=0;i<n;i++)
	{	
		printf("%d %d\n",dfs_num[i][0],dfs_num[i][1]);
	}*/
	
	
	/////////////////////////////for dfs_low
	for(i=0;i<n;i++)
	{
		dfs_low[i][0]=dfs_num[i][0];//for base case i.e without using backedge condition
		dfs_low[i][1]=dfs_num[i][1];
	}
	////////////////////////// now arr2 has only backedges
	int x,y,k,min=1000,index=0;
	int backpair[n][2];//array of pair of backedges
	for(i=0;i<n;i++)
	{
		min=100;
		for(j=0;j<n;j++)
		{
			if(arr2[i][j]==1)//found backedge
			{
				
				x=i;
				y=j;
				arr2[i][j]=0;//zero the backedge
				arr2[j][i]=0;
				if(temp1[1][i]>temp1[1][j])//node->>time greater to least will be backedge
				{	
					new[i][j]=1;	// add backedge to new graph(i to j)
					if(dfs_num[j][1]<min)
					{
						min=dfs_num[j][1];	//change dfs_low for 1 or more backedges from same node
						dfs_low[i][1]=min;
						backpair[index][0]=i;
						backpair[index][1]=j;
						index++;
					}
				}
				else
				{
					new[j][i]=1;
					if(dfs_num[i][1]<min)
					{
						min=dfs_num[i][1];
						dfs_low[j][1]=min;
						backpair[index][0]=j;
						backpair[index][1]=i;
						index++;
					}
				}
			}
		}
	}
	//print dfs_num and low value only for backedge
	//for(i=0;i<n;i++)
	//printf("%d %d %d\n",dfs_num[i][0],dfs_num[i][1],dfs_low[i][1]);
	
	//new graph
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",new[i][j]);
		}
		printf("\n");
	}*/
	
	//print pair of backedges
	
	//for(i=0;i<index;i++)
	//printf("%d %d\n",backpair[i][0],backpair[i][1]);
	
	
	
	//for filling dfs_low value for all the nodes 
	int p;
	for(i=0;i<index;i++)
	{
		int q,w,k,l;
		q=backpair[i][0];//backedge start from here,q>w;(l time used)
		w=backpair[i][1];//backedge ends here;(k time is used)
		for(p=0;p<n;p++)
		{
			if(q==dfs_num[p][0])
				l=dfs_num[p][1];
			else if(w==dfs_num[p][0])
				k=dfs_num[p][1];
		}
		
		int kope=k;
		kope++;
		for(;kope<l;kope++)
		{
			if(dfs_num[kope-1][1]>dfs_num[k-1][1])//as dfs_num(time-1) gives us index of node
			{
				if(dfs_low[kope-1][1]>dfs_num[k-1][1])	//always take lowest dfs_low value so condition
					dfs_low[kope-1][1]=dfs_num[k-1][1];
				
			}
		}
		
	}
	printf("node  d_num  d_low  \n\n");
	for(i=0;i<n;i++)
		printf("%5d %5d %5d\n",dfs_num[i][0],dfs_num[i][1],dfs_low[i][1]);//dfsf_num[i][0] gives node value
		
/////////////////////////////////////////////////main code for articulation point
	//latest graph
	printf("\ngraph for finding articulation point\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",new[i][j]);
		}
	printf("\n");
	}
	//case1-check root
	int counter=0;
	for(i=0;i<n;i++)
	{
		if(new[0][i]==1)
			counter++;
	}
	printf("\n");
	if(counter>=2)
	{
		printf("%d is a articulation point\n",0);
	}
	//case2 and 3
	counter=0;//count backedge
	int count2=0;//count total connection other than backedge
	int counter3;
	for(i=1;i<n;i++)
	{
		counter=0;
		count2=0;
		counter3=0;
		for(j=0;j<n;j++)//check condition3
		{
			if(new[i][j]==1)
			{
				for(k=0;k<index;k++)
				{
					if(j==backpair[k][1] && i==backpair[k][0])
					{
						counter++;
					}				
				}
				count2++;
				
			}
		}
		if((counter>=0 && counter<=index && count2==counter))
		{
		//means no articulation point(that i is leaf node)
		}
		else//check condition2
		{
			for(j=0;j<n;j++)
			{
				if(new[i][j]==1 )
				{
					for(k=0;k<index;k++)
					{
						if(backpair[k][0]==i && backpair[k][1]==j)
						{
							//ignore backedges as they are not child
						}
						else
						{
							if(dfs_low[j][1]>=dfs_num[i][1])
							{
							printf("%d is articulation point\n",i);
							counter3++;
							break;
							}
						}
					}
					if(counter3>0)
						break;
						
				}
			}
		}
	}
	return 0;
}
/*
7
0 1 0 1 1 0 0
1 0 0 0 0 0 1
0 0 0 0 0 1 1
1 0 0 0 0 0 1
1 0 0 0 0 1 0
0 0 1 0 1 0 0
0 1 1 1 0 0 0
7
0 1 0 1 0 0 0
1 0 1 0 0 0 0
0 1 0 1 0 0 1
1 0 1 0 1 1 0
0 0 0 1 0 1 0
0 0 0 1 1 0 0
0 0 1 0 0 0 0


*/
/*
7
0 1 0 1 0 0 0
1 0 1 0 0 0 0
0 1 0 1 0 0 1
1 0 1 0 1 1 0
0 0 0 1 0 1 0
0 0 0 1 1 0 0
0 0 1 0 0 0 0
*/
