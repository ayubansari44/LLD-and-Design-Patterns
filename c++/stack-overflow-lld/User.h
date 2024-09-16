#ifndef USER_H
#define USER_H

#include<bits/stdc++.h>
#include "Tag.h"
#include "Answer.h"
#include "Question.h"
#include "Comment.h"
#include "Commentable.h"

using namespace std;

class Tag;
class Question;
class Answer;
class Comment;

class User
{
    private:
        int id;
        string name, email;
        int reputation;
        // int tags[Tag*];
        vector<Comment*> comments;
        vector<Question*> questions;
        vector<Answer*> answers;

        static const int QUESTION_REPUTATION = 5;
        static const int ANSWER_REPUTATION = 10;
        static const int COMMENT_REPUTATION = 2;

    public:
        User(int id, string name, string email);
        Question* askQuestion(string title, string content, vector<string> tags);
        Answer* answerQuestion(Question *question, string content);
        Comment* addComment(Commentable *commentable, string content);
        void updateReputation(int value);

        int getId();
        string getUsername();
        string getEmail();
        int getReputation();
        vector<Question*> getQuestions();
        vector<Answer*> getAnswers();
        vector<Comment*> getComments();
};



#endif