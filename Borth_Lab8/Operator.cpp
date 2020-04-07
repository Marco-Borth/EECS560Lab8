/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.cpp
 * Author: Marco Borth
 * Assignment:   Lab 8 – Implementation of Maxmin Heap
 * Description:  Operator Class will run the Interactive program for a maxmin Heap.
 * Date: 4/7/20
 *
 ---------------------------------------------------------------------------- */

#include "Operator.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

Operator::Operator(string file1){
  file = file1;
  GameCenter.setPriority("maxmin");
  GameCenter.setApproach("topdown");

  //Open File.
  inFile.open(file);

  if (!inFile.is_open()) {
    cout << "Games File name not valid!\n\n";
  } else {
    string title, memory;
    int InputFailures = 0;
    while (!inFile.eof()) {
      inFile >> input;
      title = "";
      memory = "";

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        InputFailures++;
      } else {
        int j = 0;
        for(int i = 0; i < input.length(); i++) {
          if(input.at(i) != ',') {
            if (j == 0)
              title = title + input.at(i);
            else
              memory = memory + input.at(i);
          } else {
            j++;
          }
        }
        //cout << alias << " " << surname << " " << condition << "\n";

        tempGame = new Game(title, stoi(memory));
        GameCenter.add(tempGame);
      }
    }

    if(InputFailures > 1)
      cout << "ERROR! Invalid Input for Doctor Network Detected: " << InputFailures << "\n";
  }

  inFile.close();
  // Close File.
}

void Operator::MainMenu() {
  cout << "----------------------------------Hospital Patient & Doctor Management System------------------------\n\n";
  cout << "1- AddGame\n";
  cout << "2- DeleteMaxDownloadedGame\n";
  cout << "3- DeleteGame\n";
  cout << "4- PrintGamesAtMinimumLevels\n";
  cout << "5- PrintGamesAtMaximumLevels\n";
  cout << "6- TotalMinimumDownloadedGames\n";
  cout << "7- TotalMaximumDownloadedGames\n";
  cout << "8- Exit\n\n> ";
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Binary Search Tree Program!\n\n";

  do {
    MainMenu();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        MainMenu();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. Patient Management - Complete!
        if (option == 1) {

        }
        // 2. Doctor Assignment - Complete!
        else if (option == 2) {

        }
        // 8- Exit - Complete!
        else if (option == 8) {
          cout << "\nClosing Program...\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while(option != 8);

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}
