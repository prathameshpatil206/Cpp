#include<iostream>
#include<math.h>
using namespace std;

//
//Time complexity: O(log10(n))
int main()
{
    int m=3567;
    int n=m;
    while(n>0)
    {
        int ld=n%10;
        cout<<ld<<endl;
        n=n/10;
    }
    //no.of digits
    cout<<(int)(log10(m)+1)<<endl;
    return 0;
}