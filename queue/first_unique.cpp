#include<bits/stdc++.h>
using namespace std;

//TC:O(n)
//SC:O(n)

class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char,int> freq;
        queue<int> q;

        
        int i=0;
        for(auto ch:s)
        {

            if(freq.find(ch)!=freq.end())
            {
                freq[ch]++;
            }else{
                q.push(i);
                freq[ch]=1;
            }
            i++;

        }

        while(!q.empty())
        {
            if(freq[s[q.front()]]==1)
            {
                return q.front();
            }
            q.pop();
        }

        return -1;
    }
};