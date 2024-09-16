#include<bits/stdc++.h>
#include "StackOverflow.h"
using namespace std;

int main()
{
    cout<<"###### Welcome to Stack Overflow LLD #########"<<endl;
    StackOverflow* instance = StackOverflow::getInstance();

    User *don = instance->createUser("Don", "don@gmail.com");
    User *pathan = instance->createUser("Pathan", "pathan@gmail.com");
    User *rahul = instance->createUser("Rahul", "rahul@gmail.com");

    Question* javaQuestion = instance->askQuestion(don, "What is Abstraction?", "Please explain abstraction in Java", {"oops", "java"});
    Answer* javaAnswer = instance->answerQuestion(pathan, javaQuestion, "Process of hiding unnecessary details in called Abstaction!");

    instance->addComment(rahul, javaQuestion, "I also had the same question");
    instance->addComment(don, javaQuestion, "Thanks for the answer!");

    instance->voteQuestion(rahul, javaQuestion, 1);
    instance->voteAnswer(rahul, javaAnswer, 1);

    instance->acceptAnswer(javaAnswer);

    cout<<"Question:"<<javaQuestion->getTitle()<<endl;
    cout<<"Asked by:"<<javaQuestion->getAuthor()->getUsername()<<endl;
    cout<<"Tags:"<<endl;
    for(auto it: javaQuestion->getTags()){
        cout<<it->getName()<<", ";
    }
    cout<<endl;

    cout<<"Votes:"<<javaQuestion->getVoteCount()<<endl;
    cout<<"Comments:"<<javaQuestion->getComments().size()<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"Answer by:"<<javaAnswer->getAuthor()->getUsername()<<endl;
    cout<<"Votes:"<<javaAnswer->getVoteCount()<<endl;
    cout<<"Accepted:"<<javaAnswer->isAcceptedd()<<endl;
    cout<<"Comments:"<<javaAnswer->getComments().size()<<endl;

    cout<<"User Reputation:"<<endl;
    cout<<"Don:"<<don->getReputation()<<endl;
    cout<<"Pathan:"<<pathan->getReputation()<<endl;
    cout<<"Rahul:"<<rahul->getReputation()<<endl;

}