#include<bits/stdc++.h>
using namespace std;

//basic without multithreading
class Singleton
{
    private:
        //************Very important -> Constructor is private **************
        static Singleton *instance;

        Singleton()
        {
            cout<<"Singleton class initialized!"<<endl;
        }
    
    public:
        static Singleton* getInstance()
        {
            if(instance==NULL)
            {
                instance=new Singleton();
            }
            return instance;
        }

        void showMessage(){
            cout<<"Singleton says hello!"<<endl;
        }
};

Singleton* Singleton :: instance = NULL;

int main()
{
    Singleton* s = Singleton::getInstance();
    s->showMessage();

    Singleton *t = Singleton::getInstance();
    t->showMessage();
}