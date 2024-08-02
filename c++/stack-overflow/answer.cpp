#include<Answer.h>
#include<bits/stdc++.h>
using namespace std;

Answer::Answer(User* author, Question* question, string content)
{
    this->id = generateId();
    this->author=author;
    this->question=question;
    this->content=content;
    this->creationDate="31-07-2024";
    this->isAccepted=false;
}

int Answer::generateId(){
    return 1;
}

bool isTrue(Vote* vote, User* user) {
    return vote->getUser() == user;
}

void Answer::vote(User* user, int value)
{
    if(value != 1 && value!= -1){
        cout<<"Value has to be either -1 or +1";
    }

    // votes.remove_if(isTrue, User* user);
    votes.remove_if([user](Vote* vote) { return isTrue(vote, user); });
    Vote *vote = new Vote(user, value);
    votes.push_back(vote);
    author->updateReputation(value*10);
}

int Answer::getVoteCount()
{
    //syntax is different from Source
    int ans = 0;
    for(auto it: votes)
    {
        ans+=it->getValue();
    }
    return ans;
}

void Answer::addComment(Comment* comment){
    comments.push_back(comment);
}

list<Comment*> Answer::getComments(){
    return comments;
}

void Answer::markAsAccepted()
{
    if(isAccepted){
        cout<<"This answer is already accepted";
    }
    else{
        isAccepted=true;
        author->updateReputation(15);
    }
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

bool Answer::getIsAccepted(){
    return isAccepted;
}