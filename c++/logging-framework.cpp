#include<bits/stdc++.h>
using namespace std;

enum LogLevel
{
    ERROR,
    DEBUG,
    WARNING,
    INFO,
    FATAL,
};
class LogMessage
{
    private:
        string message;
        string timestamp;
        LogLevel level;
    public:
        LogMessage() {}

        LogMessage(LogLevel level, string message)
        {
            this->level = level;
            this->message = message;
            this->timestamp = "2024-08-10";
        }

        string getMessage(){
            return message;
        }

        LogLevel getLevel(){
            return level;
        }
};
class LogAppender
{
    public:
        virtual void append(LogMessage* message) = 0;
};

class ConsoleAppender: public LogAppender
{
    public:
        void append(LogMessage* message)
        {
            cout<<"[Console Appender]:"<<message->getMessage()<<endl;
        }
};

class DatabaseAppender: public LogAppender
{
    public:
        void append(LogMessage* message)
        {
            cout<<"[Database Appender]:"<<message->getMessage()<<endl;
        }
};

class FileAppender: public LogAppender
{
    public:
        void append(LogMessage* message) 
        {
            cout<<"[File Appender]:"<<message->getMessage()<<endl;
        }
};

class LogConfig
{
    private:
        LogLevel level;
        LogAppender* appender;
    
    public:
    LogConfig(LogLevel level, LogAppender* appender)
    {
        this->level = level;
        this->appender = appender;
    }

    LogAppender* getAppender(){
        return appender;
    }

    void setAppender(LogAppender* appender){
        this->appender = appender;
    }

    LogLevel getLogLevel(){
        return level;
    }

    void setLogLevel(LogLevel level){
        this->level = level;
    }
};

class Logger
{
    private:
        static Logger* instance;
        LogConfig *config;
    
    public:
        Logger()
        {
            config = new LogConfig(LogLevel::INFO, new ConsoleAppender());
        }

        static Logger* getInstance()
        {
            if(instance == NULL){
                instance = new Logger();
            }
            return instance;
        }

        void setConfig(LogConfig *config){
            this->config=config;
        }

        void log(LogLevel level, string message)
        {
            LogMessage *logMessage = new LogMessage(level, message);
            config->getAppender()->append(logMessage);
        }

        void debug(string message){
            log(LogLevel::DEBUG, message);
        }

        void info(string message) {
            log(LogLevel::INFO, message);
        }

        void warning(string message) {
            log(LogLevel::WARNING, message);
        }

        void error(string message) {
            log(LogLevel::ERROR, message);
        }

        void fatal(string message) {
            log(LogLevel::FATAL, message);
        }
};

Logger* Logger::instance = NULL;

int main()
{
    //*************start here tomorrow 08-08-2024 *********************
    cout<<"Welcome to Logging Framework!!!"<<endl;
    Logger *logger = Logger::getInstance();
    logger->debug("This is debug");
    logger->error("This is Error");
    logger->warning("This is Warning");
   
    LogConfig *config = new LogConfig(LogLevel::DEBUG, new FileAppender());
    logger->setConfig(config);

    logger->debug("This is debug again!");
    logger->info("This is info again!");
    logger->warning("This is warning again!");
}