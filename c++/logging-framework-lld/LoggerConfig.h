#ifndef LOGCONFIG_H
#define LOGCONFIG_H
#include<bits/stdc++.h>
#include "LogAppender.h"
#include "LogLevel.h"

using namespace std;

class LoggerConfig
{
    private:
        LogLevel logLevel;
        LogAppender *logAppender;
    public:
        LoggerConfig(LogLevel level, LogAppender *logAppender);
        LogLevel getLogLevel();
        void setLogLevel(LogLevel level);
        LogAppender* getLogAppender();
        void setLogAppender(LogAppender* logAppender);
};

#endif