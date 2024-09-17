#include "CoffeeMachine.h"

CoffeeMachine* CoffeeMachine::instance = NULL;

CoffeeMachine::CoffeeMachine()
{
    initializeCoffeeMenu();
    initializeIngredients();
}

CoffeeMachine* CoffeeMachine::getInstance()
{
    if(instance==NULL){
        instance = new CoffeeMachine();
    }
    return instance;
}

void CoffeeMachine::initializeCoffeeMenu()
{
    map<Ingredient*, int> cappuccinoRecipe;
    cappuccinoRecipe[ingredients["Coffee"]] = 1;
    cappuccinoRecipe[ingredients["Water"]] = 1;
    cappuccinoRecipe[ingredients["Milk"]] = 1;
    coffeeMenu.push_back(new Coffee("Cappuccino", 20, cappuccinoRecipe));

    map<Ingredient*, int> expressoRecipe;
    expressoRecipe[ingredients["Coffee"]] = 1;
    expressoRecipe[ingredients["Water"]] = 1;
    coffeeMenu.push_back(new Coffee("Espresso", 30, expressoRecipe));

     map<Ingredient*, int> latteRecipe;
    latteRecipe[ingredients["Coffee"]] = 1;
    latteRecipe[ingredients["Water"]] = 1;
    latteRecipe[ingredients["Milk"]] = 2;
    coffeeMenu.push_back(new Coffee("Latte", 40, latteRecipe));

}

void CoffeeMachine::initializeIngredients()
{
    ingredients["Coffee"] = new Ingredient("Coffee", 10);
    ingredients["Water"] = new Ingredient("Water", 10);
    ingredients["Milk"] = new Ingredient("Milk", 10);
}

void CoffeeMachine::displayMenu()
{
    cout<<"Coffee Menu:"<<endl;

    for(auto coffee: coffeeMenu)
    {
        cout<<coffee->getName()<<", Price:"<<coffee->getPrice()<<endl;
    }
}

Coffee* CoffeeMachine::selectCoffee(string coffeeName)
{
    for(auto coffee: coffeeMenu)
    {
        if(coffee->getName() == coffeeName)
        {
            return coffee;
        }
    }
    cout<<"COFFEE NOT FOUND :("<<endl;
    return NULL;
}

void CoffeeMachine::dispenseCoffee(Coffee* coffee, Payment* payment)
{
    if(payment->getAmount() >= coffee->getPrice())
    {
        if(hasEnoughIngredients(coffee))
        {
            updateIngredients(coffee);
            cout<<"Dispensing "<<coffee->getName()<<endl;
            double change = payment->getAmount() - coffee->getPrice();
            if(change > 0){
                cout<<"Please collect change: Rs."<<change<<endl;
            }
        }
        else{
            cout<<"Insufficient ingredients to make Coffee"<<endl;
        }
    }
    else{
        cout<<"Insufficient payment"<<endl;
    }
}

bool CoffeeMachine::hasEnoughIngredients(Coffee *coffee)
{
    //fix this later
    return true;
}

void CoffeeMachine::updateIngredients(Coffee *coffee)
{
    cout<<"updateIngredients later"<<endl;
}


