#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(3);
    s.insert(4);
    cout<<*(s.lower_bound(4))<<endl;//s.lowerbound(4) gives 
    //iterator pointing to min value >=4 ....if not present then returnss.end()
    cout<<*(s.upper_bound(4))<<endl;//returns value strictly greator than 4
    for(auto p: s)
    {
        cout<<p<<" ";//sorted form
    }
    cout<<endl;

    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(1);//contains duplicate elements
    ms.insert(2);
    for(auto p: ms)
    {
        cout<<p<<" ";//sorted form
    }
    cout<<endl;

    unordered_set<int> us;
    us.insert(1);
    us.insert(3);
    us.insert(2);
    us.insert(1);
    for(auto p: us)
    {
        cout<<p<<" ";//unsorted form
    }
    cout<<endl;

    return 0;
}