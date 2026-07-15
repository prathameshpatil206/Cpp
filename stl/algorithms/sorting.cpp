#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//custom comparator
bool comparator(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.second<p2.second) return true;
    else if(p1.second==p2.second)
    {
        if(p1.first<p2.first) return true;
        else return false;
    }
    else return false;
}

int main()
{
    int a[5]={100,22,13,34,55},n=5;
    vector<int> v={100, 180,400,3,59,40};
    vector<pair<int,int>> vp={{14,26},{23,45},{56,22},{13,56},{23,11},{12,22}};
    sort(a,a+n);//ascending
    for(auto p:a)
    {
        cout<<p<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end(),greater<int>());//descending.....use functor(or comparator)
    for(auto p:v)
    {
        cout<<p<<" ";
    }
    cout<<endl;

    sort(vp.begin(),vp.end());
    for(auto p:vp)//sorted based on first value of pair.
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;

    sort(vp.begin(),vp.end(),comparator);
    for(auto p:vp)//sorted based on second value of pair.
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;
    return 0;
} 