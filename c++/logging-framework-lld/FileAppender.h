#ifndef FILEAPPENDER_H
#define FILEAPPENDER_H
#include<bits/stdc++.h>
#include "LogAppender.h"
using namespace std;

class FileAppender : public LogAppender
{
    public:
        void append(LogMessage* logMessage)
        {
            cout<<"File Appender logs message:"<<logMessage<<endl;
            logMessage->display();
        }
};

#endif