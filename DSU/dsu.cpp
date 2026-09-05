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

};

int main()
{
    
    return 0;
}