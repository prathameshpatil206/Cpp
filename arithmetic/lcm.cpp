#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//a*b=gcd(a,b)Xlcm(a,b)

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
    int a=15,b=20;
    cout<<a*b/EuclidsAlgo(a,b);
    return 0;
}