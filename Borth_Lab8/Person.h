/* -----------------------------------------------------------------------------
 *
 * File Name:  Person.h
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 7 – Min Heap and Max Heap
 * Description:  Patient Class is defined.
 * Date: 3/31/20
 *
 ---------------------------------------------------------------------------- */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
  string firstName, lastName;
  int priority;

public:

/**
* @return the firstName of the Patient.
*/
  string getFirstName() const;

/**
* @return the lastName of the Patient.
*/
  string getLastName() const;

/**
* @return the urgency of the Patient.
*/
  int getPriority() const;

/**
* @param first, last, and symptoms are valid strings, years and rating are valid ints.
* @post construct Patient with all of its characteristics defined.
*/
  Person(string first, string last, int number);

/**
* @post deletes Patient and its characteristicss.
*/
  ~Person();
};

#endif
