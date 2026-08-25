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

    bool det_cycle(int src, vector<bool>& vis,vector<bool>& rePath)
    {
        vis[src]=true;
        rePath[src]=true;
        for(int v:l[src])
        {
            if(!vis[v])
            {
                if(det_cycle(v,vis,rePath))
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

    //TC:O(V+E)
    void detectCycle()
    {
        vector<bool> vis(V,false);
        vector<bool> rePath(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(det_cycle(i,vis,rePath))
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
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(2,1);
    g.addEdge(2,5);
    g.addEdge(3,4);
    g.addEdge(4,2);

    g.detectCycle();
    return 0;
}