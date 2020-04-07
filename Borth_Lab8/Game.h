/* -----------------------------------------------------------------------------
 *
 * File Name:  Game.h
 * Author: Marco Borth
 * Assignment:   Lab 8 – Implementation of Maxmin Heap
 * Description:  Game Class is defined.
 * Date: 4/7/20
 *
 ---------------------------------------------------------------------------- */

#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
using namespace std;

class Game
{
private:
  string title;
  int priority;

public:

/**
* @return the firstName of the Patient.
*/
  string getTitle() const;

/**
* @return the urgency of the Patient.
*/
  int getPriority() const;

/**
* @param first, last, and symptoms are valid strings, years and rating are valid ints.
* @post construct Patient with all of its characteristics defined.
*/
  Game(string name, int number);

/**
* @post deletes Patient and its characteristicss.
*/
  ~Game();
};

#endif
