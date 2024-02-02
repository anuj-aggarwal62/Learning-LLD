#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

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

    void move(Player* player,int i,int j)
    {
        if(board->isValidMove(i,j))
        {
            if(board->move(player,i,j))
            {
                complete = true;
                win = player;
            }
        }
        else
        {
            cout<<"Invalid Move"<<endl;
            exit(0);
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
            if(check)`
            {
                cout<<"Enter your move "<<p1->name<<endl;
                cin>>i>>j;
                game->move(p1,i,j);
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

int main()
{
    GameEngine ttt;

    ttt.start();

    Player* winner = ttt.play();

    cout<<"Winner of the game is "<<winner->name<<endl;


}