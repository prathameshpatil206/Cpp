#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> l;    //{}
    l.push_back(1); //{1}
    l.push_back(2); //{1,2}
    l.push_front(3);//{3,1,2}
    l.emplace_back(4);//{3,1,2,4}
    l.pop_back();//{3,1,2}
    l.pop_front();//{1,2}
    for(int val: l)
    {
        cout<<val<<" ";
    }
    return 0;
}