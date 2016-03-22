#include <iostream>
#include "pentago.h"

int main()
{

   cout << "Bienvenue. Jouons au Pentago !" << endl;
   cout << "------------------------------" << endl;
   /*
   int size, winLength;
   char setRules[10];
   
   cout << "Voulez vous changer les regles ? (O/N)" << endl;
   cin >> setRules;
   
   if(setRules[0]=='O' || setRules[0]=='o')
   {
      cout << "Veuillez selectionner la taille de votre plateau" << endl;
      cout << "La taille du plateau doit etre un nombre pair" << endl;
      cin >> size;
      cout << "Veuillez selectionner le nombre de jetons a aligner pour gagner" << endl;
      cout << "Ce nombre doit etre inferieur ou egal a la taille du plateau" << endl;
      cin >> winLength;
      Pentago partie1(size,winLength);
      cout << "Taille du plateau : " << partie1.getSize() << endl;
      cout << "Pions a aligner pour gagner : " << partie1.getWinLength() << endl;
      partie1.displayBoard();
   }
   else
   {
      cout << "Reglages par defaut" << endl;
      Pentago partie1;
      cout << "Taille du plateau : " << partie1.getSize() << endl;
      cout << "Pions a aligner pour gagner : " << partie1.getWinLength() << endl;
      partie1.displayBoard();
   }
   */
   cout << "Reglages par defaut" << endl;
   Pentago partie1;
   cout << "Taille du plateau : " << partie1.getSize() << endl;
   cout << "Pions a aligner pour gagner : " << partie1.getWinLength() << endl;
   partie1.displayBoard();

   string gagnant;
   string pseudo1, pseudo2;
   cout << "Veuillez choisir un pseudo pour le Joueur1" << endl;
   cin >> pseudo1;
   player J1;
   J1.nickname = pseudo1;
   cout << "Veuillez choisir un pseudo pour le Joueur2" << endl;
   cin >> pseudo2;
   player J2;
   J2.nickname = pseudo2;
   cout << "Les pseudo sont : " << endl;
   cout << "J1 : " << J1.nickname << endl;
   cout << "J2 : " << J2.nickname << endl;

   bool partieTerminee = false;
   while(partieTerminee==false)
   {
      partie1.displayBoard();
      cout << "C'est au tour de " << J1.nickname << endl;

      partie1.poserPion(J1);
      partie1.displayBoard();

      int numMorceau = 0;
      char sens = ' ';
      cout << "Les sous-plateaux sont repartis de cette maniere : " << endl;
      cout << "1-2" << endl;
      cout << "3-4" << endl;
      cout << "Choisir quel plateau tourner " << endl;
      cin >> numMorceau;
      cout << "Choisir le sens (D/G)" << endl;
      cin >> sens;
      partie1.tournerPlateau(numMorceau, sens);

      if(partie1.win(J1,J2).nickname==J1.nickname)
      {
         partieTerminee = true;
         break;
      }
      if(partie1.win(J1,J2).nickname==J2.nickname)
      {
         partieTerminee = true;
         break;
      }

      partie1.displayBoard();
      cout << "C'est au tour de " << J2.nickname << endl;

      partie1.poserPion(J2);
      partie1.displayBoard();

      /*
      numMorceau = 0;
      sens = ' ';
      cout << "Les sous-plateaux sont repartis de cette maniere : " << endl;
      cout << "1-2" << endl;
      cout << "3-4" << endl;
      cout << "Choisir quel plateau tourner " << endl;
      cin >> numMorceau;
      cout << "Choisir le sens (D/G)" << endl;
      cin >> sens;
      partie1.tournerPlateau(numMorceau, sens);
      */
      if(partie1.win(J1,J2).nickname==J1.nickname)
      {
         partieTerminee = true;
         break;
      }
      if(partie1.win(J1,J2).nickname==J2.nickname)
      {
         partieTerminee = true;
         break;
      }

   }
   cout << "Partie terminee" << endl;
   cout << "Le gagnant est : " << partie1.win(J1,J2).nickname << endl;
   cout << "A bientot" << endl;
}
