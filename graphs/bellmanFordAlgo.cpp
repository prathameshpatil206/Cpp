#include<bits/stdc++.h>
using namespace std;

//TC:O(V*E)

//cannot use in case of negative weighted cycles

class Edge
{
public:
    int neigh;
    int weight;


    Edge(int n,int w)
    {
        this->neigh=n;
        this->weight=w;
    }
};

struct info{
    int weight;
    int node;

    bool operator>(const info& other) const
    {
        return weight>other.weight;
    }
};

int main()
{
    int V=5;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(4,-1));
    g[1].push_back(Edge(2,-4));

    g[2].push_back(Edge(3,2));

    g[3].push_back(Edge(4,4));

    vector<int> dist(V,INT_MAX);
    dist[0]=0;

    for(int i=0;i<V-1;i++)
    {
        for(int u=0;u<V;u++)
        {
            for(Edge e:g[u])
            {
                int dist_from_u=dist[u]+e.weight;
                if(dist_from_u<dist[e.neigh])
                {
                    dist[e.neigh]=dist_from_u;
                }
            }
        }
    }

    for(int i=0;i<dist.size();i++)
    {
        cout<<i<<" --> "<<dist[i]<<endl;
    }

    return 0;
}