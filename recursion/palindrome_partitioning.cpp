#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string& s,int start,int end)
{
    while(start<end)
    {
        if(s[start]!=s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void partition(string& s,int start,vector<string>& parts, vector<vector<string>>& ans)
{
    if(start==s.size())
    {
        ans.push_back(parts);
        return;
    }

    for(int i=start;i<s.size();i++)
    {
        if(is_palindrome(s,start,i))
        {
            parts.push_back(s.substr(start,i+1-start));

            partition(s,i+1,parts,ans);

            parts.pop_back();
        }
    }
}

//TC=O(n * (2^n))

int main()
{
    string s="ababa";
    vector<string>parts;
    vector<vector<string>> ans;
    partition(s,0,parts,ans);

    for(auto v:ans)
    {
        for(auto ele:v)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//a="aaaaaa"