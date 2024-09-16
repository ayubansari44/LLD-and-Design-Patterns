#include<bits/stdc++.h>
#include "Question.h"


using namespace std;

Question::Question(User *author, string title, string content, vector<string> tagNames)
{
    this->id=2001;
    this->author=author;
    this->title=title;
    this->content=content;
    this->creationDate="2024-09-16";
    for(auto tag: tagNames){
        tags.push_back(new Tag(tag));
    }
}

void Question::addAnswer(Answer *answer)
{    
    if(find(answers.begin(), answers.end(), answer) == answers.end())
        answers.push_back(answer);
}

void Question::vote(User *user, int value)
{
    if(value != 1 && value!= -1){
        cout<<endl<<"Value of vote either can be +1 or -1"<<endl;
        return;
    }

    //if User exists then remove it
    for (auto it = votes.begin(); it != votes.end(); ) 
    {
        if ((*it)->getUser() == user) {
            it = votes.erase(it);
        }
    }

    votes.push_back(new Vote(user, value));
    author->updateReputation(value * 5);
}

int Question::getVoteCount(){
    int sum=0;
    for(auto it: votes){
        sum += it->getValue();
    }
    return sum;
}

void Question::addComment(Comment *comment){
    comments.push_back(comment);
}

vector<Comment*> Question::getComments(){
    return comments;
}

int Question::getId(){
    return id;
}

User* Question::getAuthor(){
    return author;
}

string Question::getTitle(){
    return title;
}

string Question::getContent(){
    return content;
}

string Question::getCreationDate(){
    return creationDate;
}

vector<Answer*> Question::getAnswers(){
    return answers;
}

vector<Tag*> Question::getTags(){
    return tags;
}