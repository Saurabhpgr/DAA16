#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isSafe(vector<string> &board, int row, int col, int n) 
    {
        for (int i = 0; i <= row; i++)
        {
            // Vertical
            if (board[i][col] == 'Q')
                return false;

            // Left diagonal
            if (col - i >= 0 && board[row - i][col - i] == 'Q')
                return false;

            // Right diagonal
            if (col + i < n && board[row - i][col + i] == 'Q')
                return false;
        }

        return true;
    }

    bool nQueens(vector<string> &board, int row, int n) 
    {
        if (row == n)
            return true;

        for (int j = 0; j < n; j++) 
        {
            if (isSafe(board, row, j, n)) 
            {
                board[row][j] = 'Q';

                if (nQueens(board, row + 1, n))
                    return true;

                board[row][j] = '.';
            }
        }

        return false;
    }

    void printBoard(vector<string> &board) 
    {
        cout << "\nSolution:\n\n";

        for (string row : board) 
        {
            cout << row << endl;
        }
    }

    void solveNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));

        if (nQueens(board, 0, n))
            printBoard(board);
        else
            cout << "\nNo solution exists.\n";
    }
};

int main() 
{
    int n;

    while (true) 
    {
        cout << "Enter value of N: ";
        cin >> n;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Enter integer only.\n";
        }
        else if (n <= 0) 
        {
            cout << "N must be greater than 0.\n";
        }
        else if (n == 2 || n == 3) 
        {
            cout << "No solution exists for N = " << n << ".\n";
        }
        else 
        {
            break;
        }
    }

    Solution obj;

    obj.solveNQueens(n);

    return 0;
}



/*for (int j = 0; j < n; j++) 
        {
            if (board[row][j] == 'Q')
                return false;
        }*/

        /*for (int i = 0; i < n; i++) 
        {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) 
        {
            if (board[i][j] == 'Q')
                return false;
        }*/