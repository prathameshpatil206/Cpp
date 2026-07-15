#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int main()
{
    string s="the  sky  is blue " ;
    string ans="";
    int i;
    string word="";
    reverse(s.begin(),s.end());
    for(i=0;i<=s.length();i++)
    {
        if(s[i]==' '||s[i]=='\0')
        {
            if(word.length()>0)
            {
                reverse(word.begin(),word.end());
                ans+=word+" ";
                word="";
            }
        }else{
            word +=s[i];
        }
    }
    cout<<ans.substr(0,ans.length()-1)<<endl;
    return 0;
}