#ifndef INGREDIENT_H
#define INGREDIENT_H
#include<bits/stdc++.h>
using namespace std;

class Ingredient
{
    private:
       string name;
       int quantity;

    public:
        Ingredient(string name, int quantity){
            this->name = name;
            this->quantity = quantity;
        }

        string getName(){
            return name;
        }

        int getQuantity(){
            return quantity;
        }

        void updateQuantity(int amount){
            this->quantity += amount;
        }
};

#endif