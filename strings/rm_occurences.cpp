#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s="daabcbaabcbc";
    string part="abc";
    while(s.length()>0 && s.find(part)<s.length())
    {
        int i=s.find(part);
        s.erase(i,part.length());
    }
    cout<<s<<endl;
    return 0;
}