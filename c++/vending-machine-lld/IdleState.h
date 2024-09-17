#ifndef IDLESTATE_H
#define IDLESTATE_H

#include "VendingMachineState.h"
#include "VendingMachine.h"

class IdleState : public VendingMachineState {
private:
    VendingMachine* vendingMachine;

public:
    IdleState(VendingMachine* vendingMachine);

    void selectProduct(Product* product) override;
    void insertCoin(CoinsNotes* coin) override;
    void insertNote(CoinsNotes* note) override;
    void dispenseProduct() override;
    void returnChange() override;
};

#endif // IDLESTATE_H
