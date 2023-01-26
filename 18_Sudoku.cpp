#include <bits/stdc++.h>
using namespace std;

#define Size 9

bool usedInRow(vector<vector<int>> &sudoku, int row, int fill)
{
    for (int i = 0; i < Size; i++)
    {
        if (sudoku[row][i] == fill)
        {
            return true;
        }
    }
    return false;
}

bool usedInCol(vector<vector<int>> &sudoku, int col, int fill)
{
    for (int i = 0; i < Size; ++i)
    {
        if (sudoku[i][col] == fill)
        {
            return true;
        }
    }
    return false;
}

bool usedInBox(vector<vector<int>> &sudoku, int row, int col, int fill)
{
    row = row - row % 3;
    col = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[row + i][col + j] == fill)
            {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(vector<vector<int>> &sudoku, int row, int col, int fill)
{
    return (!usedInRow(sudoku, row, fill) &&
            !usedInCol(sudoku, col, fill) &&
            !usedInBox(sudoku, row, col, fill));
}

bool isEmpty(vector<vector<int>> &sudoku, int &row, int &col)
{
    for (row = 0; row < Size; row++)
    {
        for (col = 0; col < Size; col++)
        {
            if (sudoku[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(vector<vector<int>> &sudoku)
{
    int row, col;
    if (!isEmpty(sudoku, row, col))
    {
        return true;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(sudoku, row, col, i))
        {
            sudoku[row][col] = i;
            if (solveSudoku(sudoku))
            {
                return true;
            }
            // backtracking
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (solveSudoku(grid) == true)
        for (vector<int> row : grid)
        {
            for (int cell : row)
            {
                cout << cell << "\t";
            }
            cout << "\n";
        }
    else
        cout << "No solution exists";

    return 0;
}
