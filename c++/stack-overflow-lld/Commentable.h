#ifndef COMMENTABLE_H
#define COMMENTABLE_H
#include<bits/stdc++.h>
#include "Comment.h"
using namespace std;

class Comment;

class Commentable
{
    public:
        virtual void addComment(Comment *comment)=0;
        virtual vector<Comment*> getComments()=0;
};


#endif