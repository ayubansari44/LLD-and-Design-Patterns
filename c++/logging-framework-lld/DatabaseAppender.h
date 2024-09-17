#ifndef DATABASEAPPENDER_H
#define DATABASEAPPENDER_H
#include<bits/stdc++.h>
#include "LogAppender.h"
using namespace std;

class DatabaseAppender : public LogAppender
{
    public:
        void append(LogMessage* logMessage)
        {
            cout<<"Database Appender logs message:"<<logMessage<<endl;
            logMessage->display();
        }
};

#endif