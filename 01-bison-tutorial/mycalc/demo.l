%{
#include <stdlib.h>
#include "demo.tab.h"
%}

%%

[a-zA-Z]          {yylval.name = yytext[0]; return ID;}

[0-9]+\.?[0-9]+    {yylval.val = atof(yytext); return NUM;}

[\+\-\*/=]        {return yytext[0];}

\n                {return yytext[0];}

"print"           {return PRINT;}

"exit"            {return EXIT;}

[ \t]             {}

%%

int yywrap() {return 1;}