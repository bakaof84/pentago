#include <iostream>
#include "pentago.h"

int main()
{
   Pentago partie1/*(7, 6)*/;
   cout << "Taille du plateau : " << partie1.getSize() << endl;
   cout << "Pions a aligner pour gagner : " << partie1.getWinLength() << endl;
   partie1.displayBoard();
}
