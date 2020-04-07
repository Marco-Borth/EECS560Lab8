/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.h
 * Author: Marco Borth
 * Assignment:   EECS 560 Lab 7 – Min Heap and Max Heap
 * Description:  Operator Class is defined.
 * Date: 3/24/20
 *
 ---------------------------------------------------------------------------- */

#ifndef OPERATOR_H
#define OPERATOR_H

#include "Heap.h"
#include "Person.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class Operator
{
private:
  int option;

  string doctersFile, paitientsFile;
  string input;

  Heap <Person*> DoctorNetwork;
  Heap <Person*> PatientNetwork;

  Person* tempDoctor;
  Person* tempPatient;

  ifstream inFile;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/**
* @pre none.
* @post prints list of commands to display for the user.
*/
  void printCommands();

  void MainMenu();

  void printDoctorTerminal();

  void printPatientPortal();

  void PatientManagementSystem();

  void DoctorManagementSystem();

/*
* @pre filename is a string.
* @post Operator object is constructed, file == filename.
*/
  Operator(string file1, string file2);
};
#endif
