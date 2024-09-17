#include<iostream>
#include "ReturnChangeState.h"

ReturnChangeState::ReturnChangeState(VendingMachine* vendingMachine) {
    this->vendingMachine = vendingMachine;
}

void ReturnChangeState::selectProduct(Product* product) {
    std::cout << "Please collect the change" << std::endl;
}

void ReturnChangeState::insertCoin(CoinsNotes* coin) {
    std::cout << "Please collect the change" << std::endl;
}

void ReturnChangeState::insertNote(CoinsNotes* note) {
    std::cout << "Please collect the change" << std::endl;
}

void ReturnChangeState::dispenseProduct() {
    std::cout << "Product already dispensed, please collect the change" << std::endl;
}

void ReturnChangeState::returnChange() {
    double change = vendingMachine->getTotalPayment() - vendingMachine->getSelectedProduct()->getPrice();
    if (change > 0) {
        std::cout << "Change to return: " << change << std::endl;
        vendingMachine->resetPayment();
    } else {
        std::cout << "No change to return" << std::endl;
    }

    vendingMachine->resetSelectedProduct();
    vendingMachine->setState(vendingMachine->getIdleState());
}
