#include <iostream>
#include "pentago.h"

Pentago::Pentago(int taille/*=6*/, int nbAlignes/*=5*/)// : size(taille), winLength(nbAlignes)
{
   if(taille%2 == 0)
      size=taille;
   else
   {
      size=taille+1;
      cout << "La taille doit etre paire et a donc ete reglee sur ";
      cout << size << " (soit taille+1) " << endl;
   }
   if(nbAlignes<=taille)
      winLength=nbAlignes;
   else
   {
      winLength=size-1;
      cout << "Le nombre de pions a aligner pour gagner doit etre inferieur ou egal a la taille du plateau.";
      cout << "Il a ete regle a " << winLength << " (soit taille-1)"; 
      cout << endl;
   }
   setBoard();
}

Pentago::~Pentago()
{

}

int Pentago::getSize() const
{
   return size;
}

int Pentago::getWinLength() const
{
   return winLength;
}

void Pentago::setSize(int size)
{
   this->size=size;
}

void Pentago::setWinLength(int winLength)
{
   this->winLength=winLength;
}

void Pentago::setBoard()
{
   //char board[getSize()][getSize()];
   for(int i=0;i<getSize();i++)
   {
      for(int j=0;j<getSize();j++)
      {
         board[i][j]='X';
      }
   }
}

void Pentago::displayBoard()
{
   for(int i=0;i<getSize();i++)
   {
      cout << "   " << i;
   }
   cout << endl;
   for(int j=0;j<getSize();j++)
   {

      for(int k=0;k<getSize();k++)
      {
         cout << " . _";
      }
      cout << " ." << endl;
      for(int l=0;l<getSize();l++)
      {
         cout << " | " << board[j][l];
      }
      cout << " | " << j << endl;
   }
   
   for(int m=0;m<getSize();m++)
   {
      cout << " . _";
   }
   cout << " ." << endl;
   cout << " " << endl;
   cout << " " << endl;
}

void Pentago::poserPion(player P)
{
   int x,y = 0;
   cout << "Choisir la position verticale de 0 a " << getSize() << endl;
   cin >> x;
   cout << "Choisir la position horizontale de 0 a " << getSize() << endl;
   cin >> y;
   board[y][x]=P.nickname[0];
}

void Pentago::tournerPlateau(int numMorceau, char sens)
{
/*
   char ghostBoard[getSize()/2][getSize()/2];
   switch(numMorceau) 
   {
      case 1 : 
         if(sens=='D')
         {
            for(int i=0;i<getSize()/2;i++)
            {
               ghostBoard[i][getSize()/2-2] = board[getSize()/2][i];
               ghostBoard[i][getSize()/2-1] = board[getSize()/2-1][i];
               ghostBoard[i][getSize()/2] = board[getSize()/2-2][i];
            }

            for(int j=0;j<getSize()/2;j++)
            {
               for(int k=0;k<getSize()/2;k++)
               {
                  board[j][k] = ghostBoard[j][k];
               }
            }
         }
         else
         {
            for(int i=0;i<getSize()/2;i++)
            {
               ghostBoard[getSize()/2][i] = board[i][getSize()/2-2];
               ghostBoard[getSize()/2-1][i] = board[i][getSize()/2-1];
               ghostBoard[getSize()/2-2][i] = board[i][getSize()/2];
            }

            for(int j=0;j<getSize()/2;j++)
            {
               for(int k=0;k<getSize()/2;k++)
               {
                  board[j][k] = ghostBoard[j][k];
               }
            }
         }
         break;
      case 2 : break;
      case 3 : break;
      case 4 : break;
      default: cout << "Ce n'est pas un sous plateau valable"; break;
   }
*/
}

bool Pentago::winner(player P)
{
   int row = 0;
   for(int i=0;i<getSize();i++)
   {
      for(int j=0;j<getSize();j++)
      {
         if(board[i][j]==P.nickname[0])
            row++;
      }
   }
   if(row==winLength)
      return true;

   row = 0;
   for(int k=0;k<getSize();k++)
   {
      for(int l=0;l<getSize();l++)
      {
         if(board[l][k]==P.nickname[0])
            row++;
      }
   }
   if(row==winLength)
      return true;
   return false;
}
