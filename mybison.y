%{

    #include<stdio.h>
    #include<ctype.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <string.h>
    int yylex();	// use flex to return token 
    void yyerror(char* s);
    extern int yylineno; //line number
    int failed = 0; // if == 0, print the tree; else print error
    int lastLine = -1;//  line number of last error
    extern int failed;
    extern char* yytext;
    extern int lastLine;
    char* print_leaf[37] = {"INT", "FLOAT", "CONST","VOID", "BREAK", "CONTINUE", "RETURN","IF", "ELSE", "WHILE", "INTCON", 
    "FLOATCON", "LT", "LE", "GT", "GE", "EQ", "NE", "ASSIGN", "PLUS", "SUB", "MUL", "DIV", "MOD", "NOT","AND", "OR", "SEMICN", 
     "COMMA", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "LPARENT", "RPARENT", "Ident", "BType"};
     typedef struct Node{
        char* value;
        char* text;
        int line;
        struct Node* sonNodes;
        struct Node* broNodes;
    }Node;
    void my_yyerror(char* str);
    void preHandle(char* text, char* str);
    struct Node* createNode(char* value, char* text, int line, int num, ...);
    void printTree(Node* root, int space);
    void addBroOfSon(Node* root, Node* bro);
%}

%union{
    int const_Int_Val;
    float const_Float_Val;
    char* const_String_Val;
    struct Node* node;
}
%token <node> ASSIGN "="
%token <node> LT "<"
%token <node> LE "<="
%token <node> GT ">"
%token <node> GE ">="
%token <node> EQ "=="
%token <node> NE "!="
%token <node> PLUS "+"
%token <node> SUB "-"
%token <node> MUL "*"
%token <node> DIV "/"
%token <node> MOD "%"
%token <node> NOT "!"
%token <node> SEMICN ";"
%token <node> COMMA  ","
%token <node> LBRACE "{"
%token <node> RBRACE "}"
%token <node> LBRACK "["
%token <node> RBRACK "]"
%token <node> LPARENT "("
%token <node> RPARENT ")"

%token <node> CONST
%token <node> IF
%token <node> ELSE
%token <node> WHILE
%token <node> BREAK
%token <node> RETURN
%token <node>CONTINUE
%token <node> AND
%token <node> OR
%token <node> Ident
%token <node> INT
%token <node> FLOAT
%token <node> VOID
%token <node> INTCON
%token <node> FLOATCON
%token ILLEGAL_OCTAL_CONST
%token ILLEGAL_HEX_CONST
%type <node> Exp Cond PrimaryExp UnaryExp AddExp RelExp EqExp LAndExp LOrExp ConstExp LVal Number MulExp Start CompUnit
%type <node> FuncDef Decl ConstDecl VarDecl BType ConstDef ConstExpGroup ConstInitVal ConstInitValGroup
%type <node> VarDefGroup VarDef ArrayDef InitVal InitValGroup Block FuncFParam FuncFParams Array
%type <node> BlockGroup BlockItem Stmt FuncRParams UnaryOp


%start Start

%%
Start: CompUnit {
    if(failed == 0) printTree($$, 0);
};
CompUnit: FuncDef {$$ = createNode("CompUnit", "", $1->line, 1, $1); }
        | CompUnit FuncDef {$$ = $1; addBroOfSon($1, $2); }
        | Decl {$$ = createNode("CompUnit", "", $1->line, 1, $1); }
        | CompUnit Decl {$$ = $1; addBroOfSon($1, $2); };
Decl: ConstDecl {$$ = createNode("Decl", "", $1->line, 1, $1); }
     |VarDecl {$$ = createNode("Decl", "", $1->line, 1, $1); };
     
ConstDecl: CONST BType ConstDef SEMICN {$$ = createNode("ConstDecl", "", $1->line, 3, $1, $2, $3); }
          |ConstDecl COMMA ConstDef {$$ = createNode("ConstDecl", "", $1->line, 3, $1, $2, $3);};

BType: INT {$$ = createNode("Btype", "", $1->line, 1, $1);}
     | FLOAT {$$ = createNode("Btype", "", $1->line, 1, $1);}
     | VOID {$$ = createNode("Btype", "", $1->line, 1, $1);};
ConstDef: Ident ConstExpGroup ASSIGN ConstInitVal {$$ = createNode("ConstDef", "", $1->line, 4, $1, $2, $3, $4);}
    | Ident ASSIGN ConstInitVal {$$ = createNode("ConstDef", "", $1->line, 3, $1, $2, $3);};

ConstExpGroup: LBRACK ConstExp RBRACK 
    | ConstExpGroup LBRACK ConstExp RBRACK {$$ = $1; addBroOfSon($1, $2); addBroOfSon($1, $3); addBroOfSon($1, $4); };
ConstInitVal : ConstExp {$$ = createNode("ConstInitVal", "", $1->line, 1, $1); }
    | LBRACE RBRACE {$$ = createNode("ConstInitVal", "", $1->line, 2, $1, $2);}
    | LBRACE ConstInitValGroup RBRACE {$$ = createNode("ConstInitVal", "", $1->line, 3, $1, $2, $3);};
ConstInitValGroup: ConstInitVal 
    | ConstInitValGroup COMMA ConstInitVal {$$ = $1; addBroOfSon($1, $2); addBroOfSon($1, $3);};

VarDecl : BType VarDefGroup SEMICN {$$ = createNode("VarDecl", "", $1->line, 3, $1, $2, $3);}
    | BType VarDefGroup error { my_yyerror("Missing \";\"\n");};
VarDefGroup: VarDef 
    | VarDefGroup COMMA VarDef {$$ = $1; addBroOfSon($1, $2); addBroOfSon($1, $3); };

VarDef : Ident {$$ = createNode("VarDef", "", $1->line, 1, $1); }
    | Ident ASSIGN InitVal {$$ = createNode("VarDef", "", $1->line, 3, $1, $2, $3);}
    | Ident LBRACK ConstExp error {$$ = createNode("ArrayVarDef", "", $1->line, 2, $1, $3); my_yyerror("Missing \"]\"\n");}
    | Ident ArrayDef {$$ = createNode("VarDef", "", $1->line, 2, $1, $2);}
    | Ident LBRACK error RBRACK {$$ = createNode("ArrayVarDef", "", $1->line, 2, $1, $4); my_yyerror("Missing expression inside \"[]\"\n");}
    | Ident ArrayDef ASSIGN InitVal {$$ = createNode("VarDef", "", $1->line, 4, $1, $2, $3, $4);};
ArrayDef: LBRACK ConstExp RBRACK 
    | ArrayDef LBRACK ConstExp RBRACK {$$ = $1, addBroOfSon($1, $2); addBroOfSon($1, $3); addBroOfSon($1, $4);};;

InitVal : Exp {$$ = createNode("InitVal", "", $1->line, 1, $1); }
    | LBRACE RBRACE {$$ = createNode("InitVal", "", $1->line, 2, $1, $2);}
    | LBRACE InitValGroup RBRACE {$$ = createNode("InitVal", "", $1->line, 3, $1, $2, $3);};

InitValGroup: InitVal 
    | InitValGroup COMMA InitVal {$$ = $1; addBroOfSon($1, $2); addBroOfSon($1, $3); };

FuncDef : BType Ident LPARENT RPARENT Block {$$ = createNode("FuncDef", "", $1->line, 5, $1, $2,$3,$4,$5);}
    | BType Ident LPARENT FuncFParams RPARENT Block {$$ = createNode("FuncDef", "", $1->line, 6, $1,$2,$3,$4,$5,$6);};
FuncFParams : FuncFParam {$$ = createNode("FuncFParams", "", $1->line, 1, $1);}
    | FuncFParams COMMA FuncFParam {$$ = $1, addBroOfSon($1, $2); addBroOfSon($1, $3);};

FuncFParam: BType Ident {$$ = createNode("FuncFParam", "", $1->line, 2, $1,$2);}
    | BType Ident LBRACK RBRACK {$$ = createNode("FuncFParam", "", $1->line, 4, $1,$2,$3,$4);}
    | BType Ident LBRACK RBRACK Array {$$ = createNode("FuncFParam", "", $1->line, 5, $1,$2,$3,$4,$5);};
Array: LBRACK Exp RBRACK 
    | Array LBRACK Exp RBRACK {$$ = $1, addBroOfSon($1, $2); addBroOfSon($1, $3); addBroOfSon($1, $4); }
    | LBRACK error RBRACK{ my_yyerror("Missing  \"]\"\n");}
    | Array Exp error RBRACK{ my_yyerror("Missing  \"]\"\n");}
    | Array LBRACK error RBRACK{ my_yyerror("Invalid array expression: use ',' insteadof']'\n");
                                $$=$1;addBroOfSon($1,$2);
                                };
Block : LBRACE RBRACE {$$ = createNode("Block", "", $1->line, 2, $1,$2);}
    | LBRACE BlockGroup RBRACE {$$ = createNode("Block", "", $1->line, 3, $1,$2,$3);};
BlockGroup: BlockItem 
    | BlockGroup BlockItem {$$ = $1; addBroOfSon($1, $2); };
BlockItem : Decl {$$ = createNode("BlockItem", "", $1->line, 1, $1);}
    | Stmt {$$ = createNode("BlockItem", "", $1->line, 1, $1);};
Stmt :  LVal ASSIGN Exp SEMICN {$$ = createNode("Stmt", "", $1->line, 4, $1,$2,$3,$4);}
	| SEMICN  {$$ = createNode("Stmt", "", $1->line, 1, $1);}
	| Exp SEMICN {$$ = createNode("Stmt", "", $1->line, 2, $1,$2);}
	| Block {$$ = createNode("Stmt", "", $1->line, 1, $1);}
	| IF LPARENT Cond RPARENT Stmt {$$ = createNode("Stmt", "", $1->line, 5, $1,$2,$3,$4,$5);}
	| IF LPARENT Cond RPARENT Stmt ELSE Stmt {$$ = createNode("Stmt", "", $1->line, 7, $1,$2,$3,$4,$5,$6,$7);}
	| WHILE LPARENT Cond RPARENT Stmt {$$ = createNode("Stmt", "", $1->line, 5, $1,$2,$3,$4,$5);}
	| BREAK SEMICN {$$ = createNode("Stmt", "", $1->line, 2, $1,$2);}
	| CONTINUE SEMICN {$$ = createNode("Stmt", "", $1->line, 2, $1,$2);}
	| RETURN SEMICN {$$ = createNode("Stmt", "", $1->line, 2, $1,$2);}
	| RETURN Exp SEMICN {$$ = createNode("Stmt", "", $1->line, 3, $1,$2,$3);}
	| Exp error {my_yyerror("Missing  \";\"\n");}
	| Block error {my_yyerror("Missing  \";\"\n");}
	| LVal ASSIGN Exp error {my_yyerror("Missing  \";\"\n");}
	| BREAK error {my_yyerror("Missing  \";\"\n");}
	| RETURN Exp error {my_yyerror("Missing  \";\"\n");}
	| CONTINUE error {my_yyerror("Missing  \";\"\n");}
	| RETURN error {my_yyerror("Missing  \";\"\n");};
Exp : AddExp {$$ = createNode("Exp", "", $1->line, 1, $1); };
Cond : LOrExp {$$ = createNode("Cond", "", $1->line, 1, $1); };
LVal : Ident {$$ = createNode("LVal", "", $1->line, 1, $1);}
    | Ident Array {$$ = $1; addBroOfSon($1, $2); };
PrimaryExp : LPARENT Exp RPARENT {$$ = createNode("PrimaryExp", "", $1->line, 3, $1,$2,$3);}
           | LVal 	 {$$ = createNode("PrimaryExp", "", $1->line, 1, $1);}
           | Number	 {$$ = createNode("PrimaryExp", "", $1->line, 1, $1);};
Number : INTCON {$$ = createNode("Number", "", $1->line, 1, $1);}
       | FLOATCON {$$ = createNode("Number", "", $1->line, 1, $1);}
       | ILLEGAL_HEX_CONST {}
       | ILLEGAL_OCTAL_CONST {};
UnaryExp : PrimaryExp 
         | Ident LPARENT RPARENT 
         | Ident LPARENT FuncRParams RPARENT 
         | UnaryOp UnaryExp ;
UnaryOp : PLUS {$$ = createNode("UnaryOp", "", $1->line, 1, $1);}
        | SUB {$$ = createNode("UnaryOp", "", $1->line, 1, $1);}
        | NOT {$$ = createNode("UnaryOp", "", $1->line, 1, $1);};
FuncRParams : Exp {$$ = createNode("FuncRParams", "", $1->line, 1, $1);}
    	| FuncRParams COMMA Exp {$$ = $1, addBroOfSon($1, $2); addBroOfSon($1, $3); }; 
MulExp : UnaryExp { $$ = createNode("MulExp", "", $1->line, 1, $1);}
       | MulExp MUL UnaryExp {$$ = createNode("MulExp", "", $1->line, 3, $1,$2,$3);}
       | MulExp DIV UnaryExp {$$ = createNode("MulExp", "", $1->line, 3, $1,$2,$3);}
       | MulExp MOD UnaryExp {$$ = createNode("MulExp", "", $1->line, 3, $1,$2,$3);};
AddExp : MulExp {$$ = createNode("AddExp", "", $1->line, 1, $1);}
       | AddExp PLUS MulExp {$$ = createNode("AddExp", "", $1->line, 3, $1,$2,$3);}
       | AddExp SUB MulExp {$$ = createNode("AddExp", "", $1->line, 3, $1,$2,$3);};
RelExp : AddExp {$$ = createNode("RelExp", "", $1->line, 1, $1);}
       | RelExp LT AddExp {$$ = createNode("RelExp", "", $1->line, 3, $1,$2,$3);}
       |RelExp GT AddExp {$$ = createNode("RelExp", "", $1->line, 3, $1,$2,$3);}
       |RelExp LE AddExp {$$ = createNode("RelExp", "", $1->line, 3, $1,$2,$3);}
       |RelExp GE AddExp {$$ = createNode("RelExp", "", $1->line, 3, $1,$2,$3);};
EqExp : RelExp {$$ = createNode("EqExp", "", $1->line, 1, $1);}
    | EqExp EQ RelExp {$$ = createNode("EqExp", "", $1->line, 3, $1,$2,$3);}
    | EqExp NE RelExp {$$ = createNode("EqExp", "", $1->line, 3, $1,$2,$3);} ;
LAndExp : EqExp {$$ = createNode("LAndExp", "", $1->line, 1, $1);}
    | LAndExp AND EqExp {$$ = createNode("LAndExp", "", $1->line, 3, $1,$2,$3);};
LOrExp : LAndExp {$$ = createNode("LOrExp", "", $1->line, 1, $1);}
    | LOrExp OR LAndExp {$$ = createNode("LOrExp", "", $1->line, 3, $1,$2,$3);};
ConstExp : AddExp {$$ = createNode("ConstExp", "", $1->line, 1, $1);};

%%

void my_yyerror(char* str){
    failed = 1;
    if(lastLine != yylineno){
        printf("\033[1;31mError Type B at Line %d : %s\033[0m", yylineno, str);
        lastLine = yylineno;
    }

}

void yyerror(char *str){
    return;
}

struct Node* createNode(char* value, char* text, int line, int num, ...){
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->text = text;
    node->line = line;
    node->sonNodes = NULL;
    node->broNodes = NULL;
    int i;
    va_list args;
    va_start(args, num);
    for(i = 0; i < num; i++){
        Node* firstSon;
        Node* son;
        son = va_arg(args, Node*);
        if(i == 0){
            firstSon = son;
            node->sonNodes = son;
        }
        else{
            firstSon->broNodes = son;
            firstSon = son;
        }
    }
    va_end(args);
    return node;
}

void printTree(Node* root, int space){
    int i;
    for(i = 0; i < space; i++){
        printf("  ");
    }
    int flag = 0;
    for(i = 0; i < 37; i++){
        if(strcmp(root->value, print_leaf[i]) == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        if(strcmp(root->value, "INTCON") == 0 || strcmp(root->value, "FLOATCON") == 0){
			char str[20];
			preHandle(root->text,str);
			printf("\033[1;32m%s:\033[0m %s\n", root->value, str);
			
	}else if(strcmp(root->value, "INT") == 0 || strcmp(root->value, "FLOAT") == 0){
			printf("\033[1;32mType:\033[0m %s\n", root->value);
	}else if(strcmp(root->value, "Ident") == 0){ 
			printf("\033[1;32mIdent:\033[0m %s\n", root->text);
	}else if(strcmp(root->value, "PLUS") == 0 || strcmp(root->value, "SUB") == 0 || strcmp(root->value, "MUL") == 0 || strcmp(root->value, "DIV") == 0 || strcmp(root->value, "MOD") == 0 ){
			printf("\033[1;32m%s:\033[0m %s\n", root->value, root->text);
	}else{
			printf("\033[1;35m%s\033[0m\n", root->value);
		}
    }else {
	printf("\033[1;35m%s\033[0m (%d)\n", root->value, root->line); 
    }
    Node* son;
    Node* bro;
    son = root->sonNodes;
    if(son != NULL){
        printTree(son, space+1);
        bro = son->broNodes;
        while(bro != NULL){
            printTree(bro, space+1);
            bro = bro->broNodes;
        }
    }
    free(root);
}

void addBroOfSon(Node* root, Node* bro){
	Node* p;
	p = root->sonNodes;
	if(p == NULL){
		root->sonNodes = bro;
		return;
	}
	while(p != NULL && p->broNodes != NULL){
		p = p->broNodes;
	}
	if(p != NULL){
		p->broNodes = bro;
	}
}

void preHandle(char* text, char* str){
	const char* prefixHex = "0x";
	const char* prefixOctal = "0";
	char* endptr;
	char decimalStr[20];
	// 如果是十六进制
	if(strncmp(text, prefixHex, strlen(prefixHex)) == 0){
		long int decimal = strtol(text+2, &endptr, 16);
		sprintf(decimalStr, "%ld", decimal);
	}else if(strncmp(text, prefixOctal, strlen(prefixOctal)) == 0){
		long int decimal = strtol(text+1, &endptr, 8);
		sprintf(decimalStr, "%ld", decimal);
	}else{
		strcpy(decimalStr, text);
	}
	strcpy(str, decimalStr);
}

int main(int argc, char** argv){
    yylineno = 1;
    extern FILE* yyin;
    if(argc == 2){
        if((yyin = fopen(argv[1], "r")) == NULL){
            printf("Can't open file %s\n", argv[1]);
            return 1;
        }
    }
    yyparse();

	fclose(yyin);
    return 0;
}

