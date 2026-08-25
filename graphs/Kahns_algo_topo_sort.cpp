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
    }

    void dfs(int src,vector<bool>& vis, stack<int>& q)
    {
        vis[src]=true;

        for(int v:l[src])
        {
            if(!vis[v])
            {
                dfs(v,vis,q);
            }
        }

        q.push(src);
    }

    //TC:O(V+E)
    void kahnsAlgo()
    {
        vector<int> indegree(V,0);
        stack<int> q;
        vector<int> ans;

        for(int i=0;i<V;i++)
        {
            for(int v:l[i])
            {
                indegree[v]++;
            }

        }

        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int curr=q.top();
            q.pop();
            ans.push_back(curr);

            for(int v:l[curr])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }

        }

        if(ans.size()!=V)
        {
            cout<<"Graph is not directed and Acyclic."<<endl;
            return;
        }

        for(auto ele:ans)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0,6);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,2);
    //g.addEdge(3,1); --> not DAG

    g.kahnsAlgo();
    return 0;
}