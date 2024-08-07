#include<bits/stdc++.h>
using namespace std;

enum Direction{
    UP,
    DOWN
};

class Request{
    private:
        int sourceFloor, destFloor;
    public:
        Request(int src, int dest)
        {
            this->sourceFloor = src;
            this->destFloor = dest;
        }    

        int getSourceFloor(){
            return sourceFloor;
        }

        int getDestFloor(){
            return destFloor;
        }
};

class Elevator
{
    private:
        int id, capacity, currFloor;
        Direction currDirection;
        list<Request*> requests;
    public:
        Elevator(int id, int capacity)
        {
            this->id=id;
            this->capacity=capacity;
            this->currFloor=1;
            this->currDirection = Direction::UP;
        }

        void addRequest(Request* request)
        {
            if(requests.size() < capacity)
            {
                requests.push_back(request);
                cout<<"Request added to Elevator id:"<<id<<endl;
                // notifyAll();
            }
        }

        Request* getNextRequest()
        {
            if(requests.empty()){
                cout<<"Requests are empty!"<<endl;
            }

            Request* request = requests.front();
            requests.erase(requests.begin());
            
            return request;
        }

        void processRequest(Request *request)
        {
            cout<<"Request from src:"<<request->getSourceFloor()<<" to dest:"<<request->getDestFloor()
                <<" is in progress"<<endl;
            
            int startFloor=currFloor;
            int endFloor=request->getDestFloor();

            //Elevator has to go UP
            if(startFloor < endFloor)
            {
                currDirection=Direction::UP;
                for(int i=startFloor;i<=endFloor;i++)
                {
                    currFloor=i;
                    cout<<"Elevator id:"<<id <<" has reached floor:"<<currFloor;
                }
            }
            else if(startFloor > endFloor)
            {
                currDirection=Direction::DOWN;
                for(int i=startFloor;i>=endFloor;i--)
                {
                    currFloor=i;
                    cout<<"Elevator id:"<<id <<" has reached floor:"<<currFloor;
                }
            }
        }

        void processRequests()
        {
            while(true)
            {
                while(!requests.empty()){
                    Request *request = getNextRequest();
                    processRequest(request);
                }
            }
        }

        int getCurrentFloor(){
            return currFloor;
        }

        void run()
        {
            processRequests();
        }
};

class ElevatorController
{
    private:
        list<Elevator*> elevators;
    public:
        ElevatorController(int numElevators, int capacity)
        {
            for(int i=0;i<numElevators;i++)
            {
                Elevator *elevator = new Elevator(i+1, capacity);
                elevators.push_back(elevator);
            }
        }

        Elevator* findOptimalElevator(int src, int dest)
        {
            Elevator* elevator;
            int minDistance=INT_MAX;
            for(auto it: elevators)
            {
                int dist = src-it->getCurrentFloor();
                if(dist < minDistance)
                {
                    minDistance=dist;
                    elevator=it;
                }
            }
            return elevator;
        }

        void requestElevator(int src, int dest)
        {
           Elevator *optimalElevator = findOptimalElevator(src, dest);
           
           Request *request = new Request(src, dest);
           optimalElevator->addRequest(request);
        }
};


int main()
{
    ElevatorController *system = new ElevatorController(3, 5);
    system->requestElevator(5, 10);
    system->requestElevator(3, 7);
    system->requestElevator(8, 2);
    system->requestElevator(1, 9);
    
    //*********************code is incomplete, add threads which are missing*********************

}