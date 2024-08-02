package com.educosys.factoryMethod;

public class ErrorLoggerFactory implements ILoggerFactory{

    public ILogger createLogger()
    {
        System.out.println("ErrorLogger created");
        return new ErrorLogger();
    }


}
