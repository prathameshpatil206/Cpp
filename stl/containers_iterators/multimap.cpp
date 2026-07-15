#include<iostream>
#include<map>
using namespace std;
int main()
{
    //used for key value pair
    multimap<int,string> m;
    m.insert({3,"Mohan"});
    m.emplace(5,"Rohan");
    m.emplace(5,"Rohini");
    m.emplace(5,"Sohini");//key duplication allowed.
    m.emplace(6,"Sohini");
    m.emplace(6,"Sohini");
    m.emplace(7,"Sohini");
    m.erase(6);
    m.erase(m.find(5));
    for(auto p: m )
    {
        cout<<p.first<<" : "<<p.second<<endl;
    }
    return 0;
}