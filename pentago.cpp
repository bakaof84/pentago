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
      for(int j=0;j<getSize();j++)
      {
         cout << " . _";
      }
      cout << " ." << endl;
      for(int k=0;k<getSize();k++)
      {
         cout << " | " << board[i][k];
      }
      cout << " | " << endl;
   }
   
   for(int l=0;l<getSize();l++)
   {
      cout << " . _";
   }
   cout << " ." << endl;
}