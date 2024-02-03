#ifndef GAME
#define GAME

#include "Board.cpp"
#include "Player.cpp"
#include<bits/stdc++.h>

using namespace std;
class Game
{
    public:
    Board *board;
    Player *win;
    Player *p1, *p2;
    bool complete;
    Game(int n,Player *p1, Player *p2)
    {
        board = new Board(n);
        this->p1 = p1;
        this->p2 = p2;
        complete = false;
    }

    bool move(Player* player,int i,int j)
    {
        if(board->isValidMove(i,j))
        {
            if(board->move(player,i,j))
            {
                complete = true;
                win = player;
            }
            return 1;
        }
        else
        {
            cout<<"Invalid Move"<<endl;
            return 0;
        }
    }

    bool isComplete()
    {
        return complete;
    }

    Player* winner()
    {
        return win;
    }  

    ~Game()
    {
        delete board;
    }
};

#endif