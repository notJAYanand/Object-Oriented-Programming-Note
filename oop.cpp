#include<bits/stdc++.h>
using namespace std;

/*
4 Pillars of OOP:-

1 Encapsulation- Bundling of data-> prevent direct modification by other class entities.
2 Abstraction- Beautification purposes-> hiding complexity of code->simulate behiavour of interface in JAVA or C# in C++ using abstract class
3 Inheritance- base class->super,parent,derived class-> sub,child --> 
4 Polymorphism- greek lang-> poly morph-> many forms, used parent class reference is used to refer an object of child class

*/


//camera app user use //story here
class AbstractEmployee //contract
{
    virtual void askForPromotion()=0; // abstract function using virtual keyword
};

//code behind camera
class Employee:AbstractEmployee //signed contract
{
    // private:  //default
    // protected:   
    private:
        
        string Company;  //Encapsulated
        int Age;
    protected:
        string Name; // accessible by derived classes
    public:
    //Accessing encapsulated parameters using methods
        void setName(string name)
        {
            Name=name;
        }
        string getName(){
            return Name;
        }
        void setCompany(string company)
        {
            Company=company;
        }
        string getCompany(){
            return Company;
        }
        void setAge(int age)
        {
            // if(age>=18)
                Age=age;//check get age only if >=18
        }
        int getAge(){
            return Age;
        }
        virtual void Work()
        {
            cout<<Name<<" is checking mail, backlogs"<<endl;
        }


        void introduceYourself() //Class Method this shows behiavour
        {
            cout<<"Name : "<<Name<<endl;
            cout<<"company : "<<Company<<endl;
            cout<<"age : "<<Age<<endl;
        }
        //Constructor is a special method each time a new object is created.
        //3 rules to make a constructor
        //1. no return type
        //2. name same as class name
        //3 ALWAYS PUBLIC
        Employee(string name,string company,int age) // parametrized constructor
        {
            Name=name;
            Company=company;
            Age=age;
        }
        void askForPromotion()
        {
            //any employee >33 age can get promotion
            if(Age>30)
            {
                cout<<Name<<" "<<"Promoted"<<endl;
            }
            else
            {
                cout<<Name<<" "<<"NOT Promoted"<<" Try again in "<<33-Age<<" Year(s)"<<endl;
            }
        }

}; //blueprint
//INHERITANCE

class Developer: public Employee // class child: parent class{}
{
    public:
        string FavProgrammingLanguage;
        Developer(string name,string company,int age,string lang):Employee(name,company,age)
        {
            // baaki ka fikar karne ka zaroorat nhi             upar dekho

            FavProgrammingLanguage=lang;
        }
        void fixBug()
        {
            cout<<"FIXED by "<<Name<<" using "<<FavProgrammingLanguage<<endl;
        }
        void Work()
        {
            cout<<Name<<" is writing code "<<FavProgrammingLanguage<<endl;
        }        

};

class Teacher: public Employee
{
    public:
        string Subject;
        void prepareLesson()
        {
            cout<<Name<<" is preparing "<<Subject<<" lesson "<<endl;
        }
        Teacher(string name,string company,int age,string subject):Employee(name,company,age)
        {
                Subject=subject;
        }
        void Work()
        {
            cout<<Name<<" is teaching "<<Subject<<endl;
        }        
};

int main()
{
    //instance banayenge ab
    // Employee employee1=Employee("jay","kiit",21); //object of type Employee
    // // employee1.name = "jay";
    // // employee1.company="kiit";  //kaam ho gay7a easy
    // // employee1.age =21;
    // employee1.setAge(16);
    // // cout<<employee1.getName()<<" is "<<employee1.getAge()<< "years old"<<endl;
    // // employee1.introduceYourself();
    
    // Employee employee2=Employee("John","amazon",55); //object of type Employee
    // we'll be fucked if we have to do like this for 500 employees.
    // we'll be fucked anyways , but to make it a little less painful, we will use an oil named constructor 
    
    // employee1.askForPromotion();
    // employee2.askForPromotion();

    Developer d= Developer("jay","kiit",21,"C++");

    // d.fixBug();
    // d.askForPromotion();
    Teacher t=Teacher("jack","sch",12,"Maths");
    // t.prepareLesson();
    // t.askForPromotion();

    // d.Work();
    // t.Work();

    Employee *e1=&d; //rule
    Employee *e2=&t;

    e1->Work();
    e2->Work(); //we have to make Work() virtual in order for it to work
                // virtual function essentially in this case checks if there is the same function is defined in derived classes and exe that
    // before using virtual O/P
    /*
    jay is checking mail, backlogs
    jack is checking mail, backlogs
    */
   //After O/P
    /*
    jay is writing code C++
    jack is teaching Maths  
   */

}