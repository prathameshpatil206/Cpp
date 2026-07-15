#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a={5,2,11,7,15};
    int tar=9;

    //Brute force approach
    /*
    TC=O(n*n)
    for(int i=0;i<a.size()-1;i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(a[i]+a[j]==tar)
            {
                cout<<i<<" "<<j<<endl;
                exit(0);
            }
        }
    }

    cout<<"no solution";
    */


    //better approach
    //TC=O(nlogn)
    /*
    sort(a.begin(),a.end());

    int st=0,end=a.size()-1;
    int sum;
    while(st<end)
    {
        sum=a[st]+a[end];
        if(sum>tar)
        {
            end--;
        }else if(sum<tar)
        {
            st++;
        }else{
            cout<<st<<" "<<end<<endl;
            exit(0);
        }
    }

    cout<<"no solution. ";
    */


    //Optimised approach
    //TC=O(n)
    map<int,int> m;
    for(int i=0;i<a.size();i++)
    {
        int sec=tar-a[i];
        if(m.find(sec)!=m.end())
        {
            cout<<i<<" "<<m[sec]<<endl;
            exit(0);
        }

        m[a[i]]=i;
        
    }


    cout<<"no solution.";
    return 0;
}