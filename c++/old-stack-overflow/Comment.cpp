#include<bits/stdc++.h>
#include "Comment.h"
using namespace std;

Comment::Comment(User* author, string content)
{
    this->id = generateId();
    this->author=author;
    this->content=content;
    this->date = "30-07-2024";
}

int Comment::generateId(){
    return 1;
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
    return date;
}
