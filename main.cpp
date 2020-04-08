#include <iostream>
#include "game.h"
using namespace std;

int main()
{
    cout << "Please enter player 1 symbol" << endl;
    char p1symbol;
    cin >> p1symbol;
    cout << "Please enter player 2 symbol" << endl;
    char p2symbol;
    cin >> p2symbol;

    Game game(p1symbol, p2symbol);

    bool someone_won = false;
    while (game.count < 9)
    {
        cout << game;
        static int player = 1;

        //take input, markbox and check if someone won
        while (!someone_won)
        {
            int i, j;
            cout << "Player " << player << ", Please enter the box row number to mark" << endl;
            cin >> i;
            cout << "Player " << player << ", Please enter the box column number to mark" << endl;
            cin >> j;

            i--;
            j--; //decrease i, j by 1 because _grid index start from 0 but in user output it starts from 1

            int mark_result = game.markbox(i, j, player);
            if (mark_result == 0)
            {
                cout << "This box is already marked." << endl;
                continue;
            }
            else if (mark_result == -1)
            {
                cout << "The entered box numbers are not valid" << endl;
                continue;
            }
            else if (mark_result == 1)
                break;
            else
                cerr << "Some error has occured" << endl;

            if (game.checkwin(i, j))
            {
                cout << "Congratulations! Player " << player << " has won!" << endl;
                someone_won = true;
            }

            if (player == 1)
                player = 2;
            else
                player = 1;
        }

        if (someone_won)
            break;
    }

    if (!someone_won)
        cout << "The game ended in a draw!" << endl;
}