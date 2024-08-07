#include <iostream>
#include "Product.h"
#include "CoinsNotes.h"
#include "Inventory.h"
#include "VendingMachine.h"
#include "IdleState.h"
#include "ReadyState.h"
#include "DispenseState.h"
#include "ReturnChangeState.h"

int main() {
    std::cout << "Welcome to Vending Machine" << std::endl;
    VendingMachine* vendingMachine = VendingMachine::getInstance();

    Product* coke = new Product("Coke", 40);
    Product* bread = new Product("Bread", 30);
    Product* eggs = new Product("Eggs", 90);

    vendingMachine->inventory->addProduct(coke, 5);
    vendingMachine->inventory->addProduct(bread, 3);
    vendingMachine->inventory->addProduct(eggs, 12);

    vendingMachine->selectProduct(coke);

    CoinsNotes* ten = new CoinsNotes(CoinsNotes::TEN);
    CoinsNotes* twenty = new CoinsNotes(CoinsNotes::TWENTY);
    CoinsNotes* fifty = new CoinsNotes(CoinsNotes::FIFTY);
    CoinsNotes* hundred = new CoinsNotes(CoinsNotes::HUNDRED);

    vendingMachine->insertCoin(hundred);
    vendingMachine->dispenseProduct();
    vendingMachine->returnChange();

    delete coke;
    delete bread;
    delete eggs;
    delete ten;
    delete twenty;
    delete fifty;
    delete hundred;

    return 0;
}
