#include<iostream>
#include<string>
using namespace std;

bool alpha_num(char a)
{
    int n=((int)a);
    if((57>=n&&n>=48)||(90>=n&&n>=65)||(122>=n&&n>=97))
    {
        return true;
    }
    return false;
}
int main()
{
    string s;
    getline(cin,s);
    int st=0,end=s.length()-1;
    while(st<end)
    {
        if(!alpha_num(s[st]))
        {
            st++;
            continue;
        }
        
        if(!alpha_num(s[end]))
        {
            end--;
            continue;
        }
        
        if(s[st]!=s[end])
        {
            if(tolower(s[st])!=tolower(s[end]))
            {
                cout<<"Not a Palindrome"<<endl;
                exit(0);
            }
            
        }
        st++;
        end--;
        
    }

    cout<<"Palindrome"<<endl;

    return 0;
}