#include<bits/stdc++.h>
using namespace std;


class DSU
{
    int n;
    vector<int> par;
    vector<int> rank;

    public:
    
    DSU(int n)
    {
        this->n=n;
        
        for(int i=0;i<n;i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    //TC:O(1);
    void _union_(int a, int b)
    {
        int parA=find(a);
        int parB=find(b);

        if(parA==parB)
        {
            return;
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

    //TC:O(1)
    int find(int a)
    {
        if(par[a]==a)
        {
            return a;
        }

        int parent= find(par[a]);
        par[a]=parent;
        return parent;
    }

    void getinfo()
    {
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<par[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<rank[i]<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    DSU d=DSU(6);
    d.getinfo();
    cout<<d.find(1)<<endl;
    d._union_(0,1);
    d.getinfo();
    d.find(1);

    d._union_(4,5);
    d.getinfo();
    d._union_(1,5);

    d.getinfo();
    cout<<d.find(5)<<endl;
    cout<<d.find(4)<<endl;
    cout<<d.find(1)<<endl;


    return 0;
}