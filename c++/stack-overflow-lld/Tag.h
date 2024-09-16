#ifndef TAG_H
#define TAG_H
#include<bits/stdc++.h>
using namespace std;

class Tag
{
    private:
        int id;
        string name;
    
    public:
        Tag(string name);

        int getId();

        string getName();
        
};

#endif