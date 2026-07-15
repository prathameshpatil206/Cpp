#include<iostream>
#include<string>
using namespace std;

//Encapsulation is wrapping up of data 
//& member functions in a single unit called class.
class Account
{
    private:
        double balance;//data hiding
        string password;
    public:
        string accountId;
        string userName;

        //setter
        void setBalance(double b)
        {
            balance=b;
        }

        //getter
        double getBalance()
        {
            return balance;
        }
};

int main()
{
    Account a;
    cin>>a.userName;
    cin>>a.accountId;
    a.setBalance(25000);
    cout<<a.getBalance();
    return 0;
}