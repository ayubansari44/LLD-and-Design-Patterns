#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// The solution uses Backtracking to solve the Sudoku puzzle. It tries filling each empty cell with a valid number (1 to 9) and checks whether the placement is valid using the isSafe function.

class Solution {
public:
    
    // The isSafe function ensures that the number being placed in the cell doesn't violate Sudoku rules: it checks the current row, column, and 3x3 subgrid for any duplicate numbers.
    
    bool isSafe(vector<vector<char>>& board, int row, int col, char currCharacter)
    {
        //Checking currCharacter already existing in current row
        for(int j=0;j<9;j++)
        {
            if(board[row][j] == currCharacter)
                return false;
        }
        
        //Checking currCharacter already existing in current column
        for(int i=0;i<9;i++){
            if(board[i][col] == currCharacter)
                return false;
        }
        
        ////Checking currCharacter already existing in 3X3 sub-boxes
        for(int i=0;i<9;i++)
        {
            if(board[3 * (row/3 )+ i/3][3 * (col/3) + i%3] == currCharacter)
                return false;
        }
        
        //currCharacter is a valid number in Sudoku hence return true
        return true;
    }
    
    
    // The solveSudoku function performs the recursive backtracking. It fills empty cells one by one, backtracks if a valid solution cannot be found, and tries the next number.
    
    bool solveSudoku(vector<vector<char>>& board)
    {
        //Iterate over every cell and check if our answer 
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                //Fill the cell only if it's empty
                if(board[i][j] == '.')
                {
                    //Fill every element from 1-9 and check if Sudoku is valid
                    for(char ch='1';ch<='9';ch++)
                    {
                        //Check if current character is valid
                        if(isSafe(board, i, j, ch))
                        {
                            board[i][j] = ch;
                            bool nextAnswer = solveSudoku(board);
                            
                            //our answer is true hence check for next cell.
                            if(nextAnswer == true)
                                return true;

                            //backtrack and reset to initial value
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    //Take a 2D vector as input where "." cell signifies an empty cell.
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    cout<<"Input Sudoku:"<<endl;
    for (const auto& row : board) 
        {
            for (const auto& cell : row) 
            {
                cout << cell << " ";
            }
            cout << endl;
    }
    
    //Call Sudoku solver method
    Solution sol;
    bool isValidSudoku = sol.solveSudoku(board);
    
    //The given Sudoku is valid
    if(isValidSudoku)
    {
        cout<<endl<<"Sudoku after filling empty cells:"<<endl;
        for (const auto& row : board) 
        {
            for (const auto& cell : row) 
            {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
    
    //The given Sudoku is not valid
    else{
        cout<<endl<<"The given Sudoku in the input is not Valid!";
    }
}
