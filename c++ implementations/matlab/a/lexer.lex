%option noinput
%option nounput
%option noyywrap
%{
#include<iostream>
#include<vector>
#include"mat.hpp"

#include"parser.tab.hpp"
%}
%%

disp {
	return disp_tok;
}
size {
	return size_tok;
}
(-)?([0-9]|[1-9][0-9]*) {
	yylval.i = atoi(yytext);
	return num_tok;
}
[(),[\];\n-] {
	return *yytext;
}

[ \t] {}

. {
	std::cout << "Greska, nepoznat token: " << *yytext << std::endl;
	exit(EXIT_FAILURE);
}
%%
