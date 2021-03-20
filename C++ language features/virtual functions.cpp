#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Solution:
// First Class has virtual functions getdata() and putdata()
class Person {
    // make protected instead of private so derived classes can access these variables
    protected:
        string name;
        int age;
        
    public:
        // used to generate cur_ID for new Person objects
        // Constructor using member initialization list
        Person() {
            name = "";
            age = 0;
        }
        
        // These virtual methods will be overriden by Professor and Student
        virtual void getdata() {
            cin >> name >> age;
        };
        virtual void putdata() {
            cout << name << " " << age << '\n';
        };
};

// Professor is derived from Person
class Professor : public Person {
    private:
        int publications;
        int cur_id;
        static int id; // static int used to get ids per instance
        // each Professor has an id starting from 1
    public:
        Professor() {
            cur_id = ++id;
        }
        
        void getdata() {
            //get user input (name, age, publications) from user
            cin >> name >> age >> publications;
        }
        void putdata() {
            // print space-separated name, age, publications, and cur_id
            cout << name << " " << age << " " << publications << " " << cur_id << '\n';
        }
};
// Must initialize static member variables outside of class
int Professor::id = 0;


class Student : public Person {
    private:
        int marks[6];
        int cur_id;
        static int id; // each student has an id starting from 1
    public:
        Student() {
            cur_id = ++id;
        } 

        int sumMarks() {
            int sum = 0;
            for(int i = 0; i < 6; i++) {
                sum += marks[i];
            }
            return sum;
        }
        void getdata() {
            // get user input (name, age, marks of student in 6 subjects)
            cin >> name >> age;
            for(int i = 0; i < 6; i++) {
                cin >> marks[i];
            }
        }
        void putdata() {
            // print space-separated name, age, and sum of marks, cur_id
            cout << name << " " << age << " " << sumMarks() << " " << cur_id <<'\n';
        }
};
// Must initialize static member variables outside of class
int Student::id = 0;

// From HackerRank
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}