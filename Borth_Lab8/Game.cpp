/* -----------------------------------------------------------------------------
 *
 * File Name:  Game.cpp
 * Author: Marco Borth
 * Assignment:   Lab 8 – Implementation of Maxmin Heap
 * Description:  Game Class will return the Game information.
 * Date: 4/7/20
 *
 ---------------------------------------------------------------------------- */

#include "Game.h"

Game::Game(string name, int number) {
  title = name;
  priority = number;
}

Game::~Game(){}

string Game::getTitle() const {
  return title;
}

int Game::getPriority() const {
  return priority;
}
