package com.educosys.simpleFactory;

public class Main {
    public static void main(String args[])
    {
        System.out.println("Welcome to Simple Factory Design Pattern!");

        ILogger error = LoggerFactory.createLogger("ERROR");
        error.log();
    }
}
