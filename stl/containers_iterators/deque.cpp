#include<iostream>
#include<deque>
using namespace std;

int main()
{
    //similar to list
    deque<int> d;    //{}
    d.push_back(1); //{1}
    d.push_back(2); //{1,2}
    d.push_front(3);//{3,1,2}
    d.emplace_back(4);//{3,1,2,4}
    d.pop_back();//{3,1,2}
    d.pop_front();//{1,2}
    cout<<d[1]<<endl;
    for(int val: d)
    {
        cout<<val<<" ";
    }
    return 0;
}