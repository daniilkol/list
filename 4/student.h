#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 20
class student
{
private:
    char*name;
    int value;
public:
    student(const char*in=0,int iv=0);
    student(const student&i);
    ~student();
    student& operator=(const student&rhs);
    int get_value()const{return value;}
     const char* get_name()const {return (const char*)name;}
    int operator<(const student&b)const;
    void swaps(student&b);
    int init(const char*in=0,int iv=0);
};

void printarray(student*a,int n);
int readarray(const char*name,student*a,int n);
