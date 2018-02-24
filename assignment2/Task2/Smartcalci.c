#include<stdio.h>
#include"base.h"
#include"number.h"
#include<string.h>
int main(int argc,char **argv)
{
	char *a1,*a2;
	FILE *p1;
	p1=fopen(argv[1],"r");
	int i,j,maxd,b1,b2;
	char ch[100],temp[10],c1[20],c2[20];
	maxd=initializebase(p1,ch);
	fclose(p1);
	p1=fopen(argv[2],"r");
	while(!feof(p1))
	{
		int a,b,c,d,l1,l2;
		fscanf(p1,"%s\n",temp);	
		fscanf(p1,"%d",&a);//base of num1
		fscanf(p1,"%s\n",c1);
		fscanf(p1,"%d",&b);
		fscanf(p1,"%s\n",c2);
		l1=strlen(c1);
		l2=strlen(c2);
		b1=createnumber(c1,l1,a,ch);//decimal base
		b2=createnumber(c2,l2,b,ch);
		if(temp[0]=='a'&&temp[1]=='d'&&temp[2]=='d')
			add(b1,b2,a,b,ch);
		else
			subtract(b1,b2,a,b,ch);
		printf("\n");
	}
	fclose(p1);
}
