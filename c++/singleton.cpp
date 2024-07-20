#include<bits/stdc++.h>
using namespace std;

class Test{
    private:
        static int counter;
    
    public:
    Test(){
        counter++;
    }

    ~Test(){
        counter--;
    }

     static int getCount()
        {
            return counter;
        }
};

// Initialize static member outside the class definition
int Test::counter = 0;

int main()
{
    // Test obj1;  // Create a Test object (not using new)

    // // Using the object
    // cout << "Count before creating another object: " << Test::getCount() << endl;

    // {
    //     Test obj2;  // Creating another Test object
    //     cout << "Count inside inner scope: " << Test::getCount() << endl;
    // } // obj2 goes out of scope and is destroyed

    // cout << "Count after inner scope: " << Test::getCount() << endl;

    // // Dynamic object creation using new
    // Test* obj3 = new Test();
    // cout << "Count after creating dynamic object: " << Test::getCount() << endl;

    // delete obj3;  // Don't forget to delete dynamically allocated memory
    // cout << "Count after deleting dynamic object: " << Test::getCount() << endl;

    // return 0;
    Test *obj1;
    cout<<Test::getCount()<<endl; 

    {Test *obj2;
    cout<<Test::getCount()<<endl;} 


    Test *obj3;
    cout<<Test::getCount()<<endl;
    
    delete obj3;
    cout<<Test::getCount()<<endl;



}