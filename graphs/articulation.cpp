#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfs(int u,int parU,vector<bool>& vis,vector<int>& low,vector<int>& dt,int& time)
    {
        vis[u]=true;
        low[u]=dt[u]=time++;
        int children=0;
        for(auto v:l[u])
        {
            if(!vis[v])
            {
                children++;
                dfs(v,u,vis,low,dt,time);
                low[u]=min(low[u],low[v]);

                if(parU!=-1 && low[v]>=dt[u])
                {
                    cout<<u<<" is an articulation point"<<endl;
                }
            }else if(v!=parU){
                low[u]=min(low[u],dt[v]);
            }
        }

        if(parU==-1 && children>1)
        {
            cout<<u<<" is an articulation point"<<endl;
        }
    }

    void articulationPointUsingTarjan()
    {
        int time=0;
        vector<bool> vis(V,false);
        vector<int> low(V);
        vector<int> dt(V);

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,vis,low,dt,time);
            }
        }
        
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);

    g.articulationPointUsingTarjan();
    return 0;
}