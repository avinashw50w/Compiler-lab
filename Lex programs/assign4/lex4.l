%{
	#include<stdio.h>
    int p=0,s=0;
%}
%%
"printf"             {p++;fprintf(yyout,"%s","write");}
"scanf"              {s++;fprintf(yyout,"%s","read");}
%%

int yywrap() {return 1;}

int main(void)
{
	yyin=fopen("inp.c","r");
	yyout=fopen("out.c","w");
	yylex();
	printf("No. of scanf=%d\n",s);
	printf("No. of printf=%d\n",p);
}
