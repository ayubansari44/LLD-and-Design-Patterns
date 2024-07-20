package com.educosys.factoryMethod;

import java.util.Scanner;

public class Main {
    public static void main(String args[])
    {
        System.out.println("Welcome to Factory Method Design Pattern!");
        Scanner scan = new Scanner(System.in);
        int ch;

        do{
            System.out.println("Please choose a Logger 1.Info 2.Debug 3.Error 0.Exit");
            ch = scan.nextInt();

            ILoggerFactory fact;

            switch(ch)
            {
                case 1: fact=new InfoLoggerFactory();
                        fact.createLogger();
                        break;
                case 2: fact=new DebugLoggerFactory();
                    fact.createLogger();
                    break;
                case 3: fact=new ErrorLoggerFactory();
                    fact.createLogger();
                    break;
                default: break;
            }
        }while(ch!=0);

//        ILoggerFactory fact = new DebugLoggerFactory();
//        fact.createLogger();
    }
}
