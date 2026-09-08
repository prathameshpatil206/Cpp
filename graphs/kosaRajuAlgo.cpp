#include<bits/stdc++.h>
using namespace std;

//TC:O(V+E)
class Graph{
    int V;
    list<int> *l;
    list<int> * tr;

public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
        tr=new list<int>[V];
    }

    void addEdge(int u,int v)
    {
        l[u].push_back(v);
        tr[v].push_back(u);
    }

    void dfs(int u,vector<bool>& vis,stack<int>& s)
    {
        vis[u]=true;
        for(auto ne:l[u])
        {
            if(!vis[ne])
            {
                dfs(ne,vis,s);
            }
        
        }

        s.push(u);
    }

    void dfsOnTranspose(int u,vector<bool>& tr_vis)
    {
        tr_vis[u]=true;
        cout<<u<<" ";
        for(auto ne:tr[u])
        {
            if(!tr_vis[ne])
            {
                dfsOnTranspose(ne,tr_vis);
            }
        }

    }

    void stronglyConnectedComponents()
    {
        vector<bool> vis(V,false);
        stack<int> s;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(0,vis,s);
            }
        }
        
        vector<bool> tr_vis(V,false);
        while(!s.empty())
        {
            int curr=s.top();
            s.pop();
            if(!tr_vis[curr])
            {
                dfsOnTranspose(curr,tr_vis);
                cout<<endl;
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(1,0);

    g.stronglyConnectedComponents();
   
    return 0;
}