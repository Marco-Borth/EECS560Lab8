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
}

void Operator::MainMenu() {
  cout << "Please choose one of the following commands:\n\n";
  cout << "1- AddGame\n";
  cout << "2- DeleteMaxDownloadedGame\n";
  cout << "3- DeleteGame\n";
  cout << "4- PrintGamesAtMinimumLevels\n";
  cout << "5- PrintGamesAtMaximumLevels\n";
  cout << "6- TotalMinimumDownloadedGames\n";
  cout << "7- TotalMaximumDownloadedGames\n";
  cout << "8- Exit\n\n> ";
  cout << "Enter your choice: ";
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Heap Program!\n\n";

  //Open File.
  inFile.open(file);

  if (!inFile.is_open()) {
    cout << "Games File name not valid!\n\n";
  } else {
    string title, downloads;
    int InputFailures = 0;
    while (!inFile.eof()) {
      inFile >> input;
      title = "";
      downloads = "";

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
              downloads = downloads + input.at(i);
          } else {
            j++;
          }
        }
        //cout << alias << " " << surname << " " << condition << "\n";

        tempGame = new Game(title, stoi(downloads));
        GameCenter.add(tempGame);
      }
    }

    if(InputFailures > 1)
      cout << "ERROR! Invalid Input for Doctor Network Detected: " << InputFailures << "\n";
  }

  inFile.close();
  // Close File.

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
        // 1- AddGame - Complete!
        if (option == 1) {
          string title;
          int downloads;

          cout << "\n>Enter the name of the game you want to insert into the play store:\n";
          cin >> title;
          cout << "\n>Enter the number of downloads for the game in thousands:\n";
          cin >> downloads;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
              cout << "\n>Enter the name of the game you want to insert into the play store:\n";
              cin >> title;
              cout << "\n>Enter the number of downloads for the game in thousands:\n";
              cin >> downloads;
            } else {
              tempGame = new Game(title, downloads);
              GameCenter.add(tempGame);
              cout << "\n\nGame has been insert into the play store.\n\n";

              break;
            }
          }
        }
        // 2. Treat Patient - Complete!
        else if (option == 2) {
          if (!GameCenter.isEmpty()) {
            tempGame = GameCenter.getEntry(0);
            cout << "\n\n" << tempGame->getTitle() << " game with " << tempGame->getPriority() << "K downloads has been deleted successfully.\n\n";
            GameCenter.remove(0);
          } else {
            cout << "\n\n> Output: ERROR! There are no more Games in the play store.\n\n";
          }
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
