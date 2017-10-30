/*
*/
%{
#include "y.tab.h"
%}

DTYPE int|float|double|char|void
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
DIGIT [0-9]+

%%

"\n" ;
[ \t]+ ;
{DTYPE} 	{ return TYPE;}
main		{ return MAIN;}
if		{ return IFST;}
else		{ return ELSE;}
while		{ return WHLE;}
for		{ return FORL;}
{IDENTIFIER}	{ return IDFR;}
{DIGIT}  	{ return DIGT;}
"#include".*	{ return HDFL;}
";" 		{ return DLIM;}
">="|"<="|"<"|">"|"=="|"!="	{ return REOP;} 
"/*"([\n]*|[\t]*|(.)*)+"*/"	{ return CMNT;}
"//".*		{ return CMNT;}
.		{ return yytext[0];}
%%

int yywrap()
{
	return 1;
}

