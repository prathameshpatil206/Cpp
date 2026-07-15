#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> a={16,3,4,15,10,23,12,10,20};
    int n=a.size(),mw=0,area;
    int lp=0,rp=n-1;

    while(lp<rp)
    {
        area=(rp-lp)*min(a[lp],a[rp]);
        mw=max(mw,area);
        a[lp]<a[rp] ? lp++ : rp--;
    }

    cout<<"MostWater: "<<mw<<endl;
    return 0;
}