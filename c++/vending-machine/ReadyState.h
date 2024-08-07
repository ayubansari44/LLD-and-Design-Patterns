#ifndef READYSTATE_H
#define READYSTATE_H

#include "VendingMachineState.h"
#include "VendingMachine.h"

class ReadyState : public VendingMachineState {
private:
    VendingMachine* vendingMachine;

public:
    ReadyState(VendingMachine* vendingMachine);

    void selectProduct(Product* product) override;
    void insertCoin(CoinsNotes* coin) override;
    void insertNote(CoinsNotes* note) override;
    void dispenseProduct() override;
    void returnChange() override;

    void checkPaymentStatus();
};

#endif // READYSTATE_H
