#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

char board[ROWS][COLS] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'}};
int row = 0;
int column = 0;

    // For printing the board.
void displayBoard()
{
    system("cls");

    cout << "\tPLAYER - 1 [X] \t PLAYER - 2 [O]" << endl << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "\t\t     |     |     " << endl << endl;
}

// Function to get the player input and update the board.
void positionTaken(char &mark)
{
    int boxChoice;

    do {
        if (mark == 'X')
            cout << "Player - 1 (X) choose a box: ";

        else if (mark == 'O')
            cout << "Player - 2 (O) choose a box: ";

        cin >> boxChoice;

        switch (boxChoice) {
            case 1:
                row = 0;
                column = 0;
                break;
            case 2:
                row = 0;
                column = 1;
                break;
            case 3:
                row = 0;
                column = 2;
                break;
            case 4:
                row = 1;
                column = 0;
                break;
            case 5:
                row = 1;
                column = 1;
                break;
            case 6:
                row = 1;
                column = 2;
                break;
            case 7:
                row = 2;
                column = 0;
                break;
            case 8:
                row = 2;
                column = 1;
                break;
            case 9:
                row = 2;
                column = 2;
                break;
            default:
                cout << "Invalid choice" << endl << endl;
        }
    } while (boxChoice < 1 || boxChoice > 9);

    if (mark == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = mark;
        mark = 'O';
    }
    else if (mark == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = mark;
        mark = 'X';
    }

    else //if (board[row][column] == 'X' && board[row][column] == 'O')
    {
        cout << "POSITION TAKEN!" << endl << endl;
        positionTaken(mark);
    }

    displayBoard();
}

    // For checking whether someone has won, lost, or drawn the game.
int gameStatus()
{
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] == 'X'))
            //if (mark = 'X')
            return 1;

            //else if (mark = 'O')
        else if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] == 'O'))
            return 2;
    }

    for (int i = 0; i < 3; i++) {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] == 'X'))
            return 1;

        else if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] == 'O'))
            return 2;
    }

    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] == 'X'))
        return 1;

    else if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] == 'O'))
        return 2;

    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] == 'X'))
        return 1;

    else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] == 'O'))
        return 2;

        // Check if all possible boxes were entered (check if match is a draw).
    if ((board[0][0] != '1') && (board[0][1] != '2') && (board[0][2] != '3') &&
        (board[1][0] != '4') && (board[1][1] != '5') && (board[1][2] != '6') &&
        (board[2][0] != '7') && (board[2][1] != '8') && (board[2][2] != '9'))
        return 0;

    return -1;
}

int main()
{
    char mark = 'X';
    int status; // 1 represents player 1.
                // 2 represents player 2.
                // 0 represents draw.
                // -1 represents no outcome for the match currently.

    do {
        displayBoard();
        positionTaken(mark);
        status = gameStatus();
    } while (status == -1);

    if (status == 1)
        cout << "Congratulations Player - 1[X]! YOU WIN!" << endl;
    else if (status == 2)
        cout << "Congratulations Player - 2[O]! YOU WIN!" << endl;
    else if (status == 0)
        cout << "DRAW!" << endl;

    return 0;
}
