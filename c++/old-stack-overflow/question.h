#pragma once

#include<bits/stdc++.h>
#include "Commentable.h"
#include "Votable.h"
#include "Vote.h"
#include "Tag.h"
#include "Answer.h"
#include "Comment.h"
#include "User.h"

using namespace std;

class Answer;

class Question : public Commentable, public Votable
{
    private:
        int id;
        string title;
        string content;
        User* author;
        string creationDate;
        list<Answer*> answers;
        list<Comment*> comments;
        list<Tag*> tags;
        list<Vote*> votes;
    
    public:
        Question(User* author, string title, string content, list<string> tagNames);

        int generateId();
        void addAnswer(Answer* ans);
        void vote(User* user, int value);
        int getVoteCount();
        void addComment(Comment* comment);
        list<Comment*> getComments();
        int getId();
        User* getAuthor();
        string getTitle();
        string getContent();
        string getCreationDate();
        list<Answer*> getAnswers();
        list<Tag*> getTags();
       
};