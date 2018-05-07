#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp=fopen("2.txt","r");
	char text[100],pattern[100];
	fscanf(fp,"%s\n",text);
	fscanf(fp,"%s\n",pattern);
	int len1=strlen(text);
	int len2=strlen(pattern);
	printf("enter prime number\n");
	int q,i,j;//q is a prime
	int h=1;
	int d=256;//d is the number of characters in input alphabet
	scanf("%d",&q);
	printf("text::%s\npattern::%s\n",text,pattern);
	for(i=0;i<len2-1;i++)//calculation of h//to remove integer overflow we use mod q
	{
		h=(h*d)%q;	//d to power m-1
	}
	int pat=0;//hash of pattern
	int tes=0;//hash of text
	for(i=0;i<len2;i++)
	{
		pat=(d*pat+pattern[i])%q;			//hash of pattern
		tes=(d*tes+text[i])%q;			//hash of first text
	}
	for(i=0;i<=len1-len2;i++)
	{
		if(pat==tes)
		{	
			for(j=0;j<len2;j++)
			{
				if(text[i+j]!=pattern[j])
				{
					printf("spurious hit occurs at shift->%d\n",i);
					break;
				}
			}
			if(len2==j)
				printf("shift-> %d\n",i);
		}
		//use previous hash to calculate new hash
		if(i<len1-len2)
		{
			tes=(d*(tes-text[i]*h)+text[i+len2])%q;
			if(tes<0)
				tes=(tes+q);////////-ve modulo====[q-(-ve number)%q]
		}
	}
	return 0;
}
