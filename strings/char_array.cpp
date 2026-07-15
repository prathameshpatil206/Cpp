#include<iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[]={'h','e','l','l','o','\0'};
    char a[]="hello";//cannot change size during runtime.
    string b="hello";//dynamic => can change size during runtime
    //output
    cout<<str<<" "<<a<<" "<<b<<endl;
    cout<<str[4]<<" "<<a[1]<<" "<<b[3]<<endl;
    cout<<strlen(str)<<" "<<strlen(a)<<" "<<strlen(b.c_str())<<endl;

    //input
    char c[10],d[12];
    cin>>c; //accepts only a single word.
    cout<<c<<endl;
    cin.getline(d,12,'*');//cin.getline(string,length,delimiter)
    // delimiter does not accept anything from *
    for(int i=0;i<12;i++)
    {
           cout<<d[i]<<" "; 
    
    }
    cout<<endl;

    //string length
    char st[]="hello world";
    int len;
    for(len=0;st[len]!='\0';len++);
    cout<<len<<endl;
    return 0;
}