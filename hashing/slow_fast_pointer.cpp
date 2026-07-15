#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a={3,1,3,4,2};
    int s=a[0],f=a[0];


    do{
        s=a[s];
        f=a[a[f]];
    }while(s!=f);

    s=a[0];
    while(s!=f){
        s=a[s];
        f=a[f];
    }

    cout<<"rep_val = "<<s<<endl;
    return 0;
}
