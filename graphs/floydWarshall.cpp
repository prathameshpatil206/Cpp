#include<bits/stdc++.h>
using namespace std;

struct info{
    int nh;
    int wt;
};

class Graph{
    int V;
    list<info> *l;

public:
    Graph(int V){
        this->V=V;
        l=new list<info>[V];
    }

    void addEdge(int u,int v,int wt)
    {
        l[u].push_back({v,wt});
    }

    //TC:O(V^3)
    void FloydWarshallAlgo()
    {
        const int INF=1e9;
        vector<vector<int>> dist(V,vector<int>(V,INF));
        for(int i=0;i<V;i++)
        {
            dist[i][i]=0;
            for(auto ed:l[i])
            {
                dist[i][ed.nh]=ed.wt;
            }
        }

        for(int k=0;k<V;k++)
        {
            for(int i=0;i<V;i++)
            {
                for(int j=0;j<V;j++)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i!=j && dist[i][j]!=INF)
                {
                    cout<<i<<" --> "<<j<<" : "<<dist[i][j]<<endl;
                }
            }
        }

        //check if the graph has negative weighted cycle.
        for(int i=0;i<V;i++)
        {
            if(dist[i][i]<0)
            {
                cout<<"Negative weighted cycle detected"<<endl;
                break;
            }
        }
    }
    
    
};

int main()
{
    Graph g(4);
    g.addEdge(0,1,4);
    g.addEdge(0,2,11);
    g.addEdge(1,2,2);
    g.addEdge(2,3,3);
    g.addEdge(1,3,8);

    g.FloydWarshallAlgo();
    return 0;
}