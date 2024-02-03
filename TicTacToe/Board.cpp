#ifndef BOARD
#define BOARD
#include<bits/stdc++.h>
using namespace std;

#include "Player.cpp"
#define vi vector<int>
#define vvi vector<vi>
class Board
{
    public: 
    vvi board;
    int n;
    vvi rows;
    vvi cols;
    vvi diags;

    Board() = default;
    Board(int n)
    {
        this->n = n;
        board.resize(n,vi(n,-1));
        rows.resize(2,vi(n,0));
        cols.resize(2,vi(n,0));
        diags.resize(2,vi(2,0));
    }

    bool isValidMove(int i,int j)
    {
        return (board[i][j]==-1 && i>=0 && j>=0 && i<n && j<n);
    }

    int move(Player *player,int i,int j)
    {
        int p = player->id;
        rows[p][i]++;
        cols[p][j]++;
        board[i][j] = p;

        if(i==j)
        {
            diags[p][0]++;
        }
        if(i==(n-j-1))
        {
            diags[p][1]++;
        }
        
        if(rows[p][i] == n || cols[p][j] == n || diags[p][0] == n || diags[p][1] == n)
        {
            return 1;
        }

        return 0;
    }

    void print()
    {
        for(auto i : board) 
        {
            for(auto j : i) cout<<j<<" ";
            cout<<endl;
        }
    }

};

#endif