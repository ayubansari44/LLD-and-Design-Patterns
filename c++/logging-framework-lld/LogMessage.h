#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H
#include<bits/stdc++.h>
#include "LogLevel.h"
using namespace std;

class LogMessage
{
    private:
        string message, timestamp;
        LogLevel level;
    
    public:
        LogMessage(LogLevel level, string message);
        string getMessage();
        string getTimestamp();
        LogLevel getLogLevel();
        void display();
};

#endif