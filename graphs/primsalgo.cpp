#include<bits/stdc++.h>
using namespace std;


//TC:O(E*logV)
class edgePoint{
    public:
    int neigh;
    int weight;

    bool operator>(const edgePoint& other)const
    {
        return this->weight>other.weight;
    }
};

class Graph
{
    int V;
    list<edgePoint> *l;

    public:
    Graph(int V)
    {
        this->V=V;
        l=new list<edgePoint>[V];
    }

    void addEdge(int u, int v,int w)
    {
        l[u].push_back({v,w});
        l[v].push_back({u,w});
    }

    void primsMST()
    {
        priority_queue<edgePoint,vector<edgePoint>,greater<edgePoint>> pq;

        pq.push({0,0});
        int mstSum=0;
        vector<bool> vis(V,false);

        while(!pq.empty())
        {
            edgePoint top=pq.top();
            pq.pop();

            if(vis[top.neigh])
            {
                continue;
            }

            vis[top.neigh]=true;
            mstSum=mstSum+top.weight;

            for(edgePoint e:l[top.neigh])
            {
                if(vis[!e.neigh])
                {
                    pq.push({e.neigh,e.weight});
                }
            }
        }

        cout<<mstSum<<endl;
    }

};

int main()
{
    int V=5;
    Graph g=Graph(V);
    g.addEdge(0,1,25);
    g.addEdge(1,2,1);
    g.addEdge(2,3,40);
    g.addEdge(3,4,1);
    g.addEdge(0,3,1);
    g.addEdge(1,3,3);

    g.primsMST();


    return 0;
}