#pragma once

#include <string>
#include <vector>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
      string toString();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur() { return valeur; }
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr(int v) : Symbole(EXPR), valeur(v) { }
      ~Expr() { }
      virtual void Affiche();
      int getValeur() { return valeur; }
   protected:
      int valeur;

};

