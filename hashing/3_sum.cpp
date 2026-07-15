#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> a={-1,0,1,2,-1,-4};
    //set<vector<int>> ans;
    int n=a.size();

    //brute force 
    //TC=O(n3*log(unique_triplets))
    //SC=O(unique_triplets)
    /*
    
    set<vector<int>> s;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(a[i]+a[j]+a[k]==0)
                {
                    vector<int> tv;
                    tv={a[i],a[j],a[k]};
                    sort(tv.begin(),tv.end());
                    s.insert(tv);
                }
            }
        }
    }

    if(!s.empty())
    {
        cout<<"solutions are:"<<endl;
        for(auto v:s)
        {
            for(auto ele:v)
            {
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<"No solution";
    }
*/


//Hashing (better approach)
//TC=O(n2*log(unique_triplets))
//SC=O(unique_triplets)

/*
int t;
unordered_set<int> s;
for(auto ele:a)
{
    s.insert(ele);
}
for(int i=0;i<n-1;i++)
{
    for(int j=i+1;j<n;j++)
    {
        s.erase(s.bucket(a[i]));
        s.erase(s.bucket(a[j]));
        t=-a[i]-a[j];
        if((s.find(t)!=s.end()))
        {
            vector<int> v={a[i],a[j],t};
            sort(v.begin(),v.end());
            ans.insert(v);

        }
        s.insert(a[i]);
        s.insert(a[j]);
    }
}

if(!ans.empty())
    {
        cout<<"solutions are:"<<endl;
        for(auto c:ans)
        {
            for(auto ele:c)
            {
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<"No solution";
    }
*/


//Two pointer approach(best)
//TC= n*logn + n²
//SC=O(unique_triplets)

set<vector<int>> ans;
int ansidx=0;
sort(a.begin(),a.end());
for(int i=0;i<n-2;i++)
{
    if(i>0 && a[i]==a[i-1])
        continue;
    
    int j=i+1;
    int k=n-1;
    while(j<k)
    {
        if((a[i]+a[j]+a[k])<0)
        {
            j++;
        }else if((a[i]+a[j]+a[k])>0)
        {
            k--;
        }else
        {
            ans.insert({a[i],a[j],a[k]});
            k--;j++;

            while(j<k && a[j]==a[j-1])
                j++;
            
        }
    }
}

for(auto b:ans)
{
    for(auto ele:b)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}

return 0;
}
    
