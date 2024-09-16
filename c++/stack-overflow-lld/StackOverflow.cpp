#include<bits/stdc++.h>
#include "StackOverflow.h"
using namespace std;

StackOverflow* StackOverflow::instance = NULL;

StackOverflow::StackOverflow(){}

StackOverflow* StackOverflow::getInstance()
{
    if(instance==NULL){
        instance = new StackOverflow();
    }
    return instance;
}

User* StackOverflow::createUser(string username, string email)
{
    int id=users.size()+1;
    User *user = new User(id, username, email);
    users[id] = user;
    return user;
}

Question* StackOverflow::askQuestion(User* user, string title, string content, vector<string> tags)
{
    Question *question = user->askQuestion(title, content, tags);
    questions[question->getId()] = question;
    for(auto tag: question->getTags())
    {
        this->tags[tag->getName()] = tag;
    }
    return question;
}

Answer* StackOverflow::answerQuestion(User *user, Question *question, string content)
{
    Answer *answer = user->answerQuestion(question, content);
    answers[answer->getId()] = answer;
    return answer;
}

Comment* StackOverflow::addComment(User *user, Commentable* commentable, string content)
{
    return user->addComment(commentable, content);
}

void StackOverflow::voteQuestion(User* user, Question *question, int value){
    question->vote(user, value);
}


void StackOverflow::voteAnswer(User* user, Answer* answer, int value){
    answer->vote(user, value);
}

void StackOverflow::acceptAnswer(Answer* answer){
    answer->markAsAccepted();
}

vector<Question*> StackOverflow::searchQuestions(string query)
{
    cout<<endl<<"$$$$$$$$$$ No idea how to implement Search query in C++ $$$$$$$$$$$$$$"<<endl;
    return {};
}

vector<Question*> StackOverflow::getQuestionByUser(User *user){
    return user->getQuestions();
}

User* StackOverflow::getUser(int id){
    return users[id];
}

Question* StackOverflow::getQuestion(int id){
    return questions[id];
}

Answer* StackOverflow::getAnswer(int id){
    return answers[id];
}

Tag* StackOverflow::getTag(string name){
    return tags[name];
}

