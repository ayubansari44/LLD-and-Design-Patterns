#include<bits/stdc++.h>
#include "User.h"
#include "Question.h"
#include "Answer.h"
#include "Tag.h"
#include "Commentable.h"
#include "Votable.h"

class User;
class Question;
class Answer;
class Tag;

using namespace std;

class StackOverflow
{
    private:
        static StackOverflow* instance;
        map<int, User*> users;
        map<int, Question*> questions;
        map<int, Answer*> answers;
        map<string, Tag*> tags;
    
    public:
        StackOverflow();
        static StackOverflow* getInstance();
        User* createUser(string username, string email);
        Question* askQuestion(User* user, string title, string content, vector<string>tags);
        Answer* answerQuestion(User *user, Question* question, string content);
        Comment* addComment(User *user, Commentable* commentable, string content);
        void voteQuestion(User *user, Question *question, int value);
        void voteAnswer(User *user, Answer *question, int value);
        void acceptAnswer(Answer *answer);
        vector<Question*> searchQuestions(string query);
        vector<Question*> getQuestionByUser(User *user);
        User* getUser(int id);
        Question* getQuestion(int id);
        Answer* getAnswer(int id);
        Tag* getTag(string name);
};