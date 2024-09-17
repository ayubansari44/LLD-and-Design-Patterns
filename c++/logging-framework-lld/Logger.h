#ifndef LOGGER_H
#define LOGGER_H
#include<bits/stdc++.h>
#include "LogAppender.h"
#include "LogLevel.h"
#include "LoggerConfig.h"
#include "ConsoleAppender.h"

using namespace std;

class Logger
{
    private:
        static Logger* instance;
        LoggerConfig* config;
    
    public:
        Logger();
        static Logger* getInstance();
        void setConfig(LoggerConfig *config);
        void log(LogLevel level, string message);
        void debug(string message);
        void error(string message);
        void fatal(string message);
        void info(string message);
        void warning(string message);

};

#endif