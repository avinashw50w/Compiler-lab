%{
	#include<stdio.h>
    int s=0,c=0,l=0,w=0;
%}
%%
[^ \t\n]+ {w++;c+=yyleng;}
" " 		 {s++;c++;}
\n 		 {l++;c++;}
. 			 {c++;}

%%

int yywrap()
{
	return 1;
}     


main()
{
	yyin=fopen("inp.txt","r");
    yylex();
    printf("No. of Space=%d\n",s);
    printf("No. of Words=%d\n",w);
    printf("No. of Lines=%d\n",l);
    printf("No. of Chars=%d\n",c);
}
