#include<iostream>
#include "Inventory.h"

Inventory::Inventory() {}

void Inventory::addProduct(Product* product, int quantity) {
    products[product] = quantity;
}

void Inventory::removeProduct(Product* product) {
    products.erase(product);
}

void Inventory::updateProductQuantity(Product* product, int quantity) {
    products[product] = quantity;
}

int Inventory::getQuantity(Product* product) {
    return products[product];
}

bool Inventory::isAvailable(Product* product) {
    if (products.find(product) != products.end()) {
        return products[product] > 0;
    } else {
        return false;
    }
}
