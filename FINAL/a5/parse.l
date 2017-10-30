%{
#include "y.tab.h"
#include<string.h>
#include<stdlib.h>
%}

%%
[ \t\n]+ ;
"++" {return INCOP;}
main {return MAIN;}
"(" {return OB;}
")" {return CB;}
"{" {return OCB;}
"}" {return CCB;}
for {return FOR;}
while {return WHILE;}
if {return IF;}
else {return ELSE;}
int {yylval.string=strdup(yytext);return TYPE;}
float {yylval.string=strdup(yytext); return TYPE;}
[a-zA-Z][a-zA-Z0-9]* {yylval.string=strdup(yytext); return ID;}
"<"|">"|"<="|">="|"==" {return REOP;}

[0-9]+ {yylval.num=atoi(yytext); return NUMBER;}
. {return yytext[0];}
%%


int yywrap()
{
return 1;
}

