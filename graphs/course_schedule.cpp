#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool cycle_bfs(int src,vector<bool>& vis, vector<bool>& rePath,vector<vector<int>>& edges)
    {
        vis[src]=true;
        rePath[src]=true;

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][1];
            int v=edges[i][0];

            if(u==src)
            {
                if(!vis[v])
                {
                    if(cycle_bfs(v,vis,rePath,edges))
                    {
                        return true;
                    }
                }else if(rePath[v])
                {
                    return true;
                }   
            }
        }

        rePath[src]=false;
        return false;
    }
    
    //TC:O(V+E)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> rePath(numCourses,false);

        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(cycle_bfs(i,vis,rePath,prerequisites))
                {
                    return false;
                }
            }
        }

        return true;
    }
};