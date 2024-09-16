#include<bits/stdc++.h>
#include "Tag.h"
using namespace std;

Tag::Tag(string name)
{   
    this->id=1;
    this->name = name;
}

int Tag::getId(){
    return id;
}

string Tag::getName(){
    return name;
}

