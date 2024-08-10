#include "Question.h"
#include<bits/stdc++.h>
using namespace std;

Question::Question(User* author, string title, string content, list<string> tagNames)
{
    this->id = generateId();
    this->author=author;
    this->title=title;
    this->content=content;
    this->creationDate="31-07-2024";
    for(auto it: tagNames){
        Tag *obj = new Tag(it);
        this->tags.push_back(obj);
    }
}

int Question::generateId(){
    return 1;
}

void Question::addAnswer(Answer *answer){
    if(std::find(answers.begin(), answers.end(), answer) == answers.end()){
        answers.push_back(answer);
    }
}

//for stl list.is_remove
bool isTrue(Vote* vote, User* user) {
    return vote->getUser() == user;
}

void Question::vote(User* user, int value)
{
    if(value != 1 && value!= -1){
        cout<<"Value has to be either -1 or +1";
    }

    // votes.remove_if(isTrue, User* user);
    votes.remove_if([user](Vote* vote) { return isTrue(vote, user); });
    Vote *vote = new Vote(user, value);
    votes.push_back(vote);
    author->updateReputation(value*5);
}

int Question::getVoteCount()
{
    //syntax is different from Source
    int ans = 0;
    for(auto it: votes)
    {
        ans+=it->getValue();
    }
    return ans;
}

void Question::addComment(Comment* comment){
    comments.push_back(comment);
}

list<Comment*> Question::getComments(){
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

list<Answer*> Question::getAnswers(){
    return answers;
}

list<Tag*> Question::getTags(){
    return tags;
}