#include <iostream>
#include <exception>
#include <example.h>
#include <QDebug>
using namespace std;
namespace exampleNamespace //creating a namespace :3
{
    int aNumber(){
        return 19253443;
    }
};

union ExampleUnion{ //unions!
    int i;
    double d;
};

class NewException:public exception{ //programmer defined exception! :)
public:
    const char * what() const throw()
    {
        return "Don't set x to 5\n";
    }
};

class Person{
public:
    virtual int getID();
};

class Staff : virtual public Person{
public:
    Staff(int ID):Person(){
    }
    int getID(){
        return this->ID;
    }
private:
    int ID;
};


class Student : virtual public Person{
public:
    Student(int ID):Person(){
    }
    int getID(){
        return this->ID;
    }
private:
    int ID;
};

class Assistant: public Staff, public Student{ //multiple inheritance!
public:
    Assistant(int ID):Student(ID), Staff(ID){
    }
    int getID(){
        return this->ID;
    }
private:
    int ID;
};

Example::Example(){
    Student Colum = Student(exampleNamespace::aNumber());//callin a namespace!
    Student* ColumPtr = & Colum;
    Assistant* Sam = dynamic_cast<Assistant*>(ColumPtr); //dynamic cast :D !

    ExampleUnion egUnion;
    egUnion.i = 20;

    try{
        int x = 5;
        if (x == 5){
            NewException y;
            throw y;
        }
    } catch(exception& e) {
        qDebug() << e.what();
    }
};



