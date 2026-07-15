#include<iostream>
#include<vector>
using namespace std;
int main()
{
    pair<string,int> p={"Marks",5};
    pair<int,pair<int,int>> z={1,{2,3}};
    cout<<p.first<<endl;
    cout<<z.second.first<<endl;

    vector<pair<int,int>> a={{1,2},{3,4}};
    a.push_back({5,6});
    a.emplace_back(7,8);
    for(auto val: a)
    {
        cout<<val.first<<" "<<val.second<<"  ";
    }
    return 0;
}