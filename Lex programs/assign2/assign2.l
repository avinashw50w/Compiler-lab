%{ 
     #include<stdio.h>
     int posi=0,negi=0,posf=0,negf=0;
 %}
 
 %%
 -[0-9]+ {negi++;}
 \+?[0-9]+ {posi++;}
 -[0-9]*\.[0-9]+ {negf++;}
 \+?[0-9]*\.[0-9]+ {posf++;}
 . ;
 %%

int yywrap() { return 1; }

int main(){
   
   printf("Enter the numbers and then press ^d in the end\n");
 
   yylex();
 
   printf("no. of positive integer %d \n",posi);
   printf("no. of negative integer %d \n",negi);
   printf("no. of positive fraction %d \n",posf);
   printf("no. of negative fraction %d \n",negf);
 }
 
 
