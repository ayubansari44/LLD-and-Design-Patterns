#include<bits/stdc++.h>
#include "CoffeeMachine.h"

using namespace std;

int main()
{
    cout<<"###### Welcome to Coffee Vending Machine ##############"<<endl;
    CoffeeMachine* instance = CoffeeMachine::getInstance();

    instance->displayMenu();

    Coffee *espresso = instance->selectCoffee("Espresso");
    instance->dispenseCoffee(espresso, new Payment(50));

    Coffee *latte = instance->selectCoffee("Latte");
    instance->dispenseCoffee(latte, new Payment(100));
}