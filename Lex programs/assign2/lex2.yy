%{
	#include<stdio.h>
	int pi=0;
	int ni=0;
	int fp=0;
	int fn=0;
%}

DIGIT[0-9]

%%
\+?{DIGIT}+ pi++;

-{DIGIT}+ ni++;

\+?{DIGIT}*\.{DIGIT}+ fp++;

-{DIGIT}*\.{DIGIT}+ fn++;

. ;
%%

int yywrap()
{
	return 1;
}

main()
{
	printf("Enter the Numbers and in the end press ^d\n");
	yylex();
	printf("positive integers: %d \n",pi);
	printf("negetive integers: %d \n",ni);
	printf("fractional positive integers: %d \n",fp);
	printf("fractional negetive integers: %d \n",fn);
}
