#include<bits/stdc++.h>
using namespace std;


void permutation(string& a,int idx,vector<string>& prmts)
{

    int n=a.size();
    if(idx==n)
    {
        prmts.push_back(a);
        return;
    }

    for(int i=idx;i<n;i++)
    {
        swap(a[idx],a[i]);
        permutation(a,idx+1,prmts);
        swap(a[idx],a[i]);
    }
}


//TC=O(n! * n)
//SC=O(n!)
int main()
{
    string a="abc";
    vector<string> prmts;
    permutation(a,0,prmts);

    for(auto v:prmts)
    {
        cout<<v<<endl;
    }

    return 0;
}
