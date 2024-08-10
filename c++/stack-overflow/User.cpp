#include<bits/stdc++.h>
#include "User.h"
using namespace std;

User::User(int id, string name, string email){
    this->id;
    this->username=name;
    this->email=email;
}

Question* User::askQuestion(string title, string content, list<string> tags)
{
    Question* question = new Question(this, title, content, tags);
    questions.push_back(question);
    updateReputation(QUESTION_REPUTATION);
    return question;
}

Answer* User::answerQuestion(Question* question, string content) {
    Answer* answer = new Answer(this, question, content);
    answers.push_back(answer);
    question->addAnswer(answer);
    updateReputation(ANSWER_REPUTATION); // Gain 10 reputation for answering
    return answer;
}

Comment* User::addComment(Commentable* commentable, string content) {
    Comment* comment = new Comment(this, content);
    comments.push_back(comment);
    commentable->addComment(comment);
    updateReputation(COMMENT_REPUTATION); // Gain 2 reputation for commenting
    return comment;
}

void User::updateReputation(int value)
{
    this->reputation += value;
    if(this->reputation < 0){
        this->reputation = 0;
    }
}

int User::getId(){
    return id;
}

string User::getUsername(){
    return username;
}
int User::getReputation(){
    return reputation;
}

list<Question*> User::getQuestions(){
    return questions;
}

list<Answer*> User::getAnswers(){
    return answers;
}

list<Comment*> User::getComments(){
    return comments;
}



   