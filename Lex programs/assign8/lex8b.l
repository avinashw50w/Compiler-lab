%{
	#include<stdio.h>
	int c=0;
%}

%%
[a-z]*(ab)+[a-z]* c++;
. ;
%%
int yywrap()
{
	return 1;
}

main()
{
	yyin = fopen("inp1.txt","r");
	yylex();
	if (c) {
		printf("ACCEPTED :\n");
		printf("No of ab : %d\n", c);
		}
	else
		printf("NOT ACCEPTED\n");
}
