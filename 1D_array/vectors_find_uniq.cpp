#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> a={1,3,1,4,3};
    int n = a.size();
    for(int i =0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(a[j]==a[i]){
                count++;
            }  
        }
        
        if(count==1)
        {
           cout<<a[i];     
        }

        //Use int XOR=0; XOR=XOR^a[i]; instead of nested for loop.
    }
    return 0;
}