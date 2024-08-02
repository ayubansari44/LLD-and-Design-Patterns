package com.educosys.factoryMethod;

public class DebugLoggerFactory implements ILoggerFactory{

    public ILogger createLogger()
    {
        System.out.println("DebugLogger created");
        return new DebugLogger();
    }
}
