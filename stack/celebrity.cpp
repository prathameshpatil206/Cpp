#include<bits/stdc++.h>
using namespace std;

//TC:O(n);
//SC:O(1);

int main()
{
    vector<vector<int>> a={{0,1,0},{0,0,0},{0,1,0}} ;
    int n=a.size();
    stack<int> s;
    s.push(0);
    s.push(1);
    int i,j;
    while(s.size()>1)
    {
        j=s.top();
        s.pop();
        i=s.top();
        s.pop();
        if(a[i][j]==0)
        {
            s.push(i);
        }else{
            s.push(j);
        }

        if(j<n-1)
        {
            s.push(++j);
        }
    }

    int cel=s.top();
    for(i=0;i<n;i++)
    {
        if(i!=cel && (a[i][cel]==0 || a[cel][i]==1))
        {
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<cel<<endl;
    return 0;
}