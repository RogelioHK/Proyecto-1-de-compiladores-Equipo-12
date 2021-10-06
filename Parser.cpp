#include "Parser.h"
#include <iostream>

namespace C_1{

	Parser::Parser(/*args*/){
	}

	Parser::Parser(Lexer *lexer){
		this->lexer = lexer;
	}

	Parser::~Parser(){
		void Parser::programa(){
			declaraciones();
			sentencias();
		}

		void Parser::declaraciones(){
			declaracion();
			declaracionesP();
		}

		void Parser::declaracionesP(){
			if(token == INT || token == FLOAT){
				declaraciones();
				declaracionesP();
			}
		}

		void Parser::declaracion(){
			tipo();
			lista_var();
		}

		void Parser::tipo(){
			switch(token){
				case INT:
					eat(INT);
					break;

				case FLOAT;
					eat(FLOAT);
					break;

				default:
					error("El token debe ser int o float");
					break;
			}
		}

		void Parser::lista_var(){
			eat(ID);
			lista_varP();
		}

		void Parser::lista_varP(){
			if(--){
				eat(COMA)
				lista_varP();
			}
		}

		void Parser::sentencias(){
			sentencia();
			sentenciasP();
		}

		void Parser::sentenciasP(){
			if((token == ID && token == ASIG) || token == IF && token == ELSE){
				sentencia();
				sentenciasP();
			}
		}

		void Parser::sentencia(){
			if(token == LPAR || token == RPAR || token == ID || token == NUMERO ){
				expresion();
			}else{
				expresion();
				sentencias();
			}
		}

		void Parser::expresion(){
			termino();
			expresion();
		}

		void Parser::expresionP(){
			if(token == SUMA){
				termino();
				expresion();
			}else{
				if(token == RESTA){
					termino();
					expresionP();
				}
			}
		}

		void Parser::termino(){
			factor();
			terminoP();
		}

		void Parser::terminoP(){
			if(toker == MUL){
				factor();
				terminoP();
			}else{
				if(token == DIV){
					factor();
					terminoP();
				}
			}
		}

		void Parser::factor(){
			if(token == LPAR ||token == RPAR ){
				expresion();
			}else{
				if(token == ID){
					eat(ID);
				}else{
					if(token == NUMERO){
						eat(NUMERO);
					}else{
						error("Error");
					}
				}
			}
		}

		void Parser::eat(int t){

		}

		void Parser::error(string msg){

		}
	}
}