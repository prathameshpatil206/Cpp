#include<bits/stdc++.h>
using namespace std;

//print fibonacci series using recursion

void fib(int a, int b, int n)
{
    if(a == 0)
    {
        cout<<a<<" "<<b<<" ";
    }
    if(n==2)
    {
        return;
    }
    
    int sum = a + b;
    cout<<sum<<" ";
    fib(b,sum,n-1);
    return;
}

//alternate recursion logic to find nth fibonacci number
//TC: O(2^n)
int nthFib(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }

    return nthFib(n-1) + nthFib(n-2);
}

//Memoization 
//TC:O(n)
//big to small 
//Top Down Approach
int memoFib(vector<int>& dp, int n)
{
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n]=memoFib(dp,n-1)+ memoFib(dp,n-2);

    return dp[n];
}

//Tabulation:
//TC:O(n)
//small to big
//Bottom Up Approach
void tabFib(int n)
{
    vector<int> dp(n,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<dp[n-1];
}

int main()
{
    int n=5;

    fib(0,1,n);
    cout<<endl;

    cout<<nthFib(n-1)<<endl;

    vector<int> dp(n,-1);
    dp[0]=0;
    dp[1]=1;
    cout<<memoFib(dp,n-1)<<endl;

    tabFib(n);
    return 0;
}