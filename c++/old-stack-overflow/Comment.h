#pragma once
#include<bits/stdc++.h>
#include "Answer.h"
#include "Question.h"
#include "User.h"

using namespace std;

class Comment
{
    private:
        int id;
        string content;
        User* author;
        string date;
    public:
        Comment(User* author, string content);
        int generateId();
        int getId();
        User* getAuthor();
        string getContent();
        string getCreationDate();
};