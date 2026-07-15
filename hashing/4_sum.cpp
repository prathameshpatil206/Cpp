#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a={-2,-1,-1,1,1,2,2};
    int tar=0;
    int n=a.size();
    set<vector<int>> ans;

    //TC=n^4
    /*
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                for(int l=k+1;l<n;l++)
                    {
                        vector<int> b={a[i],a[j],a[k],a[l]};
                        sort(b.begin(),b.end());
                        ans.insert(b);
                    }
    */


    //TC=O(n^3 + nlogn)
    sort(a.begin(),a.end());
    int i=0,j=1,k=2,l=n-1;

    while(i<n-2)
    {
        j=i+1;
        while(j<n-1)
        {
            k=j+1;
            
            l=n-1;
            while(k<l)
            {
                int sum=a[i]+a[j]+a[k]+a[l];
                if(sum>tar)
                {
                    l--;
                }else if(sum<tar)
                {
                    k++;
                }else{
                    vector<int> b={a[i],a[j],a[k],a[l]};
                    sort(b.begin(),b.end());
                    ans.insert(b);
                    k++;
                    l--;
                    while(k<l&& a[k]==a[k-1])
                        k++;
                }
                
            }

            j++;
            while(j<n-1 && a[j]==a[j-1])
            {
                j++;
            }
        }
        
        i++;
        while(i<n-2 && a[i]==a[i-1])
        {
            i++;
        }
    }


    if(ans.size()==0)
    {
        return 0;
    }

    for(auto v:ans)
    {
        for(auto ele:v)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
        
    return 0;
}