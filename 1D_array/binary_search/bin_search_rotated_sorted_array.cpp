#include<iostream>
#include<vector>
using namespace std;

//TC=O(logn) SC=O(1)

void bin(vector<int> a, int target)
{
    int st = 0, end = a.size()-1,flag=0;

    while(st <= end) 
    {      
        int mid = st + (end - st)/2;
        if(a[mid] == target) 
        {
            flag=1;
            cout<<"Element "<<target<<" found at pos: "<<mid<<endl;
            return;
        }

        if(a[st] < a[mid]) 
        { //left sorted
            if(a[st] <= target && target <= a[mid]) 
            {
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }else{ 
            //right sorted
            if(a[mid] <= target && target <= a[end]) 
            {
            st = mid + 1;
            }else{
            end = mid - 1;
            }

        }
    }
    if(flag==0)
        cout<<"Element not found"<<endl;
    return;
}

int main()
{
    vector<int> a={8,9,10,11,12,0,1,2,3,4,5,6,7};
    int target=2;
    bin(a,target);
}