// kmp algorithm
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp=fopen("2.txt","r");
	int i=1,j=0,c=0,x;
	char test[1000],pattern[1000];
	while(!feof(fp))
	{
		fscanf(fp,"%s\n",test);
		fscanf(fp,"%s\n",pattern);
	}
	int l1=strlen(test);
	int l2=strlen(pattern);
	//printf("%s\n%s",test,pattern);
	int arr[l2];
	arr[0]=0;
	//find lcs(longest proper prefix which is also suffix) array
	while(i<l2)
	{
		if(pattern[i]==pattern[j])
		{
			arr[i]=j+1;
			i++;
			j++; 
		}
		else
		{
			if(j!=0)
			{
				j=arr[j-1];
			}
			else
			{
				arr[i]=0;
				i++;
			}
		}
	}
	/*for(i=0;i<l2;i++)		//print lcs pattern
	{
		printf("%d ",arr[i]);
	}*/
	//find match of pattern in test
	j=0;
	i=0;
	while(i<l1)
	{
		if(test[i]==pattern[j])
		{
			i++;
			j++;
		}
		else if(i<l1 && pattern[j]!=test[i])
		{
			if(j!=0)
				j=arr[j-1];
			else
				i=i+1;
		}
		if(j==l2)
		{
			printf("shift-%d\n",i-j);
			j=arr[j-1];
		}
	}
	return 0;
}
