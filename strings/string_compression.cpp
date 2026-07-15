#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
    vector<char> chars ={'a','a','e','e','e','e','f'};
    int n=chars.size();
    int idx=0;
    for(int i=0;i<n;i++)
    {
        int count=0;
        char ch=chars[i];
        while(i<n && chars[i]==ch)
        {
            count++;
            i++;
        }
        chars[idx++]=ch;
        if(count>1)
        {
            string str=to_string(count);
            for(char dig : str)
            {
                chars[idx++]=dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    
    for(char val: chars)
    {
        cout<<val<<" ";
    }
    cout<<endl<<chars.size();
    return 0;
}