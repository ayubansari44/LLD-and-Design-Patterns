package com.educosys.simpleFactory;

public class LoggerFactory {
//    System.out.println("Welcome to LoggerFactory");

    public static ILogger createLogger(String logger)
    {
        if(logger.equals("INFO"))
        {
            return new InfoLogger();
        }
        else if(logger.equals("ERROR"))
        {
            return new ErrorLogger();
        }
        else if(logger.equals("DEBUG"))
        {
            return new DebugLogger();
        }
        else{
            System.out.println("Please enter a valid input");
            return null;
        }
    }
}
