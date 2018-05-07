#include<stdio.h>
#include"argum.h"
int main()
{
	char a[50],b[50],c[50];
	FILE *fp=fopen("file.txt","r");
	fscanf(fp,"%s\n",a);
	fscanf(fp,"%s\n",b);
	fscanf(fp,"%s\n",c);
	printf("input strings are\n%s\n%s\n%s\n\n",a,b,c);
	func(a,b,c);
	fclose(fp);
	return 0;
}
