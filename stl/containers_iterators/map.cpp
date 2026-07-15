#include<iostream>
#include<map>
using namespace std;
int main()
{
    //used for key value pair
    //time complexity of insert, erase, count is O(logn)
    map<int,string> m;
    m[4]="Hari";//key duplication not allowed.
    m[2]="Harish"; 
    m[0]="Hara";
    m[1]="Hari";
    m.insert({3,"Mohan"});
    m.emplace(5,"Rohan");
    cout<<"m[1] : "<<m[1]<<endl;
    cout<<"count : "<<m.count(1)<<endl;
    m.erase(1);
    for(auto p: m )
    {
        cout<<p.first<<" : "<<p.second<<endl;//gives sorted data.
    }
    if(m.find(2)!=m.end())//m.find returns iterator pointing to that key.
    {                     //if key not found then iterator returned points to end.
        cout<<"Key found"<<endl;
    }else{
        cout<<"Key not found"<<endl;
    }
    return 0;
}