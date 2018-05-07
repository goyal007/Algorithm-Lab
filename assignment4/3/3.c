#include<stdio.h>
#include<stdlib.h>		//for random function
void create(int);
int main()
{
	int n;
	printf("enter the value of nodes:\n");
	scanf("%d",&n);
	create(n);
	return 0;
}
void create(int n)
{
	int e,i=1,j;
	e=((n*(n-1))/2);// maximum edges for confirmed
	int edge[e+1][2];
	while(i<=e)
	{
		edge[i][0] = rand()%(n+1);
		edge[i][1] = rand()%(n+1);
		if((edge[i][0]==0||edge[i][1]==0))
		{
			edge[i][0] = rand()%(n+1);
			edge[i][1] = rand()%(n+1);	
		}
        if(edge[i][0] == edge[i][1])
	    	continue;
		for(j=0;j<i;j++)
			if((edge[i][0]==edge[j][0]&&edge[i][1]==edge[j][1])||(edge[i][0]==edge[j][1]&&edge[i][1]==edge[j][0]))
				i--;
		i++;
	}
	printf("Random pairs generate connected graph:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d:",i);
		for(j=1;j<=e;j++)
		{
		 	if(edge[j][0]==i)
		 	{
		 	printf("%d,",edge[j][1]);  	
			}
	    }
	    printf("\n");
	}
}
