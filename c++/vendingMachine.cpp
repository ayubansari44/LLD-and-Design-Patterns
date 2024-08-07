#include<bits/stdc++.h>
using namespace std;

class Product
{
    private:
        string name;
        double price;
    public:
        Product(string name, double price)
        {
            this->name=name;
            this->price=price;
        }

        string getName(){
            return name;
        }

        double getPrice(){
            return price;
        }
};

class CoinsNotes
{
    public:
    enum Currency{
        ONE = 1,
        TWO = 2,
        FIVE = 5,
        TEN = 10,
        TWENTY = 20,
        FIFTY = 50,
        HUNDRED = 100,
        FIVE_HUNDRED = 500
    };


    private:
        double value;
    
    public: 
        CoinsNotes(double value){
            this->value = value;
        }

        double getValue(){
            return value;
        }
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
        VendingMachineState *idleState;
        VendingMachineState *readyState;
        VendingMachineState *dispenseState;
        VendingMachineState *returnChangeState;
        VendingMachineState *currentState;
        Product *selectedProduct;
        double totalPayment;
    public:
        Inventory* inventory;
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

        void insertCoin(CoinsNotes* coin){
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

        void resetSelectedProduct(){
            this->selectedProduct = NULL;
        }

        double getTotalPayment(){
            return totalPayment;
        }

        void addCoin(CoinsNotes* coin){
            totalPayment+=coin->getValue();
        }

        void addNote(CoinsNotes* note){
            totalPayment += note->getValue();
        }

        void resetPayment(){
            totalPayment = 0.0;
        }
};

class VendingMachineState
{
    public:
        virtual void selectProduct(Product* product) = 0;
        virtual void insertCoin(CoinsNotes* coin) = 0;
        virtual void insertNote(CoinsNotes* note) = 0; 
        virtual void dispenseProduct() = 0; 
        virtual void returnChange() = 0; 
};

class IdleState : public VendingMachineState
{
    private:
        VendingMachine* vendingMachine;
    public:
        IdleState(VendingMachine* VendingMachine)
        {
            this->vendingMachine = vendingMachine;
        }

        void selectProduct(Product* product)
        {
            if(vendingMachine->inventory->isAvailable(product))
            {
                vendingMachine->setSelectedProduct(product);
                vendingMachine->setState(vendingMachine->getReadyState());
                cout<<"Product selected:"<<product->getName()<<endl;
            }
            else{
                cout<<"Product not available:"<<product->getName()<<endl;
            }
        }

        void insertCoin(CoinsNotes* coin){
            cout<<"Please select a product first"<<endl;
        }
        void insertNote(CoinsNotes* note){
            cout<<"Please select a product first"<<endl;
        }
        void dispenseProduct(){
            cout<<"Please select a product and make payment"<<endl;
        }
        void returnChange(){
            cout<<"No change to return"<<endl;
        }
};

class ReadyState : public VendingMachineState
{
    private:
        VendingMachine* vendingMachine;
    public:
        ReadyState(VendingMachine* VendingMachine)
        {
            this->vendingMachine = vendingMachine;
        }

        void selectProduct(Product* product)
        {
            cout<<"Product already selected, please make payment"<<endl;
        }

        void insertCoin(CoinsNotes* coin){
            vendingMachine->addCoin(coin);
            cout<<"Coin inserted:"<<coin<<endl;
            checkPaymentStatus();
        }

        void insertNote(CoinsNotes* note){
            vendingMachine->addCoin(note);
            cout<<"Coin inserted:"<<note<<endl;
            checkPaymentStatus();
        }

        void dispenseProduct(){
            cout<<"Please make payment"<<endl;
        }

        void returnChange(){
            double change = vendingMachine->getTotalPayment() - vendingMachine->getSelectedProduct()->getPrice();
            if(change>0){
                cout<<"Change to return:"<<change<<endl;
                vendingMachine->resetPayment();
            }
            else{
                cout<<"No change to return"<<endl;
            }
        }

        void checkPaymentStatus()
        {
            if(vendingMachine->getTotalPayment() >= vendingMachine->getSelectedProduct()->getPrice())
            {
                vendingMachine->setState(vendingMachine->getDispenseState());
            }
        }
};

class DispenseState: public VendingMachineState
{
    private:
        VendingMachine* vendingMachine;
    public:
        DispenseState(VendingMachine* VendingMachine)
        {
            this->vendingMachine = vendingMachine;
        }

        void selectProduct(Product* product)
        {
            cout<<"Product already selected, please collect the dispensed product"<<endl;
        }

        void insertCoin(CoinsNotes* coin){
            cout<<"Payment already made, please collect the dispensed product"<<endl;
        }

        void insertNote(CoinsNotes* note){
            cout<<"Payment already made, please collect the dispensed product"<<endl;
        }

        void dispenseProduct(){
            vendingMachine->setState(vendingMachine->getReadyState());

            Product* product = vendingMachine->getSelectedProduct();
            vendingMachine->inventory->updateProductQuantity(product, vendingMachine->inventory->getQuantity(product) - 1);
            cout<<"Product dispensed:"<<product->getName();
            vendingMachine->setState(vendingMachine->getReturnChangeState());
        }

        void returnChange(){
            cout<<"Product already dispensed, please collect the dispensed product"<<endl;
        }
};


class ReturnChangeState : public VendingMachineState
{
    private:
        VendingMachine* vendingMachine;
    public:
        ReturnChangeState(VendingMachine* VendingMachine)
        {
            this->vendingMachine = vendingMachine;
        }

        void selectProduct(Product* product)
        {
            cout<<"Please collect the change"<<endl;
        }

        void insertCoin(CoinsNotes* coin){
            cout<<"Please collect the change"<<endl;
        }

        void insertNote(CoinsNotes* note){
            cout<<"Please collect the change"<<endl;
        }

        void dispenseProduct(){
            cout<<"Product already dispensed, please collect the change"<<endl;
        }

        void returnChange()
        {
            //start here once back
            double change = vendingMachine->getTotalPayment() - vendingMachine->getSelectedProduct()->getPrice();
            if(change>0){
                cout<<"Change to return:"<<change<<endl;
                vendingMachine->resetPayment();
            }
            else{
                cout<<"No change to return"<<endl;
            }

            vendingMachine->resetSelectedProduct();
            vendingMachine->setState(vendingMachine->getIdleState());
        }
};

VendingMachine* VendingMachine::instance = NULL;

int main()
{
    cout<<"Welcome to Vending Machine"<<endl;
    VendingMachine *vendingMachine = VendingMachine::getInstance();

    Product *coke = new Product("Coke", 50);
    Product *bread = new Product("Bread", 30);
    Product *eggs = new Product("Eggs", 90);

    vendingMachine->inventory->addProduct(coke, 5);
    vendingMachine->inventory->addProduct(bread, 3);
    vendingMachine->inventory->addProduct(eggs, 12);

    vendingMachine->selectProduct(coke);

    CoinsNotes* ten = new CoinsNotes(CoinsNotes::TEN);
    CoinsNotes* twenty = new CoinsNotes(CoinsNotes::TWENTY);
    CoinsNotes* fifty = new CoinsNotes(CoinsNotes::FIFTY);
    CoinsNotes* hundred = new CoinsNotes(CoinsNotes::HUNDRED);

    vendingMachine->insertCoin(fifty);
    vendingMachine->dispenseProduct();
    vendingMachine->returnChange();

}