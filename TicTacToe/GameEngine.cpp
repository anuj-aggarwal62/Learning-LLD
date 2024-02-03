#ifndef GAMEENGINE
#define GAMEENGINE

#include<bits/stdc++.h>
using namespace std;
#include "Player.cpp"
#include "Game.cpp"

class GameEngine
{
    public:
    Player *p1,*p2;
    Game *game;
    int size;

    void start()
    {
        cout<<"Enter the size of board ";
        cin>>size;        
        p1 = new Player(0);
        p2 = new Player(1);

        game = new Game(size,p1,p2);
    }

    Player* play()
    {
        bool check = true;
        while(!game->isComplete())
        {
            int i,j;
            if(check)
            {
                cout<<"Enter your move "<<p1->name<<endl;
                cin>>i>>j;
                bool move = game->move(p1,i,j);

                if(!move)
                {
                    cout<<"Invalid move , Try again !"<<endl;
                }
                else
                    check = false;
            }
            else
            {
                cout<<"Enter your move "<<p2->name<<endl;
                cin>>i>>j;
                game->move(p2,i,j);
                check = true;
            }
        }

        return game->winner();
    }

    GameEngine() = default;

};

#endif