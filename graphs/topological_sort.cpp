#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
public:
    Graph(int V)
    {
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
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

    //TC:O(V+E)
    void topologicalSort()
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

        while(!q.empty())
        {
            cout<<q.top()<<" ";
            q.pop();
        }
        cout<<endl;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0,6);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);

    g.topologicalSort();
    return 0;
}