#include<bits/stdc++.h>
using namespace std;

//TC:O(n^2)
//SC:O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> rmax(height.size());
        
        for(int i=0;i<n;i++)
        {
            int maxi=-1;
            for(int j=i+1;j<n;j++)
            {
                if(height[j]>=height[i])
                {
                    maxi=max(maxi,height[j]);
                }
            }

            rmax[i]=maxi;
        }

        vector<int> lmax(height.size());
        for(int i=n-1;i>=0;i--)
        {
            int maxi=-1;
            for(int j=0;j<i;j++)
            {
                if(height[j]>=height[i])
                {
                    maxi=max(maxi,height[j]);
                }
            }

            lmax[i]=maxi;
        }

        int max_water=0;
        for(int i=0;i<n;i++)
        {
            if(lmax[i]>=0 && rmax[i]>=0)
            {
                max_water+=(min(lmax[i],rmax[i])-height[i]);
            }
        }

        return max_water;
    }
};


//TC:O(n)
//SC:O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> rmax(height.size());
        rmax[n-1]=height[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1],height[i]);
        }
        

        vector<int> lmax(height.size());
        lmax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            lmax[i]=max(lmax[i-1],height[i]);
        }

        int max_water=0;
        for(int i=0;i<n;i++)
        {
            if(lmax[i]>=0 && rmax[i]>=0)
            {
                max_water+=(min(lmax[i],rmax[i])-height[i]);
            }
        }

        return max_water;
    }
};

//TC:O(n)
//SC:O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int ans=0;
        int lmax=0,rmax=0,l=0,r=n-1;
        while(l<r)
        {
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            if(lmax<rmax)
            {
                ans+=lmax-height[l];
                l++;
            }else{
                ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};