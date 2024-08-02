#include<bits/stdc++.h>
#include "User.h"
#include "Tag.h"
#include "Question.h"
#include "Answer.h"
#include "Comment.h"
#include "StackOverflow.cpp"

using namespace std;

int main()
{
    cout<<"Welcome to Stack Overflow!!!"<<endl;
    StackOverflow* system = new StackOverflow();

    User *user1 = system->createUser("Aaron", "aaron@mail.com");
    User *user2 = system->createUser("Steve", "steve@mail.com");
    User *user3 = system->createUser("Dave", "dave@mail.com");

    Question* javaQuestion = system->askQuestion(user1, "What is Polymorphism in Java?", "Please explain with example", {"java", "oops", "cs"});
    Answer *answer = system->answerQuestion(user2, javaQuestion, "Polymorphism means so and so...");
    
    system->addComment(user3, javaQuestion, "I also has same question...");
    system->addComment(user1, javaQuestion, "Thanks for explaination!");

}
