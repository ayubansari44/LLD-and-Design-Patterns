#ifndef COMMENT_H
#define COMMENT_H
#include<bits/stdc++.h>
#include "User.h"
using namespace std;

class User;

class Comment
{
    private:
        int id;
        string content;
        User *author;
        string creationDate;
    
    public:
        Comment(User *author, string content);

        int getId();
        User* getAuthor();
        string getContent();
        string getCreationDate();
};


#endif