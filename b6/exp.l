/*
 
 */

%{
	#include<stdlib.h>
	#include<string.h>
	#include"y.tab.h"
%}

IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
DIGIT [0-9]+|[0-9]*\.[0-9]+

%%

"\n" ;
[ \t]+ ;
{IDENTIFIER}	{ return IDFR;}
{DIGIT}  	{ yylval.value = atof(yytext); return DIGT;}
.		{ return yytext[0];}
%%

int yywrap()
{
	return 1;
}

