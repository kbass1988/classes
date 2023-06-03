/* RPNCalc.h
*  Kalead Bassma
*  CS15M1
*  Header file for RPNCalc
*/


#include <iostream>
#include <ctype.h>
#include <fstream>
#ifndef RPNCALC_H
#include "Datum.h"
#include "datumStack.h"
#include <sstream>
using namespace std;


class RPNCalc{
    public:
    RPNCalc();
    
    ~RPNCalc();
     private:
    //addition
    void add();

    //subtraction
    void sub();
    //multiplication
    void multiply();
    //division
    void div();
    //modulo
    void mod();
    //duplicate
    void dup();
    
    string parseRstring(std::istream &input);    
    
    //comparison operators
    void compare_equal();
   
    void compare_greater();
   
    void compare_less();
   
    void compare_lessOrEqual();
   
    void compare_greaterOrEqual();
   
    

    
    void t();

    void f();
    
    void not_();
    //Operator functions
    void drop();
    
    void swap();

    void clear();

    void print();

    void quit();

    void run();

    void exec();
   
    void file();

    void if_();
    
    
  
    DatumStack entry;
     //helper functions 
    void read_input(std::istream &user_input);
   
    bool int_check(); // prevents crashes

};

#endif
