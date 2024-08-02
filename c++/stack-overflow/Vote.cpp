#include<bits/stdc++.h>
#include<Vote.h>
using namespace std;

Vote::Vote(User* user, int value)
{
    this->user=user;
    this->value=value;
}

User* Vote::getUser(){
    return user;
}

int Vote::getValue(){
    return value;
}


