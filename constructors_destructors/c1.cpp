#include<iostream>
using namespace std;

// Constructor with no paras...
// Win()
// {
//    cout<<"Inside Constructor";
// }


// Parameterized Constructor...
// Win(int x, int y)
// {
//    cout<<"\nSum of "<<x<<" and "<<y<<" is "<<x+y;
// }


class Win{
private:
public:
int a=0;
Win(){

}
Win(int x)
{
   this->a=x;
}

//copy constructor....
    Win(Win &obj,int y)
    {
        this->a=obj.a*10+y;
    }
};


int main()
{   
    Win c;
    cout<<c.a<<endl;
    Win b(10);
    cout<<b.a<<endl;
    Win d(b,10);
    cout<<d.a<<endl;
    return 0;
}