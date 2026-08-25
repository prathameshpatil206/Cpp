#include<bits/stdc++.h>
using namespace std;


//TC:O((V+E)*logV)
//SC:O(V+E)
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
    vector<vector<Edge>> g(6);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(3,7));
    g[1].push_back(Edge(2,1));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));

    vector<int> dist(6,INT_MAX);
    priority_queue<info,vector<info>,greater<info>> pq;
    dist[0]=0;
    pq.push({0,0});

    while(!pq.empty())
    {
        info curr=pq.top();
        pq.pop();

        for(Edge neighbr:g[curr.node])
        {
            int dist_from_curr=dist[curr.node]+neighbr.weight;
            if(dist_from_curr<dist[neighbr.neigh])
            {
                dist[neighbr.neigh]=dist_from_curr;
                pq.push({dist[curr.node]+neighbr.weight,neighbr.neigh});
            }
        }

    }

    for(int i=0;i<dist.size();i++)
    {
        cout<<i<<" --> "<<dist[i]<<endl;
    }

    return 0;
}