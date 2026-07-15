#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m=4,n=4;

    int a[4][4] = 
    {
        {1 ,2 ,3 ,4 },
        {5 ,6 ,7 ,8 },
        {9 ,10,11,12},
        {13,14,15,16}
    };

    bool hz=true,fcw=true,frw=true;
    int m_r=0, n_c=-1;
    m=m-1;
    while(m>0 || n>0)
    {
        if(hz)
        {
            for(int i=0;i<n;i++)
            {
                if(fcw)
                {
                    n_c++;
                }else{
                    n_c--;
                }
                cout<<a[m_r][n_c]<<" ";
            }
            n--;
            fcw=!fcw;
  
        }else{
            for(int i=0;i<m;i++)
            {
                if(frw)
                {
                    m_r++;
                }else{
                    m_r--;
                }
                
                cout<<a[m_r][n_c]<<" ";
            }
            m--;
            frw=!frw;

        }

        hz=!hz;
    }

    return 0;
}