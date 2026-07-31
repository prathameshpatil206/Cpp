#include<bits/stdc++.h>
using namespace std;

bool match(char a, char b)
{
    if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
    {
        return true;
    }

    return false;
}


//TC:O(n)
//SC:O(n)
bool valid_paranthesis(string exp)
{
    stack<char> s;
    int i=0;
    while(exp[i]!='\0')
    {
        char curr=exp[i];
        if(curr=='(' ||curr=='{' ||curr=='[' )
        {
            s.push(curr);
        }else{
            if(s.empty())
            {
                return false;
            }

            if(match(s.top(),curr))
            {
                s.pop();
            }else{
                return false;
            }
        }
        i++;
    }

    if(s.empty())
    {
        return true;
    }
    
    return false;
}

int main()
{
    string exp="({([[({})]])})";

    cout<<valid_paranthesis(exp);
    return 0;
}