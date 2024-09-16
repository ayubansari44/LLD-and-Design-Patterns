#ifndef ANSWER_H
#define ANSWER_H
#include<bits/stdc++.h>
#include "Question.h"
#include "Votable.h"
#include "Commentable.h"
#include "Comment.h"
#include "User.h"

using namespace std;

class Comment;
class Question;
class Vote;
class User;

class Answer : public Votable, public Commentable
{
    private:
        int id;
        string content;
        User* author;
        Question *question;
        bool isAccepted;
        string creationDate;
        vector<Comment*> comments;
        vector<Vote*> votes;
    
    public:
        Answer(User *author, Question *question, string content);
        void vote(User *user, int value);
        int getVoteCount();
        void addComment(Comment *comment);
        vector<Comment*> getComments();
        void markAsAccepted();
        
        int getId();
        User* getAuthor();
        Question* getQuestion();
        string getContent();
        string getCreationDate();
        bool isAcceptedd();
};

#endif