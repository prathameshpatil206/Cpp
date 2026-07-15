#include <iostream>
#include <string>
using namespace std;

void fun()
{
    static int x=2;//initialiising only once...not at every call
    cout<<"x : "<<x<<endl;
    x++;
}

class ABC
{
    public:
        static int y;

        void incx()
        {
            y++;
        }
};

int ABC::y = 0; // define static member once globally

int main() 
{
    fun();
    fun();
    fun();

    ABC obj1,obj2;
    /*if any variable is static in class then
      the same variable is shared accross its objects
      and the objects are deleted at the end of main
      function.
    */
    obj1.y=0;
    cout<<obj1.y<<endl;
    cout<<obj2.y<<endl;
    obj1.incx();
    cout<<obj2.y<<endl;
    return 0;
}