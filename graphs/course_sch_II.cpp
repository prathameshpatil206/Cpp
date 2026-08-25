#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int>* l;

    public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    bool addEdge(int u, int v)
    {
        for(int ele:l[v])
        {
            if(ele==u)
            {
                return false;
            }
        }

        l[u].push_back(v);
        return true;
    }

    bool Cycle_dfs(int src,vector<bool>& vis,vector<bool>& rePath)
    {
        vis[src]=true;
        rePath[src]=true;

        for(auto v:l[src])
        {
            if(!vis[v])
            {
                if(Cycle_dfs(v,vis,rePath))
                {
                    return true;
                }
            }else{
                if(rePath[v])
                {
                    return true;
                }
            }
        }

        rePath[src]=false;
        return false;
    }

    bool detect_cycle()
    {
        vector<bool> vis(V,false);
        vector<bool> rePath(V,false);

        for(int i=0;i<V;i++)
        {
            if(Cycle_dfs(i,vis,rePath))
            {
                return true;
            }
        }

        return false;
    }

    void dfs(int src,vector<bool>& vis, stack<int>& q)
    {
        vis[src]=true;

        for(int v:l[src])
        {
            if(!vis[v])
            {
                dfs(v,vis,q);
            }
        }

        q.push(src);
    }

    vector<int> topologicalSort()
    {
        vector<bool> vis(V,false);
        stack<int> q;

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,q);
            }
        }

        vector<int> order={};
        while(!q.empty())
        {
            order.push_back(q.top());
            q.pop();
        }
        
        return order;
    }
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(auto edge:prerequisites)
        {
            bool value=g.addEdge(edge[1],edge[0]);
            if(value==false)
            {
                return {};
            }
        }

        if(g.detect_cycle())
        {
            return {};
        }

        return g.topologicalSort();
    }
};