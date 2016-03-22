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
         board[i][j]=' ';
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
   char ghost;
   switch(numMorceau)
	   {
		   case 1 :
				   if(sens=='D' || sens=='d')
				   {
					   ghost = board[0][0];
					   board[0][0] = board[2][0];
					   board[2][0] = board[2][2];
					   board[2][2] = board[0][2];
					   board[0][2] = ghost;
					   ghost = board[0][1];
					   board[0][1] = board[1][0];
					   board[1][0] = board[2][1];
					   board[2][1] = board[1][2];
					   board[1][2] = ghost;
				   }
				   else
				   {
					   ghost = board[0][0];
					   board[0][0] = board[0][2];
					   board[0][2] = board[2][2];
					   board[2][2] = board[2][0];
					   board[2][0] = ghost;
					   ghost = board[0][1];
					   board[0][1] = board[1][2];
					   board[1][2] = board[2][1];
					   board[2][1] = board[1][0];
					   board[1][0] = ghost;
				   }
				   break;
		   case 2 :
				   if(sens=='D' || sens=='d')
				   {
					   ghost = board[0][3];
					   board[0][3] = board[2][3];
					   board[2][3] = board[2][5];
					   board[2][5] = board[0][5];
					   board[0][5] = ghost;
					   ghost = board[0][4];
					   board[0][4] = board[1][3];
					   board[1][3] = board[2][4];
					   board[2][4] = board[1][5];
					   board[1][5] = ghost;
				   }
				   else
				   {
					   ghost = board[0][3];
					   board[0][3] = board[0][5];
					   board[0][5] = board[2][5];
					   board[2][5] = board[2][3];
					   board[2][3] = ghost;
					   ghost = board[0][4];
					   board[0][4] = board[1][5];
					   board[1][5] = board[2][4];
					   board[2][4] = board[1][3];
					   board[1][3] = ghost;
				   }
				   break;
		   case 3 :
				   if(sens=='D' || sens=='d')
				   {
					   ghost = board[3][0];
					   board[3][0] = board[5][0];
					   board[5][0] = board[5][2];
					   board[5][2] = board[3][2];
					   board[3][2] = ghost;
					   ghost = board[3][1];
					   board[3][1] = board[4][0];
					   board[4][0] = board[5][1];
					   board[5][1] = board[4][2];
					   board[4][2] = ghost;
				   }
				   else
				   {
					   ghost = board[3][0];
					   board[3][0] = board[3][2];
					   board[3][2] = board[5][2];
					   board[5][2] = board[5][0];
					   board[5][0] = ghost;
					   ghost = board[3][1];
					   board[3][1] = board[4][2];
					   board[4][2] = board[5][1];
					   board[5][1] = board[4][0];
					   board[4][0] = ghost;
				   }
				   break;
		   case 4 :
				   if(sens=='D' || sens=='d')
				   {
					   ghost = board[3][3];
					   board[3][3] = board[5][3];
					   board[5][3] = board[5][5];
					   board[5][5] = board[3][5];
					   board[3][5] = ghost;
					   ghost = board[3][4];
					   board[3][4] = board[4][3];
					   board[4][3] = board[5][4];
					   board[5][4] = board[4][5];
					   board[4][5] = ghost;
				   }
				   else
				   {
					   ghost = board[3][3];
					   board[3][3] = board[3][5];
					   board[3][5] = board[5][5];
					   board[5][5] = board[5][3];
					   board[5][3] = ghost;
					   ghost = board[3][4];
					   board[3][4] = board[4][5];
					   board[4][5] = board[5][4];
					   board[5][4] = board[4][3];
					   board[4][3] = ghost;
				   }
				   break;
   }
}

player Pentago::win(player P1, player P2)
{
   player None;
   None.nickname = "None";
   None.nbVictoires = 0;
   if(checkRow(P1)) return P1;
   if(checkRow(P2)) return P2;
   if(checkColumn(P1)) return P1;
   if(checkColumn(P2)) return P2;
   return None;
}

bool Pentago::checkRow(player P)
{
   int compteur;
	for(int i=0 ;i<=getSize()-1;i++)
	{
		compteur = 0;
		for(int j=0;j<=getSize()-1;j++)
		{
			if(board[i][j]==P.nickname[0])
			{
				compteur++;
				if(compteur==winLength)
					return true;
			}
			else
				compteur = 0;
		}
	}
	return false;
}

bool Pentago::checkColumn(player P)
{
   int compteur;
	for(int i=0 ;i<=getSize()-1;i++)
	{
		compteur = 0;
		for(int j=0;j<=getSize()-1;j++)
		{
			if(board[j][i]==P.nickname[0])
			{
				compteur++;
				if(compteur==winLength)
					return true;
			}
			else
				compteur = 0;
		}
	}
	return false;
}
