#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class String
{
public:
int size;
    const char *s;
    String(const char *str)
    {
        size=strlen(str);
        s=str;
        for(int i=0;i<size;i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }

    String(String &old_str)
    {
        this->s=old_str.s;
        cout<<this->s<<endl;
    }

    void change(const char *z){
        this->s=z;
    }
};

int main()
{
    String a("Raman");
    String b(a);
    a.change("Shaman");
    cout<<a.s;
    return 0;
}