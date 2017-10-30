/*
 
 */

%{
#include<stdio.h>
extern FILE *yyin;
%}

%start pgm
%token TYPE MAIN DLIM KEYW IDFR DIGT HDFL CMNT IFST REOP WHLE FORL ELSE
%left '*' '/'
%left '+' '-'
%%

pgm: HDFL TYPE MAIN '(' ')' '{' stmtlist '}'			{ printf("Valid program\n");}
;
stmtlist: stmt stmtlist |
;
stmt: astmt | ifst | while | for
;
astmt: IDFR '=' exp DLIM					{ printf("Assignment\n");}
;
asmt: IDFR '=' exp					{ printf("Assignment\n");}
;
exp: exp '*' exp | exp '/' exp | exp '+' exp | exp '-' exp | IDFR | DIGT
;
ifst: 	IFST '(' con ')' '{' stmtlist '}' { printf("If\n");} | IFST '(' con ')' '{' stmtlist '}' ELSE '{' stmtlist '}' { printf("If-Else block\n");}
;
while: WHLE '(' con ')' '{' stmtlist '}'			{ printf("While\n");}
;
for: FORL '(' asmt DLIM con DLIM asmt ')' '{' stmtlist '}'	{ printf("For\n");}
;
con: IDFR REOP DIGT | IDFR REOP IDFR
%%

void main(int argc, char ** argv)
{	 
	yyin=fopen(argv[1],"r");   	
	yyparse();  	
}
void yyerror()
{
   printf("Program is Invalid\n");  
}




