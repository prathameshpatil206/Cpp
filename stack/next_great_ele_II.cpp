#include<bits/stdc++.h>
using namespace std;

//TC:O(n)
//SC:O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size());
        int n=nums.size();
        int j=0;
        int flag=1;
        for(int i=n-1;i>=0;i--)
        {
            
            while(!s.empty() && nums[s.top()]<=nums[i])
            {
                if(s.top()<i)
                {
                    j=s.top()+1;
                }
                s.pop();
            }
            
            if(flag && s.empty())
            {
                while(j<i && nums[j]<=nums[i])
                {
                    j++;
                }

                if(i!=j)
                {
                    s.push(j);
                }else
                {
                    flag=0;
                }
            }

            if(s.empty())
            {
                ans[i]=-1;
            }else
            {
                ans[i]=nums[s.top()];
            }

            s.push(i);
        }

        return ans;
    }
};

//OR

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!s.empty() && nums[s.top()]<=nums[i%n])
            {
                s.pop();
            }

            if(s.empty())
            {
                ans[i%n]=-1;
            }else{
                ans[i%n]=nums[s.top()];
            }
            s.push(i%n);
        }

        return ans;
    }
};