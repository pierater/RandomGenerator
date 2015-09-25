//////////////////////////
// Filename: RandomGen.h
// Author: Martin Almaraz
// Date: Thu Sep 17 22:34:25 PDT 2015
//////////////////////////

#ifndef RANDOMGEN_H
#define RANDOMGEN_H
#include <string>

using namespace std;

class RandomGen
{
    private:
        string *names;
        string *excludes;
        string *educators;
        string roles[6];
        int CAPACITY;
        int excluded;
        int used;
        void grow();
    public:
        RandomGen();
        void insert(string member);
        void remove(string member);
        void getPairs();
        void getRoles();
        void shuffle();
        string operator [](int index) const {return (index <= used && index >= 0) ? (names[index]) : ("NAN");}
        int size() const {return used;}
        void exclude(string name);
        bool isExcluded(string name);
        ~RandomGen();
};

#endif
