%{
	#include<stdio.h>
	int identifier=0,digits=0,others=0;
%}

%%

[a-zA-Z]+[0-9]* identifier++;
[0-9]*  digits++;
[0-9]+[a-z]+  others++;
. ;

%%

int yywrap()
{
	return 1;
}

main()
{
	yyin=fopen("inp.c","r");
	yylex();
	printf("number of identifiers = %d\n",identifier);
	printf("number of strings which are neither identifier nor integer = %d\n",others);
	printf("number of integers = %d\n",digits);
}
