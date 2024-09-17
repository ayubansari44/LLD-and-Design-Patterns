#include<iostream>
#include "ReadyState.h"

ReadyState::ReadyState(VendingMachine* vendingMachine) {
    this->vendingMachine = vendingMachine;
}

void ReadyState::selectProduct(Product* product) {
    std::cout << "Product already selected, please make payment" << std::endl;
}

void ReadyState::insertCoin(CoinsNotes* coin) {
    vendingMachine->addCoin(coin);
    std::cout << "Coin inserted: " << coin << std::endl;
    checkPaymentStatus();
}

void ReadyState::insertNote(CoinsNotes* note) {
    vendingMachine->addCoin(note);
    std::cout << "Coin inserted: " << note << std::endl;
    checkPaymentStatus();
}

void ReadyState::dispenseProduct() {
    std::cout << "Please make payment" << std::endl;
}

void ReadyState::returnChange() {
    double change = vendingMachine->getTotalPayment() - vendingMachine->getSelectedProduct()->getPrice();
    if (change > 0) {
        std::cout << "Change to return: " << change << std::endl;
        vendingMachine->resetPayment();
    } else {
        std::cout << "No change to return" << std::endl;
    }
}

void ReadyState::checkPaymentStatus() {
    if (vendingMachine->getTotalPayment() >= vendingMachine->getSelectedProduct()->getPrice()) {
        vendingMachine->setState(vendingMachine->getDispenseState());
    }
}
