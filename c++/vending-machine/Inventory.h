#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include "Product.h"

class Inventory {
private:
    std::map<Product*, int> products;

public:
    Inventory();

    void addProduct(Product* product, int quantity);
    void removeProduct(Product* product);
    void updateProductQuantity(Product* product, int quantity);
    int getQuantity(Product* product);
    bool isAvailable(Product* product);
};

#endif // INVENTORY_H
