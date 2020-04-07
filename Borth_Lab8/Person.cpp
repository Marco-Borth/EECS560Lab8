/* -----------------------------------------------------------------------------
 *
 * File Name:  Person.cpp
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 7 – Min Heap and Max Heap
 * Description:  Patient Class will return the Patient information.
 * Date: 3/31/20
 *
 ---------------------------------------------------------------------------- */

#include "Person.h"

Person::Person(string first, string last, int number) {
  firstName = first;
  lastName = last;
  priority = number;
}

Person::~Person(){}

string Person::getFirstName() const {
  return firstName;
}

string Person::getLastName() const {
  return lastName;
}

int Person::getPriority() const {
  return priority;
}
