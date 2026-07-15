#include<iostream>
using namespace std;
int main()
{
    string s1="What's";
    string s2="Up";
    cout<<s1+s2<<endl;//concatenation
    cout<<(s1==s2)<<endl;
    cout<<(s1<s2)<<endl;
    cout<<(s1>s2)<<endl;
    cout<<s1.length()<<endl;

    string s;
    getline(cin,s);
    cout<<s<<endl;

    for(char ch: s)
    {
        cout<<ch<<"\t";
    }
    return 0;
}