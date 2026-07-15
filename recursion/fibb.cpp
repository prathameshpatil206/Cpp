#include<bits/stdc++.h>
using namespace std;

void fib(int f,int s,int i,int n)
{

    if(i==n+1)
    {
        return;
    }

    cout<<f+s<<" ";
    fib(s,f+s,i+1,n);
    
}

int main()
{
    int n=30;
    cout<<0<<" "<<1<<" ";
    fib(0,1,3,n);
    return 0;
}

// 0 1 1 2 3 5 8 13 21 34

//(0,1,3) (1,1,4) (1,2,5) (2,3,6) (3,5,7) (5,8,8)