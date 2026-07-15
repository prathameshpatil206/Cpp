#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;   //LIFO
    s.push(1);
    s.push(2);
    s.emplace(3);
    cout<<s.top()<<endl; //3
    s.pop();
    s.push(4);
    cout<<s.size()<<endl;
    
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    s.push(1);
    s.push(9);
    stack<int> s2;
    s2.swap(s);

    cout<<endl<<s.size()<<endl; //0
    cout<<s2.size()<<endl; //2
    
    return 0;
}