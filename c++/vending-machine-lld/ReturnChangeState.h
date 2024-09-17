#ifndef RETURNCHANGESTATE_H
#define RETURNCHANGESTATE_H

#include "VendingMachineState.h"
#include "VendingMachine.h"

class ReturnChangeState : public VendingMachineState {
private:
    VendingMachine* vendingMachine;

public:
    ReturnChangeState(VendingMachine* vendingMachine);

    void selectProduct(Product* product) override;
    void insertCoin(CoinsNotes* coin) override;
    void insertNote(CoinsNotes* note) override;
    void dispenseProduct() override;
    void returnChange() override;
};

#endif // RETURNCHANGESTATE_H
