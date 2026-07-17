#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<char>>& m, int row, int col, int n)
{
    for(int j=0;j<n;j++)
    {
        if(m[row][j]=='Q')
            return false;
    }

    for(int i=0;i<n;i++)
    {
        if(m[i][col]=='Q')
            return false;
    }

    int r=row-1;
    int c=col-1;
    while(r>=0 && c>=0)
    {
        if(m[r][c]=='Q')
            return false;

        r--;
        c--;
    }

    r=row-1;
    c=col+1;
    while(r>=0 && c<n)
    {
        if(m[r][c]=='Q')
            return false;

        r--;
        c++;
    }

    return true;
}

void nqueens(vector<vector<char>>& m,int i, int n)
{
    if(i==n)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                if(m[x][y]=='Q')
                {
                    cout<<x<<" "<<y<<endl;
                }
                
            }
        }
        cout<<endl<<endl;
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(isSafe(m,i,j,n))
        {
            m[i][j]='Q';
            nqueens(m,i+1,n);
            m[i][j]=' ';
        }
    }

}

int main()
{
    
    int n=4;
    vector<vector<char>> m(n,vector<char>(n,' '));
    nqueens(m,0,n);
    return 0;
}