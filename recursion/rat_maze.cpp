#include<bits/stdc++.h>
using namespace std;

bool valid(vector<vector<int>>& maze,int row, int col)
{

    int n=maze.size();

    if(row<0 || col<0 || row>=n || col>=n)
    {
        return false;
    }

    if(maze[row][col]==1)
    {
        return true;
    }

    return false;
}

void path(vector<vector<int>>& maze,int i, int j,string& way,vector<string>& ans)
{
    int n=maze.size();
    if(i==n-1 && j==n-1)
    {
        ans.push_back(way);
        return;
    }

    maze[i][j]=0;
    //left
    if(valid(maze,i,j-1))
    {
        way.push_back('L');
        path(maze,i,j-1,way,ans);
        way.pop_back();
    }

    //right
    if(valid(maze,i,j+1))
    {
        way.push_back('R');
        path(maze,i,j+1,way,ans);
        way.pop_back();
    }

    //up
    if(valid(maze,i-1,j))
    {
        way.push_back('U');
        path(maze,i-1,j,way,ans);
        way.pop_back();
    }

    //down
    if(valid(maze,i+1,j))
    {
        way.push_back('D');
        path(maze,i+1,j,way,ans);
        way.pop_back();
    }

    maze[i][j]=1;

}


//TC=O(4^(n*n))
int main()
{
    int count=0;
    vector<vector<int>> maze=
    {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    vector<string> ans;
    string way;
    path(maze,0,0,way,ans);

    for(auto str:ans)
    {
        cout<<str<<endl;
    }

    return 0;
}