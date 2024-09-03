#include <bits/stdc++.h>
using namespace std;

class ILogger
{
public:
    virtual void log() = 0;
    virtual ~ILogger() {}
};

class InfoLogger : public ILogger
{
public:
    void log() override
    {
        cout << "InfoLogger created" << endl;
    }
};

class ErrorLogger : public ILogger
{
public:
    void log() override
    {
        cout << "ErrorLogger created" << endl;
    }
};

class DebugLogger : public ILogger
{
public:
    void log() override
    {
        cout << "DebugLogger created" << endl;
    }
};

class LoggerFactory
{
public:
    static ILogger *createLogger(string fact)
    {
        if (fact == "ERROR")
        {
            return new ErrorLogger();
        }

        else if (fact == "INFO")
        {
            return new InfoLogger();
        }

        else if (fact == "DEBUG")
        {
            return new DebugLogger();
        }
        else
            return NULL;
    }
};

int main()
{
    int x;
    cout << "Welcome to Simple Factory Class" << endl;
    int ch;

    do
    {
        cout << "Enter a choice for Logger 1.Debug 2.Error 3.Info 0.Exit" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            ILogger *debug = LoggerFactory::createLogger("DEBUG");
            debug->log();
        }
        break;

        case 2:
        {
            ILogger *error = LoggerFactory::createLogger("ERROR");
            error->log();
        }

        break;

        case 3:
        {
            ILogger *info = LoggerFactory::createLogger("INFO");

            info->log();
        }

        break;
        }
    } while (ch != 0);
    return 0;
}