%{
	#include<stdio.h>
	int c=0;
%}

%%
[\n\t ]+
" and " c++;
" And " c++;
" AND " c++;
" or "  c++;
" Or "  c++;
" OR "  c++;
" but " c++;
" But " c++;
" BUT " c++;

. ;
%%
int yywrap()
{
	return 1;
}

main()
{
	printf("Enter the string and press ^d\n");
	yylex();
	if(c==0)
		printf("\nNot Compound\n");
	else
		printf("\nCompound\n");
	
}
