#include<iostream>
#include<vector>
using namespace std;
int main(){

    vector<int> a ={1,2,3};
    a.push_back(1);
    a.push_back(23);
    cout<<"Size     : "<<a.size()<<endl;    //5
    cout<<"Capacity : "<<a.capacity()<<endl;//6
    a.pop_back();
    cout<<"Size     : "<<a.size()<<endl;    //4
    cout<<"Capacity : "<<a.capacity()<<endl;//6
    cout<<"at 1     : "<<a.at(1)<<endl;
    cout<<"front    : "<<a.front()<<endl;
    cout<<"back     : "<<a.back()<<endl;
    a.emplace_back(6);

    vector<int> b(10,-1);   //10 sized vector with -1 as value
    vector<int> c(a);       //initialize vector c with vector a
    for(int i:b)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i:c)
    {
        cout<<i<<" ";
    }

    a.erase(a.begin()+1);             //a={1, 3, 1, 6}
    a.erase(a.begin()+1,a.begin()+3); //a={1,6}
    a.insert(a.begin()+1,2);          //a={1,2,6}
    cout<<endl<<a.empty()<<endl;            //false(0)
    a.clear();                        //a={}
    cout<<a.empty()<<endl;            //true(1)
    a=c;
    for(int i:a)
    {
        cout<<i<<" ";
    }
    cout<<endl<<*(a.begin()+1);
    cout<<endl<<*(a.end()-1)<<endl;

    //Iterators
    vector<int>::iterator it;
    for(it=a.begin(); it!=a.end();it++) //forward
    {
        cout<<*(it)<<" ";
    }
    cout<<endl;
    for(auto it=a.rbegin(); it!=a.rend();it++)  //backward
    {
        cout<<*(it)<<" ";
    }
    return 0;
}