#include<bits/stdc++.h>
using namespace std;

//Use case is a Food order on Swiggy. 
//Observers: Restaurant, DeliveryPartner, Customer
//Subject: Order

class IObserver
{
    public:
        virtual void notify(string msg) = 0;
};

class Restaurant : public IObserver
{
    private: 
        string name;
    
    public:
        Restaurant(string name)
        {
            this->name = name;
        }

        void notify(string msg)
        {
            cout<<"Restaurant "<<name<<" has been notified that "<<msg<<endl;
        }
};

class DeliveryPartner : public IObserver
{
    private: 
        string name;
    
    public:
        DeliveryPartner(string name)
        {
            this->name = name;
        }

        void notify(string msg)
        {
            cout<<"DeliveryPartner "<<name<<" has been notified that "<<msg<<endl;
        }
};

class Customer : public IObserver
{
    private: 
        string name;
    
    public:
        Customer(string name)
        {
            this->name = name;
        }

        void notify(string msg)
        {
            cout<<"Customer "<<name<<" has been notified that "<<msg<<endl;
        }
};

//In our code Order acts as a Subject
class Order
{
    private:
        list<IObserver*> observerList;
    
    public:
        void subscribe(IObserver* obs)
        {
            observerList.push_back(obs);
        }

        void unsubscribe(IObserver* obs)
        {
            observerList.remove(obs);
        }

        void notifyAll(string msg)
        {
            for(auto it: observerList)
            {
                it->notify(msg);
            }
        }
};


int main()
{
    Customer* cus1 = new Customer("Raaj");
    Restaurant* res1 = new Restaurant("Hotel Taaj");
    DeliveryPartner* del1 = new DeliveryPartner("Driver Sam");

    Order* ord1 = new Order();
    ord1->subscribe(cus1);
    ord1->subscribe(res1);
    // ord1->subscribe(del1);
    ord1->notifyAll("Order has been placed");

    ord1->subscribe(del1);
    ord1->notifyAll("Order is ready for pick up");

    ord1->unsubscribe(res1);

    ord1->notifyAll("Order has been delivered!");


}