#include<bits/stdc++.h>
using namespace std;

class User
{
    private:
        string id, name, email;
    public:
        User(){

        }

        User(string id, string name, string email)
        {
            this->id = id;
            this->name = name;
            this->email = email;
        }

        string getId(){
            return id;
        }

        string getName(){
            return name;
        }

};

enum TaskStatus
{
    STARTED,
    IN_PROGRESS,
    COMPLETED
};

class Task
{
    private:
        string id, title, description, dueDate;
        int priority;
        TaskStatus status;
        User* assignedUser;
    
    public:
        Task()
        {

        }

        Task(string id, string name, string desc, string date, User* user)
        {
            this->id = id;
            this->title = name;
            this->description = desc;
            this->dueDate = date;
            this->priority=0;
            this->status = TaskStatus::COMPLETED;
            this->assignedUser = user;
        }

        string getId(){
            return this->id;
        }

        void setId(string id){
            this->id=id;
        }

        string getTitle(){
            return title;
        }

        void setTitle(string title){
            this->title=title;
        }

        string getDescription(){
            return description;
        }

        void setDescription(string desc){
            this->description=desc;
        }

        string getDueDate(){
            return dueDate;
        }

        void setDueDate(string dueDate){
            this->dueDate=dueDate;
        }

        int getPriority(){
            return priority;
        }

        void setPriority(int prio){
            this->priority=prio;
        }

        TaskStatus getStatus(){
            return status;
        }

        void setStatus(TaskStatus status){
            this->status = status;
        }

        User* getAssignedUser(){
            return this->assignedUser;
        }

        void setAssignedUser(User *user){
            this->assignedUser = user;
        }

        void displayTask() const {
            cout << "Task ID: " << id << endl;
            cout << "Title: " << title << endl;
            cout << "Description: " << description << endl;
            cout << "Due Date: " << dueDate << endl;
            cout << "Priority: " << priority << endl;
            cout << "Status: " << (status == STARTED ? "Started" : (status == IN_PROGRESS ? "In Progress" : "Completed")) << endl;
            if (assignedUser != nullptr) {
                cout << "Assigned User: " << assignedUser->getName() << endl;
            } else {
                cout << "Assigned User: None" << endl;
            }
        }

};

class TaskManager
{
    private:
        static TaskManager* instance;
        unordered_map<string, Task*> tasks;
        unordered_map<string, vector<Task*>> userTask;
    
    public:
        static TaskManager* getInstance()
        {
            if(instance==NULL)
            {
                instance=new TaskManager();
            }
            return instance;
        }

        void createTask(Task* task)
        {
            tasks[task->getId()] = task;
            // assignTaskToUser(task->getAssignedUser(), task);
            assignTaskToUser(task->getAssignedUser(), task);
        }

        void updateTask(Task* newTask)
        {
            //basically look for same id and update
            if(tasks.find(newTask->getId()) != tasks.end())
            {
                Task *existingTask = tasks[newTask->getId()];
                existingTask->setTitle(newTask->getTitle());
                existingTask->setDescription(newTask->getDescription());
                existingTask->setDueDate(newTask->getDueDate());
                existingTask->setPriority(newTask->getPriority());
                existingTask->setStatus(newTask->getStatus());
                //before updating user you can if Task is assigned to same user, so that updation could be avoided
                // existingTask->setAssignedUser(newTask->getAssignedUser());
                // assignTaskToUser(newTask->getAssignedUser(), newTask);
            }
        }

        void deleteTask(Task *task)
        {
            if(tasks.find(task->getId()) != tasks.end())
            {
                tasks.erase(task->getId());
                unassignTaskFromUser(task->getAssignedUser(), task);
            }
            else{
                cout<<"Deletion is not possible since ID does not exist";
            }
        }

        vector<Task*> searchTask(string key)
        {
            vector<Task*> ans;
            for(auto it: tasks)
            {
                Task* task = it.second;
                if(task->getTitle().find(key) != string::npos || 
                    task->getDescription().find(key) != string::npos)
                {
                    ans.push_back(task);
                }
            }

            return ans;
        }

        void assignTaskToUser(User* user, Task* task)
        {
            userTask[user->getId()].push_back(task);
        }

        void unassignTaskFromUser(User *user, Task* task)
        {
            if (user == nullptr || task == nullptr) {
                cout << "Invalid user or task." << endl;
                return;
            }

            string userId = user->getId();
            if(userTask.find(userId) != userTask.end())
            {
                auto& tasksForUser = userTask[userId];
                auto it = std::find(tasksForUser.begin(), tasksForUser.end(), task);
                if (it != tasksForUser.end())
                {
                    tasksForUser.erase(it);
                    // cout << "Task unassigned from user: " << userId << endl;
                }
                else
                {
                    cout << "Task not found for the given user." << endl;
                }
            }
            else
            {
                cout << "User not found." << endl;
            }
        }

        void displayAllTasks()
        {
            cout<<"Displaying all tasks:"<<endl;
            for (auto it : tasks)
            {
                it.second->displayTask();
                cout << "-----------------------------" << endl;
            }
        }

        void displayUserTasks(User* user)
        {
            cout<<"Displaying all tasks of "<<user->getName()<<endl;
            if(user == nullptr)
            {
                cout << "Invalid user." << endl;
                return;
            }

            string userId = user->getId();
            cout<<"current vector size:"<<userTask[userId].size()<<endl;
            if(userTask.find(userId) != userTask.end())
            {
                for(auto task : userTask[userId])
                {
                    task->displayTask();
                    cout << "-----------------------------" << endl;
                }
            }
            else
            {
                cout << "No tasks found for user: " << userId << endl;
            }
        }
        
        
};

TaskManager* TaskManager::instance = NULL;

int main()
{
    cout<<"Welcome to Task Management System!!"<<endl;

    TaskManager *taskManager = TaskManager::getInstance();
    User *user1 = new User("1001", "mark", "mark@mail.com");
    User *user2 = new User("1002", "shawn", "shawn@mail.com");

    Task *t1 = new Task("1", "Graphs", "Go through Striver's Sheet", "28-07-2024", user1);
    Task *t2 = new Task("2", "Stack", "Go through Striver's Sheet", "01-02-2024", user1);
    Task *t3 = new Task("3", "Binary Search", "Go through Striver's Sheet", "15-08-2024", user2);

    taskManager->createTask(t1);
    taskManager->createTask(t2);
    taskManager->createTask(t3);

    t1->setDescription("Follow NeetCode please");
    taskManager->updateTask(t1);
    taskManager->displayAllTasks();//display only tasks

    taskManager->deleteTask(t2);
    taskManager->displayAllTasks();//display only tasks
    taskManager->displayUserTasks(user1); //display all users with tasks
}
