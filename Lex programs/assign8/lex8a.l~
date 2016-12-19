%{
	#include<stdio.h>
	int c=0;
%}

%%
abb[a-z]*cdd c++;

. ;
%%
int yywrap()
{
	return 1;
}

main()
{
	yyin = fopen("inp.txt", "r");
	yylex();
	printf("Accepted strings=%d\n",c);
}
