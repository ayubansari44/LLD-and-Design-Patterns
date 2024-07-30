#include<bits/stdc++.h>
using namespace std;

class Product
{
    private:
        int id;
        string name;
        double price;
    public:
        Product(int id, string name, double price)
        {
            this->id=id;
            this->name=name;
            this->price=price;
        }
};

enum Coins{
    ONE,
    TWO,
    FIVE
};

enum Notes{
    TEN,
    TWENTY,
    FIFTY,
    HUNDRED
};

class Inventory
{
    private:
        map<Product*, int> products;
    public:
        Inventory()
        {

        }

        void addProduct(Product* product, int quantity){
            products[product] = quantity;
        }

        void removeProduct(Product *product){
            products.erase(product);
        }

        void updateProductQuantity(Product* product, int quantity){
            products[product] = quantity;
        }

        int getQuantity(Product* product){
            return products[product];
        }

        bool isAvailable(Product* product){
            if(products.find(product) != products.end()){
                return products[product]>0;
            }
            
            else{
                cout<<"Product not found"<<endl;
                return false;
            }
        }

};

class VendingMachine
{
    private:
        static VendingMachine *instance;
        Inventory* inventory;
        VendingMachineState *idleState;
        VendingMachineState *readyState;
        VendingMachineState *dispenseState;
        VendingMachineState *returnChangeState;
        VendingMachineState *currentState;
        Product *selectedProduct;
        double totalPayment;
    public:
        VendingMachine(){
            this->totalPayment=0;
        }

        static VendingMachine* getInstance()
        {
            if(instance==NULL){
                instance=new VendingMachine();
            }

            return instance;
        }

        void selectProduct(Product* product){
            currentState->selectProduct(product);
        }

        void insertCoin(Coins coin){
            currentState->insertCoin(coin);
        }

        void dispenseProduct(){
            currentState->dispenseProduct();
        }

        void returnChange(){
            return currentState->returnChange();
        }

        void setState(VendingMachineState* state){
            currentState = state;
        }

        VendingMachineState* getIdleState(){
            return idleState;
        }

        VendingMachineState* getReadyState(){
            return readyState;
        }
        
        VendingMachineState* getDispenseState(){
            return dispenseState;
        }
        
        VendingMachineState* getReturnChangeState(){
            return returnChangeState;
        }

        Product* getSelectedProduct(){
            return selectedProduct;
        }

        void setSelectedProduct(Product* product){
            this->selectedProduct = product;
        }

        void resetSelectedProduct(Product *product){
            this->selectedProduct = NULL;
        }

        double getTotalPayment(){
            return totalPayment;
        }

        //***********************************continue here again once back****************************
        void addCoin(Coins coin){

        }

       

};

class VendingMachineState
{
    public:
        virtual void selectProduct(Product* product) = 0;
        virtual void insertCoin(Coins coin) = 0;
        virtual void insertNote(Notes note) = 0; 
        virtual void dispenseProduct() = 0; 
        virtual void returnChange() = 0; 
};

class IdleState : public VendingMachineState
{
    private:
        
    public:
        void selectProduct(Product* product)
        {
            
        }
};

class ReadyState : public VendingMachineState
{
    public:
        void getState()
        {
            cout<<"Vending Machine is in Ready State";
        }
};

class DispenseState : public VendingMachineState
{
    public:
        void getState()
        {
            cout<<"Vending Machine is in Dispense State";
        }
};

class ReturnChangeState : public VendingMachineState
{
    public:
        void getState()
        {
            cout<<"Vending Machine is in ReturnChange State";
        }

};

int main()
{
    cout<<"Welcome to Vending Machine"<<endl;
}