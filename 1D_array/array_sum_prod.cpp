#include<iostream>
using namespace std;

void findSumProd(int a[],int n)
{
int sum=0, product=1;

for(int i=0;i<n;i++)
{
    sum=sum+a[i];
    product=product*a[i];
}

cout<<"Sum of elements: "<<sum<<endl;
cout<<"Product of elements: "<<product<<endl;

}

int main()
{

    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: ";

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    findSumProd(a,n);

    return 0;
}