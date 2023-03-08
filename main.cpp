#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {

   string chaine;

   cout<<"Entrez la chaine à analyser : ";

   cin>>chaine;  

   Lexer l(chaine);

   automate a(l);
   int valeur;
   string errorString;
   bool result = a.solveAutomate(valeur, errorString);

   cout<<"---------------------------------------------------"<<endl;
   if(result){
      cout<<"Expression correcte"<<endl;
      cout<<"Valeur de l'expression : "<<valeur<<endl;
   }else{
      cout<<"Mot non reconnu"<<endl;
      cout<<errorString<<endl;
   }

   return 0;
}

