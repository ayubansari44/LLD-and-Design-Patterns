#include<bits/stdc++.h>
using namespace std;

// customer, restaurant_manager, order(ingredients), reservation, payment(credit, debit, upi),staff,singleton

class MenuItem
{
    private:
        int id;
        double price;
        string name, description;
        bool available;

    public:
        MenuItem(int id, double price, string name, string desc, bool avail){
            this->id=id;
            this->price=price;
            this->name=name;
            this->description=desc;
            this->available=avail;
        }

        int getId(){
            return id;
        }

        int getPrice(){
            return price;
        }

        string getName(){
            return name;
        }

        string getDescription(){
            return description;
        }

        void setName(string name){
            this->name=name;
        }

        bool getAvailability(){
            return available;
        }

        void printMenuItem()
        {
            cout << "ID: " << id << ", Name: " << name << ", Price: " << price
                << ", Description: " << description << ", Available: " << (available ? "Yes" : "No") << endl;
        }
};


enum OrderStatus
{
    PENDING,
    PREPARING,
    READY,
    COMPLETED,
    CANCELLED
};

class Order
{
    private:
        int id;
        double amount;
        vector<MenuItem*> items;
        OrderStatus status;
        string time;
    
    public:
        Order(){

        }

        Order(int id, double amount, vector<MenuItem*> items, OrderStatus status, string time){
            this->id=id;
            this->amount=amount;
            this->items=items;
            this->status = status;
            this->time=time;
        }

        int getId(){
            return id;
        }

        double getAmount(){
            return amount;
        }

        vector<MenuItem*> getMenuItems(){
            return items;
        }

        OrderStatus getStatus(){
            return status;
        }

        string getTime(){
            return time;
        }

        void setId(int id){
            this->id=id;
        }

        void setStatus(OrderStatus status){
            this->status=status;
        }

        void printOrder()
        {
            cout << "Order ID: " << id << ", Amount: " << amount << ", Status: ";
            switch (status)
            {
            case PENDING:
                cout << "PENDING";
                break;
            case PREPARING:
                cout << "PREPARING";
                break;
            case READY:
                cout << "READY";
                break;
            case COMPLETED:
                cout << "COMPLETED";
                break;
            case CANCELLED:
                cout << "CANCELLED";
                break;
            }
            cout << ", Time: " << time << endl;

            cout << "Items: " << endl;
            for (auto item : items)
            {
                item->printMenuItem();
            }
        }

};

class Reservation
{
    private:
        int id, partySize;
        string custName;
        string time;

    public:
        Reservation(int id, int size, string name, string time){
            this->id=id;
            this->partySize=size;
            this->custName=name;
            this->time=time;
        }
};

enum PaymentMethod{
    CASH,
    CREDIT,
    DEBIT,
    UPI,
    INTERNET_BANKING
};

enum PaymentStatus{
    PENDINGG,
    COMPLETEDD,
    FAILEDD
};

class Payment
{
    private:
        int id;
        double amount;
        PaymentMethod method;
        PaymentStatus status;
    
    public:
        Payment(int id, double amount, PaymentMethod method, PaymentStatus status){
            this->id=id;
            this->amount=amount;
            this->method=method;
            this->status=status;
        }

        int getId(){
            return id;
        }

        void setId(int id){
            this->id=id;
        }

        double getAmount(){
            return amount;
        }

        void setAmount(double amount){
            this->amount=amount;
        }

        PaymentMethod getPaymentMethod(){
            return method;
        }


};

class Staff
{
    private:
        int id;
        string name, email, role;
    
    public:
        Staff(){

        }

        Staff(int id, string name, string email, string role)
        {
            this->id=id;
            this->name=name;
            this->email=email;
            this->role=role;
        }
};

class Restaurant
{
    private:
        static Restaurant* instance;
        map<int, Order*> orders;
        map<int, Payment*> payments;
        set<MenuItem*> menu;
        set<Reservation*> reservations;
        set<Staff*> staffs;
    
    public:
        static Restaurant* getInstance(){
            if(instance==NULL){
                instance=new Restaurant();
            }
            return instance;
        }

        void addMenuItem(MenuItem* item){
            menu.insert(item);
        }

        void removeMenuItem(MenuItem* item){
            menu.erase(item);
        }

        vector<MenuItem*> getMenu(){
            vector<MenuItem*> ans(menu.begin(), menu.end());
            return ans;
        }

        void placeOrder(Order* order){
            orders[order->getId()] = order;
            notifyKitchen(); //observor DP could be user in this case;
        }

        void updateOrderStatus(int orderId, OrderStatus status){
            if(orders.find(orderId) != orders.end())
            {
                orders[orderId]->setStatus(status);
                notifyKitchen();
            }
        }

        void makeReservation(Reservation *reservation){
            reservations.insert(reservation);
        }

        void removeReservation(Reservation *reservation){
            reservations.erase(reservation);
        }

        void processPayment(Payment* payment)
        {
            payments[payment->getId()] = payment;
        }

        void addStaff(Staff* staff){
            staffs.insert(staff);
        }

        void removeStaff(Staff* staff){
            staffs.erase(staff);
        }

        //This could be a good example for Observer Design Pattern
        void notifyKitchen(){
            cout<<"Attention staff, please check notice board!"<<endl;
        }

        void printMenu()
        {
            cout << "Menu Items:" << endl;
            for (auto item : menu)
            {
                item->printMenuItem();
            }
        }

        void printOrders()
        {
            cout << "Orders:" << endl;
            for (auto &pair : orders)
            {
                pair.second->printOrder();
                cout<<"-----------------------------------------------------------------------------"<<endl;
            }
        }
};

Restaurant* Restaurant::instance = NULL;

int main()
{
    cout<<"Welcome to Restaurant Management System"<<endl;
    Restaurant *restaurant = Restaurant::getInstance();

    MenuItem *item1 = new MenuItem(1001, 200, "Pizza", "Italian Delicasy", true);
    MenuItem *item2 = new MenuItem(1002, 150, "Burger", "American Delicasy", true);
    MenuItem *item3 = new MenuItem(1003, 100, "Noodles", "Chinese Delicasy", true);
    MenuItem *item4 = new MenuItem(1004, 120, "Shawarma", "Arabian Delicasy", true);
    MenuItem *item5 = new MenuItem(1005, 180, "Nuggets", "NOT A Delicasy", true);
    restaurant->addMenuItem(item1);
    restaurant->addMenuItem(item2);
    restaurant->addMenuItem(item3);
    restaurant->addMenuItem(item4);
    restaurant->addMenuItem(item5);

    Reservation *reservation = new Reservation(2001, 5, "Tony Stark", "8:00 pm");
    restaurant->makeReservation(reservation);

    Order *order1 = new Order(3001, 450.00, {item1, item2, item3}, OrderStatus::PENDING, "8.10 pm");
    Order *order2 = new Order(3002, 300.00, {item1, item3}, OrderStatus::PENDING, "8.20 pm");
    Order *order3 = new Order(3003, 600.00, {item1, item3, item4, item5}, OrderStatus::PENDING, "9.00 pm");

    restaurant->placeOrder(order1);
    restaurant->placeOrder(order2);
    restaurant->placeOrder(order3);


    Payment *payment = new Payment(4001, 450, PaymentMethod::CASH, PaymentStatus::PENDINGG);
    restaurant->processPayment(payment);

    // restaurant->updateOrderStatus(3001, OrderStatus::PREPARING);
    // restaurant->updateOrderStatus(3001, OrderStatus::READY);
    // restaurant->updateOrderStatus(3001, OrderStatus::COMPLETED);

    Staff *staff1 = new Staff(5001, "Gordan Ramsey", "gordan@mail.com", "Waiter");
    Staff *staff2 = new Staff(5001, "Gopi", "gopi@mail.com", "Cook");
    restaurant->addStaff(staff1);
    restaurant->addStaff(staff2);

    // restaurant->printMenu();
    restaurant->printOrders();
}