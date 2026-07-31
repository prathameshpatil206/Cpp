#include<bits/stdc++.h>
using namespace std;


//Optimal
//TC:O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=-1;
        vector<int> widths(heights.size());
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(s.size()!=0 && heights[s.top()]>=heights[i])
            {
                s.pop();
            }

            if(s.empty())
            {
                widths[i]=i+1;
            }else{
                widths[i]=i-s.top();
            }

            s.push(i);
        }

        while(!s.empty())
        {
            s.pop();
        }

        for(int i=n-1;i>=0;i--)
        {
            while(s.size()!=0 && heights[s.top()]>=heights[i])
            {
                s.pop();
            }

            if(s.empty())
            {
                widths[i]+=n-i-1;
            }else{
                widths[i]+=s.top()-i-1;
            }

            s.push(i);
        }

        
        for(int i=0;i<n;i++)
        {
            int curr_area=heights[i]*widths[i];
            ans=max(ans,curr_area);
        }

        return ans;
    }
};

//Brute force
//TC:O(n^2)
int main()
{
    vector<int> a={2,1,5,6,2,3};
    int n=a.size();
    int max_area=-1;

    for(int i=0;i<n;i++)
    {
        int count=0;
        int j=i;
        while(j>=0 && a[j]>=a[i])
        {
            count++;
            j--;
        }

        j=i+1;
        while(j<n && a[j]>=a[i])
        {
            count++;
            j++;
        }

        int area=count*a[i];
        if(area>max_area)
        {
            max_area=area;
        }
    }

    cout<<max_area<<endl;
    return 0;
}

