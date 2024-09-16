#ifndef VOTE_H
#define VOTE_H
#include<bits/stdc++.h>
#include "User.h"
using namespace std;

class User;

class Vote
{
    private:
        User *user;
        int value;
    
    public:
        Vote(User *user, int value);

        User* getUser();

        int getValue();
        
};

#endif