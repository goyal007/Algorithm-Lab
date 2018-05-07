#include<stdio.h>
#include"argum.h"
int main()
{
	char a[50],b[50];
	FILE *fp=fopen("lcs.txt","r");
	fscanf(fp,"%s\n",a);
	fscanf(fp,"%s\n",b);
	printf("input strings are\n%s\n%s\n\n",a,b);
	func(a,b);
	fclose(fp);
	return 0;
}
