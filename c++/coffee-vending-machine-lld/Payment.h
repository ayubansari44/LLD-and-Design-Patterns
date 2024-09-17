#ifndef PAYMENT_H
#define PAYMENT_H
#include<bits/stdc++.h>
using namespace std;

class Payment
{
    private:
      double amount;
      
    public:
        Payment(double amount){
            this->amount = amount;
        }

        double getAmount(){
            return amount;
        }
};

#endif