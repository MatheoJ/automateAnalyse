#include "automate.h"
#include "State.h"
#include <iostream>

automate::automate(Lexer& l):lex(l)
{
}

automate::~automate()
{
}

bool automate::solveAutomate(int& result, string& errorString){
    this->pileEtat.push(new State0);
    while (!this->accept && !this->stringError )
    {
        this->getState()->Transition(*this, this->lex.Consulter());        
        //this->printPileEtat();
        //this->printPileSymbole();

    }
    if(this->accept)
        result = ((Expr*)this->popSymbole())->getValeur();
    else
        errorString = this->errorString;
    return this->accept;
}

void automate::pushState(State *s){
    this->pileEtat.push(s);
}

void automate::popState(int nb){
    for (int i = 0; i < nb; i++)
    {
        this->pileEtat.pop();
    }
}

State* automate::getState(){
    return this->pileEtat.top();
}

void automate::pushSymbole(Symbole *s){
    this->pileSymbole.push(s);
}

Symbole* automate::popSymbole(){
    Symbole* s = this->pileSymbole.top();
    this->pileSymbole.pop();
    return s;
}

void automate::decalage(State *st, Symbole*sy){
    this->pileEtat.push(st);
    this->pileSymbole.push(sy);
    this->lex.Avancer();
}

void automate::faux_decalage(State *st, Symbole*sy){
    this->pileEtat.push(st);
    this->pileSymbole.push(sy);
}

void automate::accepter(){
    this->accept = true;
}

void automate::printPileEtat(){
    std::stack<State*> temp = this->pileEtat;
    while (!temp.empty())
    {
        std::cout << temp.top()->toString() << " ";
        temp.pop();
    }

    std::cout << std::endl;
}

void automate::printPileSymbole(){
    std::stack<Symbole*> temp = this->pileSymbole;
    while (!temp.empty())
    {
        temp.top()->Affiche();
        std::cout << " ";
        temp.pop();
    }

    std::cout << std::endl;
    
}

void automate::setError(string s){
    this->stringError = true;
    this->errorString = s;
}