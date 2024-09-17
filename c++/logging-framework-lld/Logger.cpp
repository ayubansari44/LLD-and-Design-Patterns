#include "Logger.h"

Logger* Logger::instance = NULL;

Logger ::Logger(){
    this->config = new LoggerConfig(LogLevel::INFO, new ConsoleAppender());
}

Logger* Logger:: getInstance()
{
    if(instance==NULL)
        instance = new Logger();

    return instance;
}

void Logger::setConfig(LoggerConfig *config){
    this->config = config;
}

void Logger::log(LogLevel level, string message)
{
    LogMessage *logMessage = new LogMessage(level, message);
    config->getLogAppender()->append(logMessage);
}

void Logger::debug(string message){
    log(LogLevel::DEBUG, message);
}

void Logger::error(string message){
    log(LogLevel::ERROR, message);
}

void Logger::fatal(string message){
    log(LogLevel::FATAL, message);
}

void Logger::warning(string message){
    log(LogLevel::WARNING, message);
}

void Logger::info(string message){
    log(LogLevel::INFO, message);
}
