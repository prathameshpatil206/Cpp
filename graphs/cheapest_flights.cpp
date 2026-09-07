#include<bits/stdc++.h>
using namespace std;


struct info
{
    int u;
    int pr;
    int st;
};

struct gf
{
    int u;
    int pr;
};
class Graph
{
    int V;
    list<gf> *l;
    public:

    Graph(int V)
    {
        this->V=V;
        l=new list<gf>[V];
    }

    void addEdge(int u,int v,int pr)
    {
        l[u].push_back({v,pr});
    }

    int bfs(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<info> q;
        vector<int> dist(n,INT_MAX);
        q.push({src,0,-1});
        dist[src]=0;

        while(!q.empty())
        {
            info curr=q.front();
            q.pop();

            for(gf path:l[curr.u])
            {
                if(dist[path.u]>curr.pr+path.pr && (curr.st+1<=k))
                {
                    dist[path.u]=curr.pr+path.pr;
                    q.push({path.u,curr.pr+path.pr,curr.st+1});
                }
                
            }


        }

        if(dist[dst]==INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};
class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        Graph g(n);

        for(auto v:flights)
        {
            g.addEdge(v[0],v[1],v[2]);
        }

        return g.bfs(n,flights,src,dst,k);
    }
};