#pragma once
#include<bits/stdc++.h>
#include "User.h"
using namespace std;

class User;

class Votable{
    public:
        void vote(User* user, int value);
        int getVoteCount();
};