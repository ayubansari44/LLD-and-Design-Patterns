#ifndef VENDINGMACHINESTATE_H
#define VENDINGMACHINESTATE_H

#include "Product.h"
#include "CoinsNotes.h"

class VendingMachineState {
public:
    virtual void selectProduct(Product* product) = 0;
    virtual void insertCoin(CoinsNotes* coin) = 0;
    virtual void insertNote(CoinsNotes* note) = 0;
    virtual void dispenseProduct() = 0;
    virtual void returnChange() = 0;
};

#endif // VENDINGMACHINESTATE_H
