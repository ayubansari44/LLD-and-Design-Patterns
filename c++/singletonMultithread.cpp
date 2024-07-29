#include<bits/stdc++.h>
#include<mutex>
using namespace std;

//Includes check for multithreading
class Singleton
{
    private:
        static Singleton *instance;
        static mutex mtx; // Mutex is added to Thread safety

        Singleton()
        {
            cout<<"SingletonMultithread class initialized!"<<endl;
        }
    
    public:
        static Singleton* getInstance()
        {
            //***************Implemented Double Checked locking*********
            if(instance==NULL)
            {
                mtx.lock();
                if(instance==NULL)
                {
                    instance=new Singleton();
                    mtx.unlock();
                }
            }
            return instance;
        }

        void showMessage(){
            cout<<"SingletonMultithread says hello!"<<endl;
        }
};

Singleton* Singleton :: instance = NULL;
mutex Singleton :: mtx;

int main()
{
    Singleton* s = Singleton::getInstance();
    s->showMessage();

    Singleton *t = Singleton::getInstance();
    t->showMessage();
}