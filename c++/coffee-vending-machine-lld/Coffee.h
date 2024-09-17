#ifndef COFFEE_H
#define COFFEE_H
#include<bits/stdc++.h>
#include "Ingredient.h"

using namespace std;

class Coffee
{
    private:
        string name;
        double price;
        map<Ingredient*, int> recipe;
        
    public:
        Coffee(string name, double price, map<Ingredient*, int> recipe);
        string getName();
        double getPrice();
        map<Ingredient*, int> getRecipe();
};

#endif