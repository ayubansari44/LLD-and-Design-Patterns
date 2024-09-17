#include<iostream>
#include "IdleState.h"

IdleState::IdleState(VendingMachine* vendingMachine) {
    this->vendingMachine = vendingMachine;
}

void IdleState::selectProduct(Product* product) {
    if (vendingMachine->inventory->isAvailable(product)) {
        vendingMachine->setSelectedProduct(product);
        vendingMachine->setState(vendingMachine->getReadyState());
        std::cout << "Product selected: " << product->getName() << std::endl;
    } else {
        std::cout << "Product not available: " << product->getName() << std::endl;
    }
}

void IdleState::insertCoin(CoinsNotes* coin) {
    std::cout << "Please select a product first" << std::endl;
}

void IdleState::insertNote(CoinsNotes* note) {
    std::cout << "Please select a product first" << std::endl;
}

void IdleState::dispenseProduct() {
    std::cout << "Please select a product and make payment" << std::endl;
}

void IdleState::returnChange() {
    std::cout << "No change to return" << std::endl;
}
