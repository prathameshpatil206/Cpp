#include<bits/stdc++.h>
using namespace std;


//TC:O(n)
//SC:O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            if(dq.empty())
            {
                dq.push_back(i);
            }else
            {
                while(dq.size()>0 && nums[i]>=nums[dq.back()])
                {
                    dq.pop_back();
                }
            }

            dq.push_back(i);
            
        }

        ans.push_back(nums[dq.front()]);

        for(int i=k;i<n;i++)
        {
            while(dq.size()>0 && dq.front()<=i-k)
            {
                dq.pop_front();
            }

            while(dq.size()>0 && nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};