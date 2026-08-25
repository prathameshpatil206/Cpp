#include<bits/stdc++.h>
using namespace std;

struct pos{
    int r;
    int c;
};

class Solution {
public:

    void change_grid(int i, int j,vector<vector<int>>& grid,int m, int n,queue<pos>& q){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==2 || grid[i][j]==0)
        {
            return;
        }

        grid[i][j]=2;
        q.push({i,j});
    }


    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pos> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }

        q.push({-1,-1});
        int mins=0;

        while(!q.empty())
        {
            pos curr=q.front();
            q.pop();

            if(curr.r==-1)
            {
                if(!q.empty())
                {
                    mins++;
                    q.push({-1,-1});
                }

                continue;
                
            }
            change_grid(curr.r-1,curr.c,grid,m,n,q);
            change_grid(curr.r+1,curr.c,grid,m,n,q);
            change_grid(curr.r,curr.c-1,grid,m,n,q);
            change_grid(curr.r,curr.c+1,grid,m,n,q);
            
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        return mins;
    }
};