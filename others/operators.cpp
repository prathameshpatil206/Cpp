#include<bits/stdc++.h>
using namespace std;

class info{
public:
    int x;
    int y;

    info(int _x,int _y)
    {
        this->x=_x;
        this->y=_y;
    }

    info operator+(const info& b) const
    {
        return info((this->x)*b.x,(this->y)*b.y);
    }
};

int main()
{
    info a=info(2,3);
    info b=info(4,5);
    info c=info(2,3);
    cout<<(a+b+c).x<<" "<<(a+b+c).y<<endl;
    
    return 0;
}