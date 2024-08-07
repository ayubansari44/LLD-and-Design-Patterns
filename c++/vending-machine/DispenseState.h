#ifndef DISPENSESTATE_H
#define DISPENSESTATE_H

#include "VendingMachineState.h"
#include "VendingMachine.h"

class DispenseState : public VendingMachineState {
private:
    VendingMachine* vendingMachine;

public:
    DispenseState(VendingMachine* vendingMachine);

    void selectProduct(Product* product) override;
    void insertCoin(CoinsNotes* coin) override;
    void insertNote(CoinsNotes* note) override;
    void dispenseProduct() override;
    void returnChange() override;
};

#endif // DISPENSESTATE_H
