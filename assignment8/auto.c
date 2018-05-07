#include<stdio.h>
#include<string.h>
#define character 256
int tablecomplete(char *pattern,int lenp,int st, int x);
void Tablefill(char *pattern,int lenp,int Table[][character]);
void find(char *pattern, char *text);
int main()
{
	FILE *fp=fopen("2.txt","r");
	char text[100],pattern[100];
	fscanf(fp,"%s\n",text);
	fscanf(fp,"%s\n",pattern);
    find(pattern, text);
    return 0;
}
int tablecomplete(char *pattern,int lenp,int st, int x)
{
    if (st<lenp && x==pattern[st])	//character match(ascii) with pattern then state++ in corresponding column of character(256)//st=state
    {
        return st+1;
    }
    int lps,i;//lps=longest prefix suufix
    for (lps=st;lps>0;lps--)	// lps longest prefix which is also suffix
    {
        if (pattern[lps-1] == x)//comapre ascii value 
        {
            for (i=0;i<lps-1;i++)
            {
                if (pattern[i]!=pattern[st-lps+1+i])	//+1 to remove one character from right side of the prefix suffix equation;
                										//example ababa,then abab=bab(a,b) here skip a in rhs
                {										//state-lps length for mismatch so that rhs start away from equal sign(see by example)
                    break;
                }
            }
            if (i==lps-1)	//if lhs=rhs then return lps
            {
                return lps;
            }
        }
    }
    return 0;
}
void Tablefill(char *pattern,int lenp,int Table[][character])//for filling table
{
    int st, index;
    for (st = 0; st <= lenp; st++)
    {
        for (index= 0; index <character; index++)
        {
            Table[st][index] = tablecomplete(pattern, lenp, st, index);//here table is being filled using Tablecomplete function
        }
    }
}
void find(char *pattern,char *text)
{
    int lenp = strlen(pattern);
    int lent = strlen(text);
    int Table[lenp+1][character];//2d array of no of states=pattenlength+1 and 256 charcters
    Tablefill(pattern, lenp, Table);
    int i, st=0;
    for (i = 0; i < lent; i++)
    {
        st = Table[st][text[i]];//go to state according to match state and text input
        if (st == lenp)	//if reach final state then string accepted
        {
            printf ("\n Pattern found at index %d",i-lenp+1);
        }
    }
}
//finite automata string match
