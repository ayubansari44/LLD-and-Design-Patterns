#ifndef CONSOLEAPPENDER_H
#define CONSOLEAPPENDER_H
#include<bits/stdc++.h>
#include "LogAppender.h"
using namespace std;

class ConsoleAppender : public LogAppender
{
    public:
        void append(LogMessage* logMessage)
        {
            cout<<"Console Appender logs message:"<<endl;
            logMessage->display();
        }
};

#endif