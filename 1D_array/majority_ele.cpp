#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void MajorEle(vector<int> a,int n)
{   
    int major=INT_MAX;
    for(int i=0;i<n;i++)
    {   
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]==a[i])
            {
                count++;
            }
        }
        if(count>n/2)
        {
            major=a[i];
            break;
        }
    }
    if(major==INT_MAX)
    {
        cout<<"No Majority element."<<endl;
    }else{
        cout<<"Majority element: "<<major<<endl;
    }
}

void Optimized(vector<int> a,int n)
{   
    sort(a.begin(),a.end());
    int freq=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
            {
                freq++;
            
            }else
            {   
                freq=1;
            }
        
        if(freq>n/2)
            {
                cout<<"Majority element: "<<a[i]<<endl;
                break;
            }
    }
    
}

void MooresVotingAlgorithm(vector<int> a,int n)
{   
    int freq=0,major=0;
    for(int i=0;i<n;i++)
    {
        if(freq==0)
        {
            major=a[i];
        }
        if(a[i]==major)
        {
            freq++;
        }else
        {
            freq--;
        }
        
    }
    cout<<"Majority element: "<<major<<endl;
}

int main(){
    vector<int> a={3,2,4,2,4,2,3,2,3,2,2};
    int n = a.size();
    MajorEle(a,n);
    Optimized(a,n);
    MooresVotingAlgorithm(a,n);
    return 0;
}