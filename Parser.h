#ifndef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include <string>
using namespace std;
#include "tokes.h"

namespace C_1{

	class Parse{
	private:
		Lexer *lexer;
		int token;
	public:
		Parser();
		Parser(Lexer *lexer);
		~Parser();
		void programa();
		void declaraciones();
		void declaracionesP();
		void declaracion();
		void tipo();
		void lista_var();
		void lista_varP();
		void sentencias();
		void sentenciasP();
		void sentencia();
		void expresion();
		void expresionP();
		void termino();
		void terminoP();
		void fector();
		void eat(int t);
		void error(string msg);
	};


}//namespaceC_1