#include<bits/stdc++.h>
using namespace std;

void display(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";
    display(--n);
}

int main()
{
    display(5);
    return 0;
}

