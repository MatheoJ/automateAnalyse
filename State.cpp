#include "State.h"

State::State(/* args */)
{
}

State::~State()
{
}

State0::State0(/* args */)
{
}

void State0::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(INT):
            a.decalage(new State3, s);
            break;
        case(OPENPAR):
            a.decalage(new State2, s);
            break;
        case (EXPR):
            a.faux_decalage(new State1, s);
            break; 
        default:
            a.setError("Erreur de syntaxe on attendait un entier, une expression ou une parenthèse ouvrante, on a reçu :"+s->toString());
            break;
        
    }
}

State0::~State0()
{
}

State1::State1(/* args */)
{
}

void State1::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(PLUS):
            a.decalage(new State4, s);
            break;
        case(MULT):
            a.decalage(new State5, s);
            break;
        case (FIN):
            a.accepter();
            break;   
        default:
            a.setError("Erreur de syntaxe on attendait un +, un * ou la fin de l'expression, on a reçu :"+s->toString());
            break;
    }
}

State1::~State1()
{
}

State2::State2(/* args */)
{
}

void State2::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(INT):
            a.decalage(new State3, s);
            break;
        case(OPENPAR):
            a.decalage(new State2, s);
            break;
        case (EXPR):
            a.faux_decalage(new State6, s);
            break; 
        default:
            a.setError("Erreur de syntaxe on attendait un entier, une expression ou une parenthèse ouvrante, on a reçu :"+s->toString());
            break;
    }
}

State2::~State2()
{
}

State3::State3(/* args */)
{
}

void State3::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(PLUS):
        case(MULT):
        case (CLOSEPAR):
        case (FIN):
        {
            a.popState(1);
            Entier *symb = (Entier*)a.popSymbole();
            State *state = a.getState();
            state->Transition(a,new Expr(symb->getValeur()));
            break;
        }
        default:
            a.setError("Erreur de syntaxe on attendait un +, un *, une parenthèse fermante ou la fin de l'expression, on a reçu :"+s->toString());
            break;
    }
}

State3::~State3()
{
}

State4::State4(/* args */)
{
}

void State4::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(INT):
            a.decalage(new State3, s);
            break;
        case(OPENPAR):
            a.decalage(new State2, s);
            break;
        case (EXPR):
            a.faux_decalage(new State7, s);
            break; 
        default:
            a.setError("Erreur de syntaxe on attendait un entier, une expression ou une parenthèse ouvrante, on a reçu :"+s->toString());
            break;
    }
}

State4::~State4()
{
}

State5::State5(/* args */)
{
}

void State5::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(INT):
            a.decalage(new State3, s);
            break;
        case(OPENPAR):
            a.decalage(new State2, s);
            break;
        case (EXPR):
            a.faux_decalage(new State8, s);
            break; 
        default:
            a.setError("Erreur de syntaxe on attendait un entier, une expression ou une parenthèse ouvrante, on a reçu :"+s->toString());
            break;
    }
}

State5::~State5()
{
}

State6::State6(/* args */)
{
}

void State6::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(PLUS):
            a.decalage(new State4, s);
            break;
        case(MULT):
            a.decalage(new State5, s);
            break;
        case (CLOSEPAR):
            a.decalage(new State9, s);
            break;
        default:
            a.setError("Erreur de syntaxe on attendait un +, un *, une parenthèse fermante ou la fin de l'expression, on a reçu :"+s->toString());
            break;
    }
}

State6::~State6()
{
}

State7::State7(/* args */)
{
}

void State7::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(PLUS):
        case (CLOSEPAR):
        case (FIN):
        {
            a.popState(3);
            Expr *expr1 = (Expr*)a.popSymbole();
            a.popSymbole();
            Expr *expr2 = (Expr*)a.popSymbole();
            State *state = a.getState();
            state->Transition(a,new Expr(expr1->getValeur()+expr2->getValeur()));
            break;
        }
        case (MULT):
        {
            a.decalage(new State5, s);
            break;
        }
        default:
            a.setError("Erreur de syntaxe on attendait un +, un *, une parenthèse fermante ou la fin de l'expression, on a reçu :"+s->toString());
            break;
    }
}

State7::~State7()
{
}

State8::State8(/* args */)
{
}

void State8::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(PLUS):
        case(MULT):
        case (CLOSEPAR):
        case (FIN):
        {
            a.popState(3);
            Expr *expr1 = (Expr*)a.popSymbole();
            a.popSymbole();
            Expr *expr2 = (Expr*)a.popSymbole();
            State *state = a.getState();
            state->Transition(a,new Expr(expr1->getValeur()*expr2->getValeur()));
            break;
        }
        default:
            a.setError("Erreur de syntaxe on attendait un +, un *, une parenthèse fermante ou la fin de l'expression, on a reçu :"+s->toString());
            break;
    }
}

State8::~State8()
{
}

State9::State9(/* args */)
{
}

void State9::Transition(automate& a, Symbole* s)
{
    switch (*s){
        case(PLUS):
        case(MULT):
        case (CLOSEPAR):
        case (FIN):
        {    
            a.popState(3);
            a.popSymbole();
            Expr *expr = (Expr*)a.popSymbole();
            a.popSymbole();
            State *state = a.getState();
            state->Transition(a,(new Expr(expr->getValeur())));
            break;
        }
        default:
            a.setError("Erreur de syntaxe on attendait un +, un *, une parenthèse fermante ou la fin de l'expression, on a reçu :"+s->toString());
            break;
    }
}

State9::~State9()
{
}


string State0::toString(){
    return "State0 ";
}

string State1::toString(){
    return "State1 ";
}

string State2::toString(){
    return "State2 ";
}

string State3::toString(){
    return "State3 ";
}

string State4::toString(){
    return "State4 ";
}

string State5::toString(){
    return "State5 ";
}

string State6::toString(){
    return "State6 ";
}

string State7::toString(){
    return "State7 ";
}

string State8::toString(){
    return "State8 ";
}

string State9::toString(){
    return "State9 ";
}