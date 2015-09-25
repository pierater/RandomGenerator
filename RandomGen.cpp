//////////////////////////
// Filename: RandomGen.cpp
// Author: Martin Almaraz
// Date: Thu Sep 17 22:34:25 PDT 2015
//////////////////////////


#include "RandomGen.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

RandomGen::RandomGen()
{
    CAPACITY = 1;
    used = 0;
    excluded = 0;
    names = new string[CAPACITY];
    excludes = new string[excluded];
    educators = new string[CAPACITY];
    roles[0] = "Educator 1:";
    roles[1] = "Educator 2:";
    roles[2] = "Time Keeper:";
    roles[3] = "Word of the Week:";
    roles[4] = "Thought of the Week:";
    roles[5] = "Thought of the World:";

}

void RandomGen::grow()
{
    string *temp;
    temp = new string[CAPACITY];
    for(int i = 0; i < CAPACITY; i++)
        temp[i] = names[i];
    CAPACITY++;
    delete[] names;
    names = new string[CAPACITY];
    for(int i = 0; i < CAPACITY - 1; i++)
        names[i] = temp[i];
    return;
}

void RandomGen::insert(string member)
{
    if(used + 1 > CAPACITY)
        grow();
    if(used == 0)
    {
        names[0] = member;
        used++;
        return;
    }
    names[used] = member;
    used++;
}

void RandomGen::remove(string member)
{
    for(int i = 0; i < used; i++)
     {
         if(names[i] == member)
         {
             string temp = names[used - 1];
             names[used - 1] = names[i];
             names[i] = temp;
             used--;
             break;
         }
     }
}

void RandomGen::getPairs()
{
    ofstream fout;
    fout.open("Pairs.txt");
    shuffle();
    fout << "herScript(Pairs)\n";
    fout << "================\n\n";

    for(int i = 0; i < used - 1; i+=2)
    {
        fout << i+1 << ") " << names[i] << " " <<  names[i+1] << endl;
    }
    fout.close();

}

void RandomGen::getRoles()
{
    ofstream fout;
    fout.open("Roles.txt");
    //shuffle();
    fout << "herScript(Roles)\n";
    fout << "================\n\n";
    
    string *temp = new string[used];
    int j = 0;
    cout << used << endl;
    for(int i = 0; i < used; i++)
    {
        if(!isExcluded(names[i]))
            temp[i - j] = names[i];
        else
        {
            j++;
            temp[used - j] = names[i];
        }
    }
    string *temp2 = new string[used];
    for(int i = 0; i < used - j; i++)
        temp2[i] = temp[i];


  
    for(int i = 0; i < used; i++)
    {
        if(i % 6 == 0)
            fout << "------" << "Week " << i % 5 + 1 << "------\n";
    
        fout << roles[i%6] << " " << temp[i] << endl;
    }
    delete[] temp;
    
    fout.close();
}
void RandomGen::shuffle()
{
    srand(time(NULL));
    int random, random2;
    
    for(int i = 0; i < used * 2; i++)
    {
        random = rand() % used;
        do
        {
            random2 = rand() % used;
        }while(random2 == random);
        string temp = names[random];
        string temp2 = names[random2];
        names[random] = temp2;
        names[random2] = temp;
    }
}

void RandomGen::exclude(string name)
{
    string *temp;
    temp = new string[excluded];
    for(int i = 0; i < excluded; i++)
        temp[i] = excludes[i];
    excluded++;
    delete[] excludes;
    excludes = new string[excluded];
    
    for(int i = 0; i < excluded - 1; i++)
        excludes[i] = temp[i];
        
    excludes[excluded - 1] = name;

}

bool RandomGen::isExcluded(string name)
{
    for(int i = 0; i < excluded; i++)
        if(excludes[i] == name)
            return true;
    return false;
}

RandomGen::~RandomGen()
{
    delete[] names;
}
