#ifndef QUESTION_H
#define QUESTION_H
#include<bits/stdc++.h>
#include "Answer.h"
#include "Comment.h"
#include "Tag.h"
#include "Vote.h"
#include "Commentable.h"
#include "Votable.h"
#include "User.h"

using namespace std;

class Comment;
class Answer;
class Vote;
class User;
class Tag;


class Question : public Commentable, public Votable
{
    private:
        int id;
        string title, content;
        User *author;
        string creationDate;
        vector<Answer*> answers;
        vector<Comment*> comments;
        vector<Tag*> tags;
        vector<Vote*> votes;
    public:
        Question(User *author, string title, string content, vector<string> tagNames);

        void addAnswer(Answer *answer);
        void vote(User *user, int value);
        int getVoteCount();
        void addComment(Comment *comment);
        vector<Comment*> getComments();

        int getId();
        User *getAuthor();
        string getTitle();
        string getContent();
        string getCreationDate();
        vector<Answer*> getAnswers();
        vector<Tag*> getTags();
};


#endif