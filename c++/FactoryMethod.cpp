#include<bits/stdc++.h>
using namespace std;

class ILogger
{
    public:
        virtual void log() = 0;
};

class InfoLogger : public ILogger{
    public:
        void log(){
            cout<<"InfoLogger created!!"<<endl;
        }
};

class ErrorLogger : public ILogger{
    public:
        void log(){
            cout<<"ErrorLogger created!!"<<endl;
        }
};

class DebugLogger : public ILogger{
    public:
        void log(){
            cout<<"DebugLogger created!!"<<endl;
        }
};

class ILoggerFactory
{
    public:
        virtual ILogger* createFactory()=0;
};

class DebugLoggerFactory : public ILoggerFactory
{
    public:
        ILogger* createFactory()
        {
            return new DebugLogger();
        }
};

class ErrorLoggerFactory : public ILoggerFactory
{
    public:
        ILogger* createFactory()
        {
            return new ErrorLogger();
        }
};

class InfoLoggerFactory : public ILoggerFactory
{
    public:
        ILogger* createFactory()
        {
            return new InfoLogger();
        }
};

int main()
{
    ILoggerFactory *fact = new InfoLoggerFactory();
    ILogger *test = fact->createFactory();
    test->log();
}
