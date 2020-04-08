#include <iostream>
#include "game.h"
using namespace std;

Game::Game() : count(0), _player_1_symbol('O'), _player_2_symbol('X')
{
    _grid = vector<vector<int>>(3, vector<int>(3, -1));
}

Game::Game(char player_1_symbol, char player_2_symbol) : count(0), _player_1_symbol(player_1_symbol), _player_2_symbol(player_2_symbol)
{
    _grid = vector<vector<int>>(3, vector<int>(3, -1));
}

bool Game::_check_params_index(int i)
{
    if (0 <= i <= 2)
        return true;
    else
        return false;
}

bool Game::_check_params_player(int player)
{
    if (player == 1 || player == 2)
        return true;
    else
        return false;
}

int Game::check_if_marked(int i, int j)
{
    if (!_check_params_index(i) || !_check_params_index(j))
        return -1;
    if (_grid[i][j] == 0)
        return 0;
    else
        return 1;
}

int Game::markbox(int i, int j, int player)
{
    if (!_check_params_index(i) || !_check_params_index(j) || !_check_params_player(player))
        return -1;
    if (check_if_marked(i, j) == 1)
        return 0;
    _grid[i][j] = player;
    count++;
    return 1;
}

int Game::checkwin(int i, int j)
{
    //check keeping the row constant
    if (_grid[i][0] == _grid[i][1] && _grid[i][1] == _grid[i][2])
        return _grid[i][j];

    //check keeping the column constant
    if (_grid[0][j] == _grid[1][j] && _grid[1][j] == _grid[2][j])
        return _grid[i][j];

    //if box is the center grid, check diagonal
    if (i == 1 and j == 1)
    {
        if (_grid[0][0] == _grid[1][1] and _grid[1][1] == _grid[2][2])
            return _grid[i][j];
        if (_grid[2][0] == _grid[1][1] and _grid[1][1] == _grid[0][2])
            return _grid[i][j];
    }

    return 0;
}

ostream &operator<<(ostream &os, const Game &game)
{
    vector<vector<char>> grid(3, vector<char>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (game._grid[i][j])
            {
            case 1:
                grid[i][j] = game._player_1_symbol;
                break;

            case 2:
                grid[i][j] = game._player_2_symbol;
                break;

            default:
                grid[i][j] = ' ';
                break;
            }
        }
    }

    os << endl
       << "    1   2   3 " << endl
       << endl
       << "1   " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << " " << endl
       << "   -----------" << endl
       << "2   " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << " " << endl
       << "   -----------" << endl
       << "3   " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << " " << endl
       << endl;
    return os;
}
