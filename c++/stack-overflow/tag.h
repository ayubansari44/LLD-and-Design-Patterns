#pragma once
#include<bits/stdc++.h>

using namespace std;

class Tag
{
    private:
        int id;
        string name;
    
    public:
        Tag(string name);

        int generateId();
        int getId();
        string getName();
};