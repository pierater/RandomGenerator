//////////////////////////
// Filename: RandomGen.cpp
// Author: Martin Almaraz
// Date: Thu Sep 17 22:34:25 PDT 2015
//////////////////////////

#include <iostream>
#include "RandomGen.h"
#include <cstdlib>

using namespace std;

int main()
{
    RandomGen lis1;
    lis1.insert("Mavey");
    lis1.insert("Daniel");
    lis1.insert("Sarah");
    lis1.insert("Giselle");
    lis1.insert("Athena");
    lis1.insert("Nancy");
    lis1.insert("Sandra");
    lis1.insert("Samba");
    lis1.insert("Kristine");
    lis1.insert("Nicole");
    lis1.insert("Lesley");
    lis1.insert("Damaris");
    lis1.insert("Steven");
    lis1.insert("Emily");
    lis1.insert("Raquel");
    lis1.insert("Ally");
    lis1.insert("Thalia");
    lis1.insert("Reggie");
    lis1.insert("Bianca");
    lis1.insert("Chnel");
    
    lis1.exclude("Bianca");
    lis1.exclude("Mavey");
    lis1.exclude("Damaris");
    lis1.exclude("Chnel");
    lis1.shuffle();
    //for(int i = 0; i < 8; i++)
        //cout << lis1[i] << endl;
    //cout << lis1.size() << endl;
    //lis1.shuffle();
    lis1.getRoles();
    lis1.getPairs();
    return EXIT_SUCCESS;
}
