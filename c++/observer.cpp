#include<bits/stdc++.h>
using namespace std;

class ISubscriber
{
    public:
        virtual void notify(string msg)=0;
};

class User : public ISubscriber
{
    private:
        int userId;
    
    public:
        User(int userId){
            this->userId = userId;
        }

        void notify(string msg){
            cout<<"User "<<userId<<" has been notified that "<< msg<<endl;
        }
};

class Group
{
    private:
        list<ISubscriber*> userList;
    
    public:
        void subscribe(User* user)
        {
            userList.push_back(user);
        }

        void unsubscribe(User* user)
        {
            userList.remove(user);
        }

        void notify(string msg)
        {
            for(auto it: userList)
            {
                it->notify(msg);
            }
        }
};

int main()
{
    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    Group* g1 = new Group();
    g1->subscribe(user1);
    g1->subscribe(user2);
    g1->subscribe(user3);

    g1->notify("You are selected");

    g1->unsubscribe(user2);

    g1->notify("Check your updates please");
}