#ifndef PLAYER
#define PLAYER
#include<bits/stdc++.h>
using namespace std;

class Player
{
    public:
    string name;
    int id;

    Player(int id)
    {
        this->id = id;
        cout<<"Player "<<id<<" : Enter you name ";
        cin>>name;
    }
};

#endif