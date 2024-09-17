#include "LogMessage.h"

LogMessage ::LogMessage(LogLevel level, string message)
{
    this->message = message;
    this->level = level;
}

string LogMessage::getMessage(){
    return message;
}

LogLevel LogMessage::getLogLevel(){
    return level;
}

string LogMessage::getTimestamp(){
    return timestamp;
}

void LogMessage::display(){
    cout<<"Message:"<<message<<", LogLevel:"<<level<<", Timestamp:"<<timestamp<<endl;
}