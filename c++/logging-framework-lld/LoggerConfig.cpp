#include "LoggerConfig.h"

LoggerConfig :: LoggerConfig(LogLevel level, LogAppender *logAppender)
{
    this->logLevel = level;
    this->logAppender = logAppender;
}

LogLevel LoggerConfig ::getLogLevel(){
    return logLevel;
}

void LoggerConfig ::setLogLevel(LogLevel level){
    this->logLevel=level;
}

LogAppender* LoggerConfig ::getLogAppender()
{
    return logAppender;
}

void LoggerConfig ::setLogAppender(LogAppender* logAppender){
    this->logAppender = logAppender;
}