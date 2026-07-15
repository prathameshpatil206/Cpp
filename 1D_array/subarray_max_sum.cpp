#include<iostream>
#include<vector>
using namespace std;

void Method1(vector<int> a, int n)
{
    int start, end;

   cout<<endl<<endl<<"Using Method1 "<<endl;
    vector<int> sums;
    
    for(start=0;start<n;start++)
        {
            for(end=start;end<n;end++)
                {
                    int sum=0;
                    for(int i=start;i<=end;i++)
                        {
                            sum=sum+a[i];
                        }
                    sums.push_back(sum);
                }
        }
    
    int max=a[0];
    for(int i : sums){
        if(i>max){
            max=i;
        }
    }
    cout<<"Maximum SubArray Sum: "<<max;

}

void Method2(vector<int> b, int n)
{
    int end, front, large=b[0];
    cout<<endl<<endl<<"Using Method2 "<<endl;
    for(front=0;front<n;front++)
    {
        int sum=0;
        for(end=front;end<n;end++)
        {
            sum=sum+b[end];
            large=max(sum,large);
        }
    }
    cout<<"Maximun Subarray Sum: "<<large;
}

void KadanesAlgorithm(vector<int> b, int n)
{
    int sum=0,maxSum=b[0];
    cout<<endl<<endl<<"Using Kadane's Algorithm "<<endl;
    for(int i=0;i<n;i++)
    {
        sum=sum+b[i];
        maxSum=max(sum,maxSum);
        if(sum<0){
            sum=0;
        } 
    }
    cout<<"Maximun Subarray Sum: "<<maxSum;
}

int main(){

    vector<int> a ={3,-4,5,4,-1,7,-8};
    int n=a.size();
    Method1(a,n);
    Method2(a,n);
    KadanesAlgorithm(a,n);
    
    return 0;
}