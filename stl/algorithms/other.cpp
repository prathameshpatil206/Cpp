#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v={1,2,3,4,5,6};
    int a=10, b=20, c=50;

    cout<<min(a,b)<<endl;
    cout<<max(b,c)<<endl;
    swap(a,b);
    cout<<"a= "<<a<<" b= "<<b<<endl;

    cout<<*(max_element(v.begin(),v.end()))<<endl;
    cout<<*(min_element(v.begin(),v.end()))<<endl;

    int target=2;
    cout<<binary_search(v.begin(),v.end(),target)<<endl;//1 or 0

    //count set bits
    cout<<__builtin_popcount(c)<<endl;//counts the number of 1's in 32 bit binary number form.
    
    long int d=234;
    cout<<__builtin_popcountl(d)<<endl;//counts the number of 1's in 32 bit binary number form.

    long long int e=567;
    cout<<__builtin_popcountll(e)<<endl;//counts the number of 1's in 32 bit binary number form.

    return 0;
}