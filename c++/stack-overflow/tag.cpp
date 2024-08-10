#include<bits/stdc++.h>
#include "tag.h"
using namespace std;

Tag::Tag(string name){
    this->id = generateId();
    this->name=name;
}

int Tag:: generateId(){
    return 1;
}

int Tag::  getId(){
    return id;
}

string Tag:: getName(){
    return name;
}

