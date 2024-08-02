#pragma once
#include<bits/stdc++.h>
#include "Comment.h"
#include "commentable.h"
#include "Answer.h"
#include "Question.h"

using namespace std;

class User
{
    private:
        int id;
        int reputation;
        string username;
        string email;
        list<Question*> questions;
        list<Answer*> answers;
        list<Comment*> comments;

        int QUESTION_REPUTATION = 5;
        int ANSWER_REPUTATION = 10;
        int COMMENT_REPUTATION = 2;

    public:
        User(int id, string name, string email);

        Question* askQuestion(string title, string content, list<string> tags);
        Answer* answerQuestion(Question* question, string content);
        Comment* addComment(Commentable* commentable, string content);
        void updateReputation(int value);
        int getId();
        string getUsername();
        int getReputation();
        list<Question*> getQuestions();
        list<Answer*> getAnswers();
        list<Comment*> getComments();
};