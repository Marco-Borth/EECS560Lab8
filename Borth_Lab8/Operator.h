/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.h
 * Author: Marco Borth
 * Assignment:   Lab 8 – Implementation of Maxmin Heap
 * Description:  Operator Class is defined.
 * Date: 3/24/20
 *
 ---------------------------------------------------------------------------- */

#ifndef OPERATOR_H
#define OPERATOR_H

#include "Heap.h"
#include "Game.h"
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

  string file;
  string input;

  Heap <Game*> GameCenter;

  Game* tempGame;

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

/*
* @pre filename is a string.
* @post Operator object is constructed, file == filename.
*/
  Operator(string file1);
};
#endif
