#include <vector>
#include <iostream>
using namespace std;

class Game
{
private:
    // it stores players input
    // 0 means not used, 1 means player1, 2 means player2
    vector<vector<int>> _grid;

    char _player_1_symbol;
    char _player_2_symbol;

    // @return true if index is within range, else false
    // @param i correspond to grid index
    bool _check_params_index(int i);

    // @return true if index is within range, else false
    // @param player correspond to player number
    bool _check_params_player(int player);

public:
    //keeps a count of no of grids marked
    int count;

    //intialises with player 1 symbol O and player 2 symbol X
    Game();

    //intialises with the given player symbols
    Game(char player_1_symbol, char player_2_symbol);

    /* 
    * @return 1 for already marked
    * 0 for not marked
    * -1 for error in params
    */
    int check_if_marked(int i, int j);

    /*
    * @returns 1 for success
    * 0 for already marked
    * -1 for error in params
     */
    int markbox(int i, int j, int player);

    /* 
    * It can be called at the end of the game or in between
    * @return player number who has won 
    * or 0 when none of them won
    * @params last move grid coordinates
    */
    int checkwin();

    //overload << operator so as to use cout
    friend ostream &operator<<(ostream &os, const Game& game);

};
