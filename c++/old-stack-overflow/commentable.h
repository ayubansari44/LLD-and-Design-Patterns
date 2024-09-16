#pragma once
#include<bits/stdc++.h>
using namespace std;
#include "Comment.h"

class Comment;

class Commentable
{
    public:
        virtual void addComment(Comment* comment) = 0;
        virtual list<Comment*> getComments() = 0;
};

