#pragma once

#include<bits/stdc++.h>
#include "Commentable.h"
#include "Votable.h"
#include "Vote.h"
#include "Tag.h"
#include "Question.h"

using namespace std;

class Question;

class Answer : public Commentable, public Votable
{
    private:
        int id;
        string content;
        User* author;
        Question* question;
        string creationDate;
        list<Comment*> comments;
        list<Vote*> votes;
    
    public:
        bool isAccepted;
        Answer(User* author, Question* question, string content);

        int generateId();
        void vote(User* user, int value);
        int getVoteCount();
        void addComment(Comment* comment);
        list<Comment*> getComments();
        void markAsAccepted();
        int getId();
        User* getAuthor();
        Question* getQuestion();
        string getContent();
        string getCreationDate();
        bool getIsAccepted();
};