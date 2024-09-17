#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include "Product.h"
#include "CoinsNotes.h"
#include "Inventory.h"
#include "VendingMachineState.h"

class VendingMachineState; // Forward declaration

class VendingMachine {
private:
    static VendingMachine* instance;
    VendingMachineState* idleState;
    VendingMachineState* readyState;
    VendingMachineState* dispenseState;
    VendingMachineState* returnChangeState;
    VendingMachineState* currentState;
    Product* selectedProduct;
    double totalPayment;

public:
    Inventory* inventory;

    VendingMachine();

    static VendingMachine* getInstance();

    void selectProduct(Product* product);
    void insertCoin(CoinsNotes* coin);
    void dispenseProduct();
    void returnChange();
    void setState(VendingMachineState* state);

    VendingMachineState* getIdleState();
    VendingMachineState* getReadyState();
    VendingMachineState* getDispenseState();
    VendingMachineState* getReturnChangeState();

    Product* getSelectedProduct();
    void setSelectedProduct(Product* product);
    void resetSelectedProduct();

    double getTotalPayment();
    void addCoin(CoinsNotes* coin);
    void addNote(CoinsNotes* note);
    void resetPayment();
};

#endif // VENDINGMACHINE_H
