#include<iostream>
using namespace std;

//~ClassName(){}

class Tree
{
    public:

        string type;
        string color;
        int *dna_count;
        
        Tree(){
            dna_count=new int;
        }

        //set dna
        void dna(int b)
        {
            *(this->dna_count)=b;
        }

        ~Tree(){
            delete this->dna_count;
            cout<<dna_count<<endl;
        }

};

int main(){

    Tree t1;
    t1.dna(5678);
    cout<<t1.dna_count<<" "<<*(t1.dna_count)<<endl;

    return 0;
}