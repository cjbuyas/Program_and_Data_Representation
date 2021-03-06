// Charles Buyas, cjb8qf, 2-5-17, postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
//#include "List.h"
using namespace std;


//class ListItr;
//class List;
//class ListNode;


class pfCal {
public:
  pfCal(); // Constructor
  void push(int x); // Adds the passed element to top
  int top(); // Returns the top of the stack
  void pop(); // Removes the value on top of the stack
  bool empty() const; // Tells whether stack is empty
  void add(); // Addition +
  void minus(); // Subtraction -
  void mult(); // Multiplication *
  void div(); // Division /
  void negate(); //Negation ~
  //void addValue(int x);
  int size() const; // Holds the size of the stack
  
private:
  stack<int> myStack;
  //List myList;
  //int count; //number of tokens left
};

#endif

