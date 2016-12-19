%{
	#include<stdio.h>
    int p=0,s=0;
%}

%%
"printf" {p++;}
"scanf" {s++;}
. ;

%%

int yywrap() {return 1;}

int main(){
	yyin = fopen("inp.c","r");  
	yylex();
	printf("No. of printf=%d \n",p);
	printf("No. of scanf=%d \n",s);
}     
