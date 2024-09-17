#include "Coffee.h"

Coffee::Coffee(string name, double quantity, map<Ingredient*, int> recipe)
{
    this->name = name;
    this->price = quantity;
    this->recipe = recipe;
}

string Coffee::getName(){
    return name;
}

double Coffee::getPrice(){
    return price;
}

map<Ingredient*, int> Coffee::getRecipe(){
    return recipe;
}