#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v={1,2,3,4,5}, 
    a={1,2,3,4,5,6,7,8,9};
    reverse(v.begin(),v.end());
    for(auto val: v)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    reverse(a.begin()+2,a.begin()+6);
    for(auto val: a)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}