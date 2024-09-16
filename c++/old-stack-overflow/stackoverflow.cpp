#include<bits/stdc++.h>
#include "User.h"
#include "Tag.h"
#include "Question.h"
#include "Answer.h"
using namespace std;

class StackOverflow
{
    private:
        map<int, User*> users;
        map<int, Question*> questions;
        map<int, Answer*> answers;
        map<string, Tag*> tags;
    public:
        StackOverflow(){

        }

        User* createUser(string username, string email)
        {
            int id = users.size()+1;
            User *user = new User(id, username, email);
            users[id] = user;
            return user;
        }

        Question* askQuestion(User *user, string title, string content, list<string> tags)
        {
            Question *question = user->askQuestion(title, content, tags);
            questions[question->getId()] = question;
            for(auto it: question->getTags()){
                this->tags[it->getName()] = it;
            }
            return question;
        }

        Answer* answerQuestion(User* user, Question* question, string content)
        {
            Answer* answer = user->answerQuestion(question, content);
            answers[answer->getId()] = answer;
            return answer;   
        }

        Comment* addComment(User *user, Commentable *commentable, string content){
            return user->addComment(commentable, content);
        }

        void voteQuestion(User* user, Question* question, int value){
            question->vote(user, value);
        }

        void voteAnswer(User* user, Answer* answer, int value){
            answer->markAsAccepted();
        }

        list<Question*> searchQuestions(string query)
        {
            //do later
            return {};
        }

        list<Question*> getQuestionsByUser(User *user){
            return user->getQuestions();
        }

        User* getUser(int id){
            return users[id];
        }

        Question* getQuestion(int id){
            return questions[id];
        }

        Answer* getAnswer(int id){
            return answers[id];
        }

        Tag* getTag(string name){
            return tags[name];
        }
};
