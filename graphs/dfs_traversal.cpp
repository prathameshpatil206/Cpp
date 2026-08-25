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

    void print()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<" -> ";
            for(auto ele:l[i])
            {
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }

    void DFShelper(int src,vector<bool>& a)
    {
        cout<<src<<" ";
        a[src]=true;
        for(auto ele:l[src])
        {
            if(a[ele]!=true)
            {
                DFShelper(ele,a);
            }
        }
    }


    //TC:O(V+E)
    //SC:O(V)
    void DFS()
    {
        vector<bool> a(V,false);
        for(int i=0;i<V;i++)
        {
            if(a[i]!=true)
            {
                DFShelper(0,a);
            }
        }
        
        cout<<endl;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.DFS();
    return 0;
}