#include<bits/stdc++.h>
using namespace std;
int n=9;

bool present(vector<vector<char>>& board,int row,int num)
{
    char cnum=num+'0';
    for(int i=0;i<n;i++)
    {
        if(board[row][i]==cnum)
        {
            return true;
        }
    }

    return false;
}

bool place(vector<vector<char>>& board,int row,int col,int num)
{
    char cnum=num+'0';
    for(int i=0;i<n;i++)
    {
        if(board[i][col]==cnum)
        {
            return false;
        }
    }

    for(int j=0;j<n;j++)
    {
        if(board[row][j]==cnum)
        {
            return false;
        }
    }


    int rst=(row/3)*3;
    int cst=(col/3)*3;
    for(int i=rst;i<(rst+3);i++)
    {
        for(int j=cst;j<(cst+3);j++)
        {
            if(board[i][j]==cnum)
            {
                return false;
            }
        }
    }

    return true;
}

bool sudoku(vector<vector<char>>& board,int i,int num)
{

    if(i==n)
    {
        cout<<endl;
        for(auto v:board)
        {
            for(auto ele:v)
            {
                cout<<ele<<"\t";
            }
            cout<<endl;
        }
        
        return true;
    }

    if(num==10)
    {
        
        sudoku(board,i+1,1);
        return false;
    }

    if(present(board,i,num))
    {
        sudoku(board,i,num+1);
        return false;
    }

    
    for(int j=0;j<n;j++)
    {
        if(board[i][j]!='.')
        {
            continue;
        }
        if(place(board,i,j,num))
        {
            board[i][j]=num+'0';
            if(sudoku(board,i,num+1))
            {
                return true;
            }
            board[i][j]='.';
        }
    }

    return false;
}


//TC=O(9^(empty cells))
int main()
{
    vector<vector<char>> board=
    {
        {'7','3','.','.','1','2','.','9','.'},
        {'.','.','.','.','4','.','.','.','.'},
        {'9','.','.','.','.','.','5','.','.'},
        {'.','.','8','.','.','.','.','.','6'},
        {'.','1','.','.','9','3','.','5','.'},
        {'.','.','.','7','.','.','.','.','.'},
        {'.','.','.','4','.','.','.','2','.'},
        {'.','7','.','5','.','.','.','.','.'},
        {'.','.','1','.','2','7','8','.','.'}
    };

    sudoku(board,0,1);

    return 0;
}