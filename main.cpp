#include <iostream>
#include "Lexer.h"

using namespace std;
using namespace C_1;

int main(int argc, char *argv[]){
	if(argc < 2){
		cout << "Faltan argumentos" << endl;
		return EXIT_FAILURE;
	}

	Lexer lexer("afd.txt");
	lexer.openFile(string(argv[1]));

	int token = lexer.yylex();

	while(token != 0){
		cout << token << ", " << lexer.getYytext() << endl;
		token = lexer.yylex();
	}
 
	lexer.closeFile();
	return 0;
}