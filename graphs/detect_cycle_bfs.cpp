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

    void addEdge(int u,int v)
    {

        l[u].push_back(v);
        l[v].push_back(u);
    }

    //TC:O(V+E)
    bool isCycleBFS(int src,vector<bool>& vis)
    {
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=true;
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();

            for(int v:l[curr.first])
            {
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push({v,curr.first});
                }else{
                    if(v!=curr.second)
                    {
                        return true;
                    }
                }
                
            }

        }

        return false;

    }

    bool isCycle()
    {
        vector<bool> vis(V,false);

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(isCycleBFS(i,vis))
                {
                    return true;
                }
            }
            
        }
        
        return false;
    }

};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,4);

    cout<<g.isCycle()<<endl;
    
    return 0;
}