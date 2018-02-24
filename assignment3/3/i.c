#include<stdio.h>
void high_card(int *b1,int *c1)
{
	int i;
	for(i=4;i>=0;i--)
	{
		if(b1[i]>c1[i])
		{
			printf("Black wins\n");
			return ;
		}
		else if(b1[i]<c1[i])
		{
			printf("White wins\n");
			return ;
		}
	}
	printf("Tie\n");
	return ;
}
