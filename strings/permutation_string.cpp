#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int fact(int n)
{
    int facto=1;
    for(int i=2;i<=n;i++)
    {
        facto=facto*i;
    }
    return facto;
}
int main()
{
    string s1="ab", s2="aghybchgh";
    // int i,n=s1.length();
    // sort(s1.begin(),s1.end());
    // int np=fact(n);
    // for(i=0;i<np;i++)
    // {
    //     if(s2.find(s1)<s2.length() && s2.find(s1)>=0)
    //     {
    //         cout<<"True"<<endl;
    //         exit(0);
    //     }
    //     next_permutation(s1.begin(),s1.end());
    // }
    // cout<<"False"<<endl;

    int i,n1=s1.length(),n2=s2.length();
    int freq1[26]={0};
    for(i=0;i<n1;i++)
    {
        freq1[s1[i]-'a']++;
    }

    for(i=0;i<n2-n1;i++)
    {
        int got=1;
        int freq2[26]={0};
        for(int j=0;j<n1;j++)
        {
            freq2[s2[i+j]-'a']++;
        }
        for(int k=0;k<26;k++)
        {
            if(freq1[k]!=freq2[k])
            {
                got=0;
                break;
            }
        }
        if(got==1)
        {
            cout<<"True"<<endl;
            exit(0);
        }

    }

    cout<<"False"<<endl;
    return 0;
}