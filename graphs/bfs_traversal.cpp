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

    //TC:O(V+E) :O(V C 2) :O(V^2)
    //SC:O(V)
    void BFS()
    {
        queue<int> q;
        vector<int> a(V,0);

        q.push(0);
        a[0]=1;

        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            cout<<front<<" ";
            for(int ele:l[front])
            {
                if(a[ele]!=1)
                {
                    a[ele]=1;
                    q.push(ele);
                }
                
            }

        }
        cout<<endl;
    }
};

int main()
{
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);

    g.BFS();
    
    return 0;
}