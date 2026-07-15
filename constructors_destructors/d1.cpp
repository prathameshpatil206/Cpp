#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

class pogo{
public:
    int *ptr;
    int size;
    char *s;

    //constructor
    pogo(int x){
        ptr= new int(x);
        cout<<"Dynamic memory allocated at "<<ptr
        <<" with value "<<*ptr<<endl;
    }

    pogo(const char *st)
    {   
        size= strlen(st);
        s=new char[size+1];
        strcpy(s,st);
        cout<<st<<" "<<s<<endl;
    }

    void del()
    {   
        delete[] s;
        delete ptr;
        ptr=NULL;
        if(!ptr)
        {
            cout<<"ptr set to null"<<endl;
        }
    }


    //destructor(called during destructing an object)
    ~pogo()
    {   
        cout<<"Memory deallocated"<<endl;
    }

    void print()
    {   if(ptr){
            cout<<*ptr<<endl;
        }
        else
        {
            cout<<"ptr is null"<<endl;
        }
    }

    void sum(int a, int b)
    {
        cout<<"Sum: "<<a+b<<endl;
    }

};

int main()
{   
    
    pogo a(10);
    pogo b("Pass");
    a.print();
    a.del();
    a.print();
    a.sum(15,12);

}

