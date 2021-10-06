#include "Lexer.h"
#include "tokens.h"
#include <iostream>

namespace C_1{

    Lexer::Lexer(/* args */)
    {
    }
    
    Lexer::Lexer(string file)
    {
        ifstream afd(file);
        string line, aceptar;
        stringstream s;
        int ren = 0, col = 0, q;
        getline(afd, line);
        s = stringstream(line);
        s>>edos;
        s>>sims;
        transiciones = new int*[edos];

        for(int i = 0; i < edos; i++)
            transiciones[i] = new int[sims];

        acc = new bool[edos];

        while(ren < edos){
            getline(afd, line);
            s = stringstream(line);
            while(col < sims){
                s>>q;
                transiciones[ren][col++] = q;
            }
            s>>aceptar;
            aceptar == "true"?acc[ren] = true : acc[ren] = false;
            ren++;
            col = 0;
        }

        printTable();
        afd.close();
        simbolos['+'] = 0;
        simbolos['-'] = 1;
        simbolos['*'] = 2;
        simbolos['/'] = 3;
        simbolos['='] = 4;
        simbolos[' '] = 5; 
        simbolos['\t'] = 5;
        simbolos['\r'] = 5;
        simbolos['\n'] = 5;
        simbolos['0'] = 6;
        simbolos['1'] = 6;
        simbolos['2'] = 6;
        simbolos['3'] = 6;
        simbolos['4'] = 6;
        simbolos['5'] = 6;
        simbolos['6'] = 6;
        simbolos['7'] = 6;
        simbolos['8'] = 6;
        simbolos['9'] = 6;

        simbolos['a'] = 7;
        simbolos['E'] = 8;
        simbolos['e'] = 9;
        simbolos['f'] = 10;
        simbolos['h'] = 11;
        simbolos['i'] = 12;
        simbolos['l'] = 13;
        simbolos['n'] = 14;
        simbolos['o'] = 15;
        simbolos['s'] = 16;
        simbolos['t'] = 17; //[b-dgjkmp-ruvx-zA-Z_]
        simbolos['w'] = 18;
        simbolos['.'] = 20;
        simbolos[','] = 21;
        simbolos[';'] = 22;
        simbolos['('] = 23;
        simbolos[')'] = 24;
        simbolos['_'] = 19;
        simbolos['b'] = 19;
        simbolos['c'] = 19;
        simbolos['d'] = 19;
        simbolos['g'] = 19;
        simbolos['j'] = 19;
        simbolos['k'] = 19;
        simbolos['m'] = 19;
        simbolos['p'] = 19;
        simbolos['q'] = 19;
        simbolos['r'] = 19;
        simbolos['u'] = 19;
        simbolos['v'] = 19;
        simbolos['x'] = 19;
        simbolos['y'] = 19;
        simbolos['z'] = 19;
        simbolos['A'] = 19;
        simbolos['A'] = 19;
        simbolos['B'] = 19;
        simbolos['C'] = 19;
        simbolos['D'] = 19;
        simbolos['F'] = 19;
        simbolos['G'] = 19;
        simbolos['H'] = 19;
        simbolos['I'] = 19;
        simbolos['J'] = 19;
        simbolos['K'] = 19;
        simbolos['L'] = 19;
        simbolos['M'] = 19;
        simbolos['N'] = 19;
        simbolos['O'] = 19;
        simbolos['P'] = 19;
        simbolos['Q'] = 19;
        simbolos['R'] = 19;
        simbolos['S'] = 19;
        simbolos['T'] = 19;
        simbolos['U'] = 19;
        simbolos['V'] = 19;
        simbolos['W'] = 19;
        simbolos['X'] = 19;
        simbolos['Y'] = 19;
        simbolos['Z'] = 19;

        /*
        simbolos['e'] = 9;
        simbolos['w'] = 10;
        simbolos['l'] = 11;
        simbolos['s'] = 12;
        simbolos['h'] = 13;
        simbolos['n'] = 14;
        simbolos['t'] = 15;
        simbolos['o'] = 16;
        simbolos['a'] = 17; //[b-dgjkmp-ruvx-zA-Z_]
        simbolos['b'] = 18;
        simbolos['d'] = 18;
        simbolos['g'] = 18;
        simbolos['j'] = 18;
        simbolos['k'] = 18;
        simbolos['m'] = 18;
        simbolos['p'] = 18;
        simbolos['q'] = 18;
        simbolos['r'] = 18;
        simbolos['u'] = 18;
        simbolos['v'] = 18;
        simbolos['x'] = 18;
        simbolos['y'] = 18;
        simbolos['z'] = 18;
        simbolos['A'] = 18;
        simbolos['B'] = 18;
        simbolos['C'] = 18;
        simbolos['D'] = 18;
        simbolos['E'] = 18;
        simbolos['F'] = 18;
        simbolos['G'] = 18;
        simbolos['H'] = 18;
        simbolos['I'] = 18;
        simbolos['J'] = 18;
        simbolos['K'] = 18;
        simbolos['L'] = 18;
        simbolos['M'] = 18;
        simbolos['N'] = 18;
        simbolos['O'] = 18;
        simbolos['P'] = 18;
        simbolos['Q'] = 18;
        simbolos['R'] = 18;
        simbolos['S'] = 18;
        simbolos['T'] = 18;
        simbolos['U'] = 18;
        simbolos['V'] = 18;
        simbolos['W'] = 18;
        simbolos['X'] = 18;
        simbolos['Y'] = 18;
        simbolos['Z'] = 18;
        simbolos['_'] = 18;
        simbolos['.'] = 19;
        simbolos[','] = 20;
        simbolos[';'] = 21;
        simbolos['('] = 22;
        simbolos[')'] = 23;        */

    }

    Lexer::~Lexer()
    {
        for(int i = 0; i < edos; i++){
            delete transiciones[i];
        }
        delete transiciones;
        delete acc;
    }

    void Lexer::getChar(){
        yyin.get(c);
    }

    bool Lexer::openFile(string file){
        yyin.open(file,ios::in);

        if(!yyin.is_open()){
            cout << "Could not open the file - '" << file << "'" << endl;
            return EXIT_FAILURE;
        }
        getChar();
        return true;
    }

    void Lexer::closeFile(){
        yyin.close();
    }

    int Lexer::yylex(){
        int q=0;
        int cc;
        yytext = "";

        if(yyin.eof()) return 0;
        while(true){
        
            cc = simbolos[c];
            if(transiciones[q][cc] != -1){
                q = transiciones[q][cc];
                yytext+=c;
                
                getChar();
                if(yyin.eof()) return token(q);
            }
            else {
                if(acc[q]){
                    if(q == 17){
                        q = 0;
                        yytext = "";
                    }
                    else return token(q);
                }
                else {
                    return ERROR;
                }
            }
        }

    }

    int Lexer::token(int q){
        switch(q){
            case 1:
                return MAS;
            case 2:
                return MENOS;
            case 3:
                return MUL;
            case 4:
                return DIV;
            case 5:
                return ASIG;
            case 6:
                return LPAR;
            case 7:
                return RPAR;
            case 8:
                return PYC;
            case 9:
                return COMA;
            case 10: case 20: case 35:
                return NUMERO;
            case 12: case 13: case 14: case 15: case 16: case 18: case 21: case 22: case 23: case 25: case 26: case 27: case 28: case 30: 
                return ID;
            case 17:
                return ESP;
            case 19:
                return IF;
            case 24:
                return INT;
            case 29:
                return ELSE;
            case 31:
                return FLOAT;
            case 32:
                return WHILE;
        }
        return 0;
    }

    string Lexer::getYytext(){
        return yytext;
    }

    void Lexer::printTable(){
        for(int i = 0; i < edos; i++){
            for(int j = 0; j < sims; j++){
                cout << transiciones[i][j] << "\t";
            }
            cout << endl;
        }

     /*   for(int i = 0; i < edos; i++){
            cout << acc[i] << "\t";
        }
        cout << endl;*/
    }

}