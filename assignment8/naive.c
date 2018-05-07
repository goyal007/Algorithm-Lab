//brute force method
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp=fopen("2.txt","r");
	int i=0,j=0,c=0,x;
	char test[1000],pattern[1000];
	while(!feof(fp))
	{
		fscanf(fp,"%s\n",test);
		fscanf(fp,"%s\n",pattern);
	}
	int l1=strlen(test);
	int l2=strlen(pattern);
	while(i<l1)
	{
		
		if(test[i]==pattern[0])
		{
			c=0;
			x=i;
			int q=i;
			for(j=1;j<l2;j++)
			{
				if(test[q+1]==pattern[j])
				{
					q++;
					c++;
				}
			}
			if(c==l2-1)
			{
				printf("shift-%d\n",x);
			}
		}
		i++;
	}
	return 0;
}
//SampleTestProgramTestTesTesttestTestTsetTest
//Test

