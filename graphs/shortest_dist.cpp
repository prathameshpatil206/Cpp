#include<bits/stdc++.h>
using namespace std;

struct info{
    int val;
    int weight;
};

class Graph
{
    int V;
    list<info> *l;

    public:

    Graph(int V)
    {
        this->V=V;
        l=new list<info>[V];
    }

    void addEdge(int u,int v,int weight)
    {
        l[u].push_back({v,weight});
    }

    void dfs(info src,int dist,unordered_map<int,int>& m)
    {
        if(m.find(src.val)==m.end())
        {
            m[src.val]=dist;
        }else{
            if(m[src.val]<=dist)
            {
                return;
            }
            m[src.val]=dist;
        }
        

        for(info v:l[src.val])
        {
            dfs(v,dist+v.weight,m);
        }
    }

    void shortest_distance()
    {
        unordered_map<int,int> m;

        dfs({0,0},0,m);

        for(auto ele:m)
        {
            cout<<ele.first<<" --> "<<ele.second<<endl;
        }
    }


};

int main()
{
    Graph g(6);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);
    g.addEdge(4,3,2);
    g.addEdge(3,5,1);
    g.addEdge(4,5,5);
    
    g.shortest_distance();

    return 0;
}