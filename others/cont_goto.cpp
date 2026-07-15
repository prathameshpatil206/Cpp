#include<iostream>
using namespace std;

void Cont()
{
    for(int i=0;i<10;i++)
    {
        if(i==4)
            continue;
        
        cout<<i<<" ";
    }
    cout<<"\n End of Cont function...\n";

}


void Goto()
{
int i=0;
start:
    i++;
    if(i<10)
    {
        cout<<i<<" ";
        goto start;
    }
        
    else
        goto end;

end:
cout<<"\n End of Goto function...";
}

int main()
{
    Cont();
    Goto();
    return 0;
}