#include "VendingMachine.h"
#include "IdleState.h"
#include "ReadyState.h"
#include "DispenseState.h"
#include "ReturnChangeState.h"

VendingMachine* VendingMachine::instance = nullptr;

VendingMachine::VendingMachine() {
    this->totalPayment = 0;
    idleState = new IdleState(this);
    readyState = new ReadyState(this);
    dispenseState = new DispenseState(this);
    returnChangeState = new ReturnChangeState(this);
    currentState = idleState;
    inventory = new Inventory();
}

VendingMachine* VendingMachine::getInstance() {
    if (instance == nullptr) {
        instance = new VendingMachine();
    }
    return instance;
}

void VendingMachine::selectProduct(Product* product) {
    currentState->selectProduct(product);
}

void VendingMachine::insertCoin(CoinsNotes* coin) {
    currentState->insertCoin(coin);
}

void VendingMachine::dispenseProduct() {
    currentState->dispenseProduct();
}

void VendingMachine::returnChange() {
    currentState->returnChange();
}

void VendingMachine::setState(VendingMachineState* state) {
    currentState = state;
}

VendingMachineState* VendingMachine::getIdleState() {
    return idleState;
}

VendingMachineState* VendingMachine::getReadyState() {
    return readyState;
}

VendingMachineState* VendingMachine::getDispenseState() {
    return dispenseState;
}

VendingMachineState* VendingMachine::getReturnChangeState() {
    return returnChangeState;
}

Product* VendingMachine::getSelectedProduct() {
    return selectedProduct;
}

void VendingMachine::setSelectedProduct(Product* product) {
    this->selectedProduct = product;
}

void VendingMachine::resetSelectedProduct() {
    this->selectedProduct = nullptr;
}

double VendingMachine::getTotalPayment() {
    return totalPayment;
}

void VendingMachine::addCoin(CoinsNotes* coin) {
    totalPayment += coin->getValue();
}

void VendingMachine::addNote(CoinsNotes* note) {
    totalPayment += note->getValue();
}

void VendingMachine::resetPayment() {
    totalPayment = 0.0;
}
