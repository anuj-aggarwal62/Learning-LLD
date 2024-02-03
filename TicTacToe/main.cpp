#include<bits/stdc++.h>
#include "GameEngine.cpp"
#include "Player.cpp"

using namespace std;

#define vi vector<int>
#define vvi vector<vi>


int main()
{
    GameEngine ttt;

    ttt.start();

    Player* winner = ttt.play();

    cout<<"Winner of the game is "<<winner->name<<endl;


}