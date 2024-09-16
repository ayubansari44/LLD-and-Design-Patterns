#include<bits/stdc++.h>
#include "Answer.h"

using namespace std;

Answer::Answer(User *author, Question *question, string content){
    this->id=3001;
    this->author=author;
    this->question=question;
    this->content=content;
    this->creationDate="2024-09-16";
    this->isAccepted=false;
}

void Answer::vote(User* user, int value){
    if(value != 1 && value != -1)
    {
        cout<<endl<<"Vote can either be -1 or +1";
        return;
    }

    //if User exists then remove it
    for (auto it = votes.begin(); it != votes.end();) 
    {
        if ((*it)->getUser() == user) {
            it = votes.erase(it);
        }
    }

    votes.push_back(new Vote(user, value));
    author->updateReputation(value * 10);
}

int Answer::getVoteCount(){
    int sum=0;
    for(auto it: votes){
        sum += it->getValue();
    }
    return sum;
}

void Answer::addComment(Comment *comment){
    comments.push_back(comment);
}

vector<Comment*> Answer::getComments(){
    return comments;
}

void Answer::markAsAccepted(){
    if(isAccepted){
        cout<<endl<<"Answer is already accepted!";
        return;
    }
    isAccepted=true;
    author->updateReputation(15);
}

int Answer::getId(){
    return id;
}

User* Answer::getAuthor(){
    return author;
}

Question* Answer::getQuestion(){
    return question;
}

string Answer::getContent(){
    return content;
}

string Answer::getCreationDate(){
    return creationDate;
}

bool Answer::isAcceptedd(){
    return isAccepted;
}