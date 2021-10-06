#ifndef LEXER_H
#define LEXER_H
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

namespace C_1{    

    class Lexer
    {
    private:        
        const int ERROR = -1; 

        ifstream yyin;
        int **transiciones;
        bool *acc;        
        string yytext;
        int yyline;
        char c;
        int edos, sims;
        map<char, int> simbolos;

    public:
        Lexer();
        Lexer(string file);
        ~Lexer();

        //bool readAFD(string file);
        void getChar();
        bool openFile(string file);
        void closeFile();
        int yylex();
        void printTable();
        int token(int q);
        string getYytext();    
    };  
}

#endif