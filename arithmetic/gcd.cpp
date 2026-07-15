#include<iostream>
#include<math.h>
using namespace std;

int gcd(int a,int b)
{

    for(int i=min(a,b);i>=1;i--)
    {
        if(a%i==0 && b%i==0)
        {
            return i;
        }
    }
    return 1;
}

int EuclidsAlgo(int a,int b)
{
    if(a==0)
        return b;
    else if(b==0)
            return a;

    if(a>b)
        return EuclidsAlgo(a%b,b);//(a-b,b)
    else
        return EuclidsAlgo(a,b%a);//(a,b-a)

}
int main()
{
    int a=28,b=20;
    cout<<gcd(a,b)<<endl;
    cout<<EuclidsAlgo(a,b)<<endl;
    return 0;
}