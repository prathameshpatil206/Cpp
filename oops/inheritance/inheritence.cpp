#include<iostream>
using namespace std;

//Properties & member functions of base class are passed on to the derived class.
class BasicProp
{
    public:
        string color;
        string model;
        string veh_num;
        float cost;

        BasicProp(string color,string model, string veh_num, float cost)
        {
            this->color=color;
            this->model=model;
            this->veh_num=veh_num;
            this->cost=cost;
        }

        BasicProp()
        {
            cout<<"First Parent class constructor is called\n"<<endl;
        }

        ~BasicProp()
        {
            cout<<"Parent class destructor"<<endl;
        }
};

class Car : public BasicProp
{
    public:
        int no_of_airbags;
        string owner_name;

        Car(string color, string model, string veh_num, float cost, int no_of_airbags,string owner_name ) 
            : BasicProp(color,model, veh_num,cost)
            {
                this->no_of_airbags=no_of_airbags;
                this->owner_name=owner_name;    
            }

        Car()
        {
            cout<<"Then Child class constructor is called\n"<<endl;
        }

        ~Car()
        {
            cout<<"Child class destructor"<<endl;
        }
        void getInfo()
        {
            cout<<"Color: "<<color<<endl;
            cout<<"Model: "<<model<<endl;
            cout<<"Vehicle Number: "<<veh_num<<endl;
            cout<<"Cost: "<<cost<<endl;
            cout<<"Airbags: "<<no_of_airbags<<endl;
            cout<<"Owner: "<<owner_name<<endl;
        }
        
};

int main(){

    Car c("red","Maruti Suzuki","KA22047E8",1260000,3,"Chintu");

    c.getInfo();

    Car d;

    return 0;
}