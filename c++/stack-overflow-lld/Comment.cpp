#include<bits/stdc++.h>
#include "Comment.h"

using namespace std;

Comment::Comment(User *author, string content){
    this->id = 1001;
    this->author=author;
    this->content=content;
    this->creationDate = "2024-06-16";
}

int Comment::getId(){
    return id;
}

User* Comment::getAuthor(){
    return author;
}

string Comment::getContent(){
    return content;
}

string Comment::getCreationDate(){
    return creationDate;
}