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
        l[v].push_back(u);
    }

    bool det_cycle(int src, vector<bool>& vis, int par)
    {
        vis[src]=true;

        for(auto v:l[src])
        {
            if(par!=v)
            {
                if(vis[v]==true)
                {
                    return true;
                }else{
                    if(det_cycle(v,vis,src))
                    {
                        return true;
                    }
                }
            }
            
        }

        return false;
    }

    //TC:O(V+E)
    void detectCycle()
    {
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(det_cycle(i,vis,-1))
                {
                    cout<<"Cycle detected"<<endl;
                    return;
                }
            }
        }

        cout<<"Cycle not present"<<endl;
    
    }

};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.detectCycle();
    return 0;
}