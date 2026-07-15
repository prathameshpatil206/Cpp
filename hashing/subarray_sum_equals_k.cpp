#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a={9,4,20,3,10,5};
    int n=a.size();
    int tar=33;
    set<vector<int>> ans; 

    //TC=n^2

    /*
    int st=0,i;
    int sum;
    while(st<n-1)
    {
        i=st+1;
        
        sum=a[st];
        while(i<n && sum<tar)
        {
            sum=sum+a[i];
            i++;
        }

        if(sum==tar)
        {
            vector<int> vec;
            for(int j=st;j<i;j++)
            {
                vec.push_back(a[j]);
            }
            ans.insert(vec);
        }
            
        st++;
        
    }
    */


    //TC=O(n)
    //SC=O(n)
    vector<int> ps;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        ps.push_back(sum);
    }

    unordered_map<int,int> m;
    int count=0;
    for(int i=0;i<n;i++)
    {
        
        int key=ps[i]-tar;
        if(key==0)
            count++;
        if(m.find(key)!=m.end())
        {
            count=count+m[key];
            
        }

        if(m.find(ps[i])==m.end())
        {
            m[ps[i]]=0;
        }

        m[ps[i]]++;
        
    }

    /*

    for(auto v:ans)
    {
        for(auto ele:v)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    
    */

    cout<<"Count: "<<count<<endl;
    return 0;
}

/*
    count=2
    a=[9,4,20,3,10,5]
    tar=33
    ps=[9,13,33,36,46,51]
    
    m=[(9,1)(13,1)(33,1)(36,1)(46,1)(51,1)]    

*/