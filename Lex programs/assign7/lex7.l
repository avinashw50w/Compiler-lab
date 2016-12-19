%{
	#include<stdio.h>
    int c=0;
%}

%%
"//"[a-zA-Z\t/]*         {c++;}
"/*"[a-zA-Z\t\n ]*"*/"$   {c++;}
%% 
 
int yywrap()
{
	return 1;
}       
main()
{
   yyin = fopen("inp.c","r");
	yyout = fopen("out.c","w");
   yylex();
   printf("No of comment lines=%d\n",c);
    
   
}
