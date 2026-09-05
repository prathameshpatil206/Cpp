#include<bits/stdc++.h>
using namespace std;

struct info
{
    int u;
    int v;
};


//TC:O(n^2)
class Solution {
public:

    int find(int u,vector<int>& par)
    {
        if(par[u]==u)
        {
            return u;
        }

        return par[u]=find(par[u],par);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<info> edges;
        int n=isConnected.size();
        vector<vector<int>>& a=isConnected;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(a[i][j]==1)
                    {
                        edges.push_back({i,j});
                        a[j][i]=0;
                    }
                }
            }
        }


        vector<int> par;
        vector<int> rank(n,0);
        for(int i=0;i<n;i++)
        {
            par.push_back(i);
        }

        for(info ed:edges)
        {
            int parA=find(ed.u,par);
            int parB=find(ed.v,par);

            if(parA==parB)
            {
                continue;
            }

            if(rank[parA]==rank[parB])
            {
                par[parB]=parA;
                rank[parA]++;
            }else if(rank[parA]>rank[parB])
            {
                par[parB]=parA;
            }else{
                par[parA]=parB;
            }

        }

        int provs=0;
        for(int i=0;i<n;i++)
        {
            if(par[i]==i)
            {
                provs++;
            }
        }

        return provs;

    }


};