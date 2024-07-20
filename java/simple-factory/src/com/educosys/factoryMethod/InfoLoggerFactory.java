package com.educosys.factoryMethod;

public class InfoLoggerFactory implements ILoggerFactory{
    public ILogger createLogger()
    {
        System.out.println("InfoLogger created");
        return new InfoLogger();
    }
}
