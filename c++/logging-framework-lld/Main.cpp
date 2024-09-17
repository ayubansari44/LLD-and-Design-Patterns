#include<bits/stdc++.h>
#include "Logger.h"
using namespace std;

int main()
{
    cout<<"########## Welcome to Logging Framework LLD ############"<<endl;
    Logger *instance = Logger::getInstance();

    instance->debug("This is DEBUG message.");
    instance->error("This is ERROR message.");
    instance->warning("This is WARNING message.");
    instance->fatal("This is FATAL message.");
    instance->info("This is INFO message.");

}