#include<iostream>
#include "DispenseState.h"

DispenseState::DispenseState(VendingMachine* vendingMachine) {
    this->vendingMachine = vendingMachine;
}

void DispenseState::selectProduct(Product* product) {
    std::cout << "Product already selected, please collect the dispensed product" << std::endl;
}

void DispenseState::insertCoin(CoinsNotes* coin) {
    std::cout << "Payment already made, please collect the dispensed product" << std::endl;
}

void DispenseState::insertNote(CoinsNotes* note) {
    std::cout << "Payment already made, please collect the dispensed product" << std::endl;
}

void DispenseState::dispenseProduct() {
    vendingMachine->setState(vendingMachine->getReadyState());

    Product* product = vendingMachine->getSelectedProduct();
    vendingMachine->inventory->updateProductQuantity(product, vendingMachine->inventory->getQuantity(product) - 1);
    std::cout << "Product dispensed: " << product->getName() << std::endl;
    vendingMachine->setState(vendingMachine->getReturnChangeState());
}

void DispenseState::returnChange() {
    std::cout << "Product already dispensed, please collect the dispensed product" << std::endl;
}
