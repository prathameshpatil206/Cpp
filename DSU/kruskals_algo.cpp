#include<bits/stdc++.h>
using namespace std;


//TC:O(E*logE)
struct info
{
    int u;
    int v;
    int w;

    bool operator>(const info& other)const
    {
        return this->w>other.w;
    }
};

class Graph
{
    int n;
    priority_queue<info,vector<info>,greater<info>> pq;

public:

    Graph(int n)
    {
        this->n=n;
    }

    void addEdge(int u,int v,int w)
    {
        pq.push({u,v,w});
    }

    int find(int u,vector<int>& par)
    {
        if(par[u]==u)
        {
            return u;
        }

        return par[u]=find(par[u],par);
    }

    void MST()
    {
        vector<int> par;
        for(int i=0;i<n;i++)
        {
            par.push_back(i);
        }
        vector<int> rank(n,0);
        int minSum=0;
        int count=1;
        
        while(!pq.empty() && count!=n)
        {
            auto curr=pq.top();
            pq.pop();

            int parA=find(curr.u,par);
            int parB=find(curr.v,par);

            if(parA==parB)
            {
                continue;
            }

            minSum += curr.w;
            count++;
            if(rank[parA]==rank[parB])
            {
                par[parB]=parA;
                rank[parA]++;
            }else if(rank[parA]>rank[parB]){
                par[parB]=parA;
            }else{
                par[parA]=parB;
            }
        }
        cout<<endl<<"MinSum : "<<minSum<<endl;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1,6);
    g.addEdge(0,3,4);
    g.addEdge(0,2,1);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(2,3,5);

    g.MST();

    return 0;
}