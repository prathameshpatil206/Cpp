#include<bits/stdc++.h>
using namespace std;

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

    int MST()
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

        return minSum;
    }
};

struct point
{
    int x;
    int y;
};


class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n=points.size();
        unordered_map<int,point> m;
        Graph g(n);
        for(int i=0;i<n;i++)
        {
            vector<int> p=points[i];
            m[i]={p[0],p[1]};
        }

        for(int i=0;i<n;i++)
        {
            point A=m[i];
            for(int j=i+1;j<n;j++)
            {
                point B=m[j];

                g.addEdge(i,j,abs(A.x-B.x)+abs(A.y-B.y));
            }
        }

        return g.MST();
};

};