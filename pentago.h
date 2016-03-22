#ifndef PENTAGO
#define PENTAGO
#include "stdio.h"
#include <string>
#include<cstdlib>
#include<ctime>

using namespace std;
struct player
{
   string nickname;
   int nbVictoires;
};

class Pentago
{
      int size;                        //taille du plateau, forcement pair
      int winLength;                   //nombre de pions à aligner pour gagner
      int nbMorceaux;                  //nombre de sous plateaux
      char board[6][6];                //plateau de jeu TODO modulable
   public:
      Pentago(int taille=6, int nbAlignes=5);
      ~Pentago();
      int getSize() const;
      int getWinLength() const;
      void setSize(int size);
      void setWinLength(int winLength);
      void setBoard();
      void displayBoard();
      void poserPion(player P);
      void tournerPlateau(int numMorceau, char sens); //TODO
      bool winner(player gagnant);
};
#endif
