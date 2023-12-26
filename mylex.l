%option yylineno
%{
#include"mybison.tab.h"
#include <stdio.h>
#include <string.h>
#define YYSTYPE Struct Node*
struct Node* createNode(char* value, char* text, int line, int num, ...);
extern int failed;
%}

INTCON [1-9][0-9]*|0[0-7]*|(0x|0X)[0-9a-fA-F]*
FLOATCON [0-9]+[Ee][0-9]+
id [a-zA-Z_][a-zA-Z0-9_]*
LETTER              [A-Za-z]
DIGIT               [0-9]
ILLEGAL_OCTAL_CONST 0[0-9a-wy-zA-WY-Z]({LETTER}|{DIGIT})*
HEX_PREFIX          0x|0X
ILLEGAL_HEX_CONST   {HEX_PREFIX}({LETTER}|{DIGIT})*

COMMENT1            "/*"(.*|(.*\n.*)+)"*/"
COMMENT2            "//".*\n
%%

{COMMENT1}              { }
{COMMENT2}              { }
[ \t]					{;}		//忽略空白符
"int"					{yylval.node = createNode("INT", "int", yylineno, 0); return (INT);}
"float"					{ yylval.node = createNode("FLOAT", "float", yylineno, 0); return (FLOAT);}
"const"                 {yylval.node = createNode("CONST", "const", yylineno, 0);return (CONST);}
"void"                	{yylval.node = createNode("VOID", "void", yylineno, 0);return (VOID);}
"break"					{yylval.node = createNode("BREAK", "break", yylineno, 0);return (BREAK);}
"continue"				{yylval.node = createNode("CONTINUE", "continue", yylineno, 0);return (CONTINUE);}
"return"				{yylval.node = createNode("RETURN", "return", yylineno, 0);return (RETURN);}
"if" 					{yylval.node = createNode("IF", "if", yylineno, 0);return (IF);}
"else" 					{yylval.node = createNode("ELSE", "else", yylineno, 0);return (ELSE);}
"while" 				{yylval.node = createNode("WHILE", "while", yylineno, 0);return (WHILE);}
{INTCON}				{yylval.node = createNode("INTCON", strdup(yytext), yylineno, 0); return (INTCON);}
{FLOATCON}				{yylval.node = createNode("FLOATCON", strdup(yytext), yylineno, 0);return (FLOATCON);}
"<"					{yylval.node = createNode("LT", "<", yylineno, 0);return (LT);}
"<="				{yylval.node = createNode("LE", "<=", yylineno, 0);return (LE);}
">"					{yylval.node = createNode("GT", ">", yylineno, 0);return (GT);}
">="				{yylval.node = createNode("GE", ">=", yylineno, 0);return (GE);}
"=="				{yylval.node = createNode("EQ", "==", yylineno, 0);return (EQ);}
"!="				{yylval.node = createNode("NE", "!=", yylineno, 0);return (NE);}
"="					{yylval.node = createNode("ASSIGN", "=", yylineno, 0);return (ASSIGN);}
"+"					{yylval.node = createNode("PLUS", "+", yylineno, 0);return (PLUS);}
"-"					{yylval.node = createNode("SUB", "-", yylineno, 0);return (SUB);}
"*"					{yylval.node = createNode("MUL", "*", yylineno, 0);return (MUL);}
"/"					{yylval.node = createNode("DIV", "/", yylineno, 0);return (DIV);}
"%"					{yylval.node = createNode("MOD", "%", yylineno, 0);return (MOD);}
"!"					{yylval.node = createNode("NOT", "!", yylineno, 0);return (NOT);}
"&&"				{yylval.node = createNode("AND", "&&", yylineno, 0);return (AND);}
"||"				{yylval.node = createNode("OR", "||", yylineno, 0);return (OR);}
";"					{yylval.node = createNode("SEMICN", ";", yylineno, 0);return (SEMICN);}
","					{yylval.node = createNode("COMMA", ",", yylineno, 0);return (COMMA);}
"("					{yylval.node = createNode("LPARENT", "(", yylineno, 0);return (LPARENT);}
")"					{yylval.node = createNode("RPARENT", ")", yylineno, 0);return (RPARENT);}
"{"					{yylval.node = createNode("LBRACE", "{", yylineno, 0);return (LBRACE);}
"}"					{yylval.node = createNode("RBRACE", "}", yylineno, 0);return (RBRACE);}
"["					{yylval.node = createNode("LBRACK", "[", yylineno, 0);return (LBRACK);}
"]"					{yylval.node = createNode("RBRACK", "]", yylineno, 0);return (RBRACK);}
{ILLEGAL_OCTAL_CONST} {fprintf(yyout, "\033[1;31mERROR TYPE A at Line %d: Illegal  octal number \'%s\'\033[0m\n", yylineno, yytext); failed = 1; return (ILLEGAL_OCTAL_CONST);}
{ILLEGAL_HEX_CONST}  {fprintf(yyout, "\033[1;31mERROR TYPE A at Line %d: Illegal hexadecimal number \'%s\'\033[0m\n", yylineno, yytext); failed = 1; return (ILLEGAL_HEX_CONST);}
{id}				{char* lexeme = strdup(yytext); yylval.node = createNode("Ident", lexeme, yylineno, 0);
                        return (Ident);}
"\n"                {}
{DIGIT}+{LETTER}*   {fprintf(yyout, "\033[1;31mERROR TYPE A at Line %d: Illegal character    \'%s\'\033[0m\n", yylineno, yytext); return(Ident);}
.                   {fprintf(yyout, "\033[1;31mERROR TYPE A at Line %d: Invalid character \'%s\'\033[0m\n", yylineno, yytext); failed  = 1;}

%%
int yywrap(){    //文件结束处理函数，如果返回值为1就停止解析。可以用来解析多个文件。
    return 1;
}

/*int main (int argc, char** argv){
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if(yyin == NULL) {
            fprintf(yyout, "Failed to open file %s\n", argv[1]);
            return 1;
        }
        if (argc > 2) yyout = fopen(argv[2], "w");
    }

    yylex();

	if(argc > 1) {
		fclose(yyin);
		if(argc > 2) fclose(yyout);
	}

	return 0;
}*/
