#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v={1,3,4,2,6};
    string s="abc";

    next_permutation(v.begin(),v.end());
    for(auto val: v)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    next_permutation(s.begin(),s.end());
    cout<<s<<endl;

    prev_permutation(s.begin(),s.end());
    cout<<s<<endl;

    return 0;
}