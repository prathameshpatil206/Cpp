#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{

    if(n==1)
        return 0;

    if(n==2)
        return 1;

    return fib(n-1)+fib(n-2);
    
}

//TC=O(2^n)
//SC=O(n)

int main()
{
    int n=30;
    cout<<fib(n);
    return 0;
}
