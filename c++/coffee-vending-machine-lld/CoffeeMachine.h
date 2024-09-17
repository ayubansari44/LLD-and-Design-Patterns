#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H
#include<bits/stdc++.h>
#include "Coffee.h"
#include "Payment.h"

using namespace std;

class CoffeeMachine
{
    private:
      static CoffeeMachine* instance;
      vector<Coffee*> coffeeMenu;
      map<string, Ingredient*> ingredients;

    public:
        CoffeeMachine();
        static CoffeeMachine* getInstance();
        void initializeCoffeeMenu();
        void initializeIngredients();
        void displayMenu();
        Coffee* selectCoffee(string coffeeName);
        void dispenseCoffee(Coffee* coffee, Payment* payment);
        bool hasEnoughIngredients(Coffee* coffee);
        void updateIngredients(Coffee* coffee);
};

#endif