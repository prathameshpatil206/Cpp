#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    //used for key value pair
    //time complexity of insert, erase, count is O(1)
    unordered_map<int,string> m;
    m[4]="Hari";
    m[2]="Harish"; //key duplication not allowed.
    m[0]="Hara";
    m[1]="Hari";
    m.insert({3,"Mohan"});
    m.emplace(5,"Rohan");
    for(auto p: m )
    {               //does not sort data.
        cout<<p.first<<" : "<<p.second<<endl;
    }
    return 0;
}