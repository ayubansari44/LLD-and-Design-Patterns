#ifndef VOTABLE_H
#define VOTABLE_H
#include<bits/stdc++.h>
#include "User.h"
using namespace std;

class User;

class Votable
{
    public:
        virtual void vote(User *user, int value)=0;
        virtual int getVoteCount()=0;
};

#endif