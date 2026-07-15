#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> a ={1,2,3,4,5,6,7,8,9};
    int n=a.size(), start, end;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            for(int k=0;k<i+1;k++){
                cout<<a[j+k];
            }
            cout<<" ";
        }
        cout<<endl;
    }

        //OR
    
    for(start=0;start<n;start++)
        {
            for(end=start;end<n;end++)
                {
                    for(int i=start;i<=end;i++)
                        {
                            cout<<a[i];
                        }
                        cout<<" ";
                }
                cout<<endl;
        }
    
    return 0;
}