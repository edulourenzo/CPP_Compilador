#include <bits/stdc++.h>

using namespace std;

#define MAX_STATES 23
#define MAX_CHAR_CLASSES 23

int sigma[MAX_STATES][MAX_CHAR_CLASSES] = {
////// 00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
////// \t, \n, SP, "", ((, )), **, ++, --, .., //, 09, ;;, <<, ==, >>, Az, EE, __, {{, }}, EF, OO,
/*00*/  0,  0,  0,  7, 19, 20, 18, 18, 18, 22, 18,  1, 21, 13, 15, 14,  9,  9, 22, 10, 22, 12, 22,
/*01*/  1,  1,  1, 22, 22,  0,  0,  0,  0,  2,  0,  1,  0,  0,  0,  0, 22,  4, 22,  0, 22, 22,  0,
/*02*/  2,  2,  2, 22, 22, 22, 22, 22, 22, 22, 22,  3, 22, 22, 22, 22, 22, 22, 22,  0, 22, 22,  0,
/*03*/  3,  3,  3, 22, 22,  0,  0,  0,  0, 22,  0,  3,  0,  0,  0,  0, 22,  4, 22,  0, 22, 22,  0,
/*04*/  4,  4,  4, 22, 22, 22, 22,  5,  5, 22, 22,  6, 22, 22, 22, 22, 22, 22, 22,  0, 22, 22,  0,
/*05*/  5,  5,  5, 22, 22, 22, 22, 22, 22, 22, 22,  6, 22, 22, 22, 22, 22, 22, 22,  0, 22, 22,  0,
/*06*/  6,  6,  6, 22, 22,  0,  0,  0,  0, 22,  0,  6,  0,  0,  0,  0, 22, 22, 22,  0, 22, 22,  0,
/*07*/  7,  7,  7,  8,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 22,  7,
/*08*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*09*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  0,  9,  9,  9,  0, 22,  0,  0,
/*10*/ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 22, 10,
/*11*/  0,  0,  0,  0,  0, 22, 22, 22, 22, 22, 22,  0, 22, 22, 22, 22,  0,  0, 22,  0,  0,  0,  0,
/*12*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*13*/ 13, 13, 13, 22, 22, 22, 22, 22, 17, 22, 22,  0, 22, 22, 15, 16,  0,  0, 22,  0, 22, 22,  0,
/*14*/ 14, 14, 14, 22, 22, 22, 22, 22, 22, 22, 22,  0, 22, 22, 15, 22,  0,  0, 22,  0, 22, 22,  0,
/*15*/ 15, 15, 15, 22,  0,  0, 22, 22, 22, 22, 22,  0, 22, 22, 22, 22,  0,  0, 22,  0, 22, 22,  0,
/*16*/ 16, 16, 16, 22,  0,  0, 22, 22, 22, 22, 22,  0, 22, 22, 22, 22,  0,  0, 22,  0, 22, 22,  0,
/*17*/ 17, 17, 17, 22,  0,  0, 22, 22, 22, 22, 22,  0, 22, 22, 22, 22,  0,  0, 22,  0, 22, 22,  0,
/*18*/ 18, 18, 18, 22,  0, 22, 22, 22, 22, 22, 22,  0,  0, 22, 22, 22,  0,  0, 22,  0, 22, 22,  0,
/*19*/ 19, 19, 19,  0,  0,  0, 22, 22, 22, 22, 22,  0, 22, 22, 22, 22,  0,  0, 22,  0,  0, 22,  0,
/*20*/ 20, 20, 20,  0,  0,  0, 22, 22, 22, 22, 22, 22,  0,  0,  0,  0,  0,  0,  0,  0,  0, 22,  0,
/*21*/ 21, 21, 21, 22,  0, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22,  0,  0, 22,  0, 22,  0,  0,
/*22*/  0, -1, -1, -9,-11,- 0,-13, -1, -1, -2, -1, -8, -7, -6,  0, -6, -5, -5, -3, -1, -4, -1, -1
};

//q0        = estado inicial
//q1 - q6   = estados Num
//q7 - q8   = estados Literal
//q9        = estado Identificador
//q10 e q11 = estados Comentários
//q12       = estado EOF
//q13 - q16 = estados Operadores Relacionáis
//q17       = estado Atribuição
//q18       = estado Operadores Aritméticos
//q19       = estado AB_P
//q20       = estado FC_P
//q21       = estado PT_V
//q19       = estado ERRO

//erros:
//-1        = caractere desconhecido
//-2        = ponto
//-3        = underscore
//-4        = abre chaves
//-5        = fecha chaves
//-6        = letra
//-7        = comparação
//-8        = ponto e vírgula
//-9        = número
//-10       = aspas
//-11       = abre parênteses
//-12       = fecha parênteses
//-13       = EOF

//Map<Lexema, Token, Atributo>;
map<string, pair<string, string> > symbolTable;

//String auxiliar para guardar o ultimo lexema;
pair<string, pair<string, string> >bufferLex;


int     symbolToCharClass (char);
void    showToken         (int);
void    showError         (int);
void    insertSymbol      (string,  string);
string  make_token        (int);

int main(int argc, char *argv[]) {
  string lex;
  int col = 0, line = 1;
  char symbol;
  int charClass, nextState, state = 0;

  symbolTable["inicio"    ] = make_pair("inicio",   "");
  symbolTable["varinicio" ] = make_pair("varinicio","");
  symbolTable["varfim"    ] = make_pair("varfim",   "");
  symbolTable["escreva"   ] = make_pair("escreva",  "");
  symbolTable["leia"      ] = make_pair("leia",     "");
  symbolTable["se"        ] = make_pair("se",       "");
  symbolTable["entao"     ] = make_pair("entao",    "");
  symbolTable["fimse"     ] = make_pair("fimse",    "");
  symbolTable["fim"       ] = make_pair("fim",      "");
  symbolTable["inteiro"   ] = make_pair("inteiro",  "");
  symbolTable["literal"   ] = make_pair("literal",  "");
  symbolTable["real"      ] = make_pair("real",     "");


  ifstream source("texto.alg");

  if (source.is_open()) {
    while (source.get(symbol)) {
      charClass = symbolToCharClass(symbol);
      nextState = sigma[state][charClass];
      if (symbol == '\n') {
        line++;
        col = 0;
      }
      if (nextState == 22) {
        cout << argv[0] << ":" << line << ":" << ":" << col << ": error: ";
        showError(sigma[nextState][charClass]);
        exit(EXIT_FAILURE);
      }
      if (nextState) {
        lex.push_back(symbol);
      }
      else {
        //showToken(state);
        if (lex.size() >= 1) insertSymbol(lex, make_token(state)); //cout << lex << endl;
        lex.clear();
        if (sigma[nextState][charClass]) {
          nextState = sigma[nextState][charClass];
          lex.push_back(symbol);
        }
      }
      state = nextState;
      col++;
    }
  }
  else {
    cout << "Programa fonte não encontrado!\n";
  }
  return 0;
}

int symbolToCharClass(char c) {
  if (c == '\t') {
    return 0;
  } else if (c == '\n') {
    return 1;
  } else if (c == ' ') {
    return 2;
  } else if (c == '"') {
    return 3;
  } else if (c >= '(' && c <= '+') {
    return c - 36;
  } else if (c >= '-' && c <= '/') {
    return c - 37;
  } else if (c >= '0' && c <= '9') {
    return 11;
  } else if (c >= ';' && c <= '>') {
    return c - 47;
  } else if ((c >= 'A' && c <= 'Z') || ((c >= 'a' && c <= 'z'))) {
    return c != 'E' ? 16 : 17;
  } else if (c == '_') {
    return 18;
  } else if (c == '{') {
    return 19;
  } else if (c == '}') {
    return 20;
  } else if (c == EOF) {
    return 21;
  } else {
    return 22;
  }
}

void showToken(int i) {
  if (i == 1 || i == 3 || i == 6)
    cout << "Token: NUM\t";
  else if (i == 8)
    cout << "Token: Literal\t";
  else if (i == 9)
    cout << "Token: ID\t";
  else if (i == 11)
    cout << "Token: Comentario\t";
  else if (i == 12)
    cout << "Token: End Of File\t";
  else if (i == 13 || i == 14 || i == 15 || i == 16)
    cout << "Token: Operador Relacional\t";
  else if (i == 17)
    cout << "Token: Atribuicao\t";
  else if (i == 18)
    cout << "Token: Operador Aritimetico\t ";
  else if (i == 19)
    cout << "Token: Abre Parentese\t";
  else if (i == 20)
    cout << "Token: Fecha Parentese\t";
  else if (i == 21)
    cout << "Token: Ponto e Virgula\t";
}

void showError(int code) {
  printf("%d\n", code);
}

void showTable(void){
  //Imprimir a tabela de simbolos;
}
string make_token(int i){
  if (i == 1 || i == 3 || i == 6)
    return "inteiro";
  else if (i == 8)
    return "literal";
  else if (i == 9)
    return "id";
  else if (i == 11)
    return "comentario";
  else if (i == 12)
    return "eof";
  else if (i == 13 || i == 14 || i == 15 || i == 16)
    return "OPR";
  else if (i == 17)
    return "RCB";
  else if (i == 18)
    return "OPM";
  else if (i == 19)
    return "AB_P";
  else if (i == 20)
    return "FC_P";
  else if (i == 21)
    return "PT_V";
  else if (i == 22)
    return "ERRO";
}

void instertSymbol(string lex, string token) {
  if (!symbolTable.count(lex)){
    symbolTable[lex] = make_pair(token, "");
    bufferLex.first = lex;
    bufferLex.second.first = token;
  }
  else if (lex == "inteiro" || lex == "literal" || lex == "real"){
    symbolTable[bufferLex.first] = make_pair(bufferLex.second.first, lex);
  }
  else{
    //Imprimir linha do token;
  }
}





