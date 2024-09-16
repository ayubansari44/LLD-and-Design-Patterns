#include<bits/stdc++.h>
#include "User.h"
using namespace std;

User::User(int id, string name, string email)
{
    this->id=id;
    this->name=name;
    this->email=email;
    this->reputation=0;
    //NOT REQUIRED TO INITIALISE VECTORS
}

Question* User::askQuestion(string title, string content, vector<string> tags){
    Question *question = new Question(this, title, content, tags);
    questions.push_back(question);
    updateReputation(QUESTION_REPUTATION);
    return question;
}

Answer* User::answerQuestion(Question *question, string content)
{
    Answer *answer = new Answer(this, question, content);
    answers.push_back(answer);
    updateReputation(ANSWER_REPUTATION);
    return answer;
}

Comment* User::addComment(Commentable *commentable, string content)
{
    Comment *comment = new Comment(this, content);
    comments.push_back(comment);
    commentable->addComment(comment);
    updateReputation(COMMENT_REPUTATION);
    return comment;
}

void User::updateReputation(int value)
{
    this->reputation+=value;

    //not sure below code is required
    if(this->reputation < 0){
        this->reputation=0;
    }
}

int User::getId(){
    return id;
}

string User::getUsername(){
    return name;
}

string User::getEmail(){
    return email;
}

int User::getReputation(){
    return reputation;
}

vector<Comment*> User::getComments(){
    return comments;
}

vector<Question*> User::getQuestions(){
    return questions;
}

vector<Answer*> User::getAnswers(){
    return answers;
}