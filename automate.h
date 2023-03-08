#pragma once

#include "lexer.h"
#include "symbole.h"
#include <stack>

class State;
class State0;

class automate
{
    private:
        std::stack<State*> pileEtat;
        std::stack<Symbole*> pileSymbole;
        Lexer& lex;
        bool accept = false;
        bool stringError = false;
        string errorString;
    public:
        automate(Lexer &l);
        ~automate();
        bool solveAutomate(int& result, string& errorString);
        void pushState(State*s);
        void popState(int nb);
        State* getState();
        void pushSymbole(Symbole*s);
        Symbole* popSymbole();
        void decalage(State *st, Symbole*sy);
        void faux_decalage(State *st, Symbole*sy);
        void accepter();
        void printPileEtat();
        void printPileSymbole();
        void setError(string s);
};
