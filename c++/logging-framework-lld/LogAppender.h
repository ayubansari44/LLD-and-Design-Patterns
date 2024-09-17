#ifndef LOGAPPENDER_H
#define LOGAPPENDER_H
#include<bits/stdc++.h>
#include "LogMessage.h"
using namespace std;

class LogAppender
{
    public:
        virtual void append(LogMessage* logMessage) = 0;
};

#endif