#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int rep_val;

    vector<vector<int>> a={{9,1,7},{8,9,2},{3,4,6}};
    int sum=0, n=a.size();
    for(auto b:a)
    {
        for(auto ele:b)
        {
            if(s.find(ele)!=s.end())
            {
                rep_val=ele;
                continue;
            }
            sum=sum+ele;
            s.insert(ele);
        }
    }

    
    int missing_val=n*n*(n*n+1)/2-sum;

    cout<<"rep_val = "<<rep_val<<endl;
    cout<<"miss_val = "<<missing_val<<endl;
    return 0;
}