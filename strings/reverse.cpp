#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s="Lamination";
    int n=s.length();
    // char rv[11];
    // for(int i=n-1;i>=0;i--)
    // {
    //     rv[n-i-1]=s[i];
    // }
    // rv[10]='\0';
    // cout<<rv<<endl;
    
    int st=0, end=n-1;
    while(st<end)
    {
        swap(s[st],s[end]);
        st++;
        end--;
    }
    cout<<s<<endl;
    //OR
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}