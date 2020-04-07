/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 6 – Implementation of Binary Search Trees
 * Description:  Operator Class will run the Interactive program for a Binary Search Tree.
 * Date: 3/12/20
 *
 ---------------------------------------------------------------------------- */

#include "Operator.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

Operator::Operator(string file1, string file2){
  doctersFile = file1;
  DoctorNetwork.setKary(3);
  DoctorNetwork.setPriority("min");
  paitientsFile = file2;
  PatientNetwork.setKary(3);
  PatientNetwork.setPriority("max");

  //Open File.
  inFile.open(doctersFile);

  if (!inFile.is_open()) {
    cout << "Doctors Network File name not valid!\n\n";
  } else {
    string alias, surname, patients;
    int InputFailures = 0;
    while (!inFile.eof()) {
      inFile >> input;
      alias = "";
      surname = "";
      patients = "";

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        InputFailures++;
      } else {
        int j = 0;
        for(int i = 0; i < input.length(); i++) {
          if(input.at(i) != ',') {
            if(j == 0)
              alias = alias + input.at(i);
            else if (j == 1)
              surname = surname + input.at(i);
            else
              patients = patients + input.at(i);
          } else {
            j++;
          }
        }
        //cout << alias << " " << surname << " " << condition << "\n";

        tempDoctor = new Person(alias, surname, stoi(patients));
        DoctorNetwork.add(tempDoctor);
      }
    }

    if(InputFailures > 1)
      cout << "ERROR! Invalid Input for Doctor Network Detected: " << InputFailures << "\n";
  }

  inFile.close();
  // Close File.
  DoctorNetwork.bottomUpHeapify();

  //Open File.
  inFile.open(paitientsFile);

  if (!inFile.is_open()) {
    cout << "Patients Queue File name not valid!\n\n";
  } else {
    string alias, surname, condition;
    int InputFailures = 0;
    while (!inFile.eof()) {
      inFile >> input;
      alias = "";
      surname = "";
      condition = "";

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        InputFailures++;
      } else {
        int j = 0;
        for(int i = 0; i < input.length(); i++) {
          if(input.at(i) != ',') {
            if(j == 0)
              alias = alias + input.at(i);
            else if (j == 1)
              surname = surname + input.at(i);
            else
              condition = condition + input.at(i);
          } else {
            j++;
          }
        }
        //cout << alias << " " << surname << " " << condition << "\n";

        tempPatient = new Person(alias, surname, stoi(condition));
        PatientNetwork.add(tempPatient);
      }
    }

    if(InputFailures > 1)
      cout << "ERROR! Invalid Input for Doctor Network Detected: " << InputFailures << "\n";
  }

  inFile.close();
  // Close File.
  PatientNetwork.bottomUpHeapify();
}

void Operator::MainMenu() {
  cout << "----------------------------------Hospital Patient & Doctor Management System------------------------\n\n";
  cout << "1. Patient Management\n";
  cout << "2. Doctor Assignment\n";
  cout << "3. Exit\n\n> ";
}

void Operator::printDoctorTerminal() {
  cout << "---------------------------------------------Doctor Assignment System-----------------------------------------\n\n";
  cout << "1.  New Doctor\n";
  cout << "2.  Update Patients\n";
  cout << "3.  Remove Doctor\n";
  cout << "4.  Next Available Doctor\n";
  cout << "5.  Check Availability\n";
  cout << "6.  Total Doctor Count\n";
  cout << "7.  Available Doctor Count\n";
  cout << "8.  Available Doctors Report\n";
  cout << "9.  Busy Doctors List\n";
  cout << "10. Go Back to Menu\n\n> ";
}

void Operator::printPatientPortal() {
  cout << "---------------------------------------------Patient Management System--------------------------------------\n\n";
  cout << "1. New Patient\n";
  cout << "2. Treat Patient\n";
  cout << "3. Change Urgency\n";
  cout << "4. Next Patient\n";
  cout << "5. Last Patient\n";
  cout << "6. Patient Token\n";
  cout << "7. Patients Count\n";
  cout << "8. Patients Report\n";
  cout << "9. Go Back to Menu\n\n> ";
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
          PatientManagementSystem();
        }
        // 2. Doctor Assignment - Complete!
        else if (option == 2) {
          DoctorManagementSystem();
        }
        // 3. Exit - Complete!
        else if (option == 3) {
          cout << "\nClosing Program...\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while(option != 3);

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}

void Operator::PatientManagementSystem() {
  do {
    printPatientPortal();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        printPatientPortal();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. New Patient - Complete!
        if (option == 1) {
          string alias, surname;
          int condition;

          cout << "\nEnter New Patient's ID and their urgency rating:\n";
          cout << "\nFirst Name: ";
          cin >> alias;
          cout << "\nLast Name: ";
          cin >> surname;
          cout << "\nUrgency Rating: ";
          cin >> condition;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
              cout << "\nCheck the input for New Patient's ID and Urgency Rating:\n";
              cout << "\nFirst Name: ";
              cin >> alias;
              cout << "\nLast Name: ";
              cin >> surname;
              cout << "\nUrgency Rating: ";
              cin >> condition;
            } else {
              bool notADuplicate = true;

              for (int i = 0; i < PatientNetwork.getSize(); i++) {
                if ( PatientNetwork.getEntry(i)->getFirstName() == alias &&
                    PatientNetwork.getEntry(i)->getLastName() == surname &&
                    PatientNetwork.getEntry(i)->getPriority() == condition ) {
                      notADuplicate = false;
                }
              }

              if (notADuplicate) {
                tempPatient = new Person(alias, surname, condition);
                PatientNetwork.add(tempPatient);
                PatientNetwork.bottomUpHeapify();
              } else {
                cout << "\nERROR! Duplicate Entry Already Exists.\n\n";
              }

              cout << "\n\n";
              break;
            }
          }

        }
        // 2. Treat Patient - Complete!
        else if (option == 2) {
          try {
            tempPatient = PatientNetwork.getEntry(0);
            cout << "\nTreating the most urgent Paitent...\n";

            cout << "\nMost urgent Patient listed:";
            cout << "\nFirst Name: " << tempPatient->getFirstName();
            cout << "\nLast Name: " << tempPatient->getLastName();
            cout << "\nUrgency Rating: " << tempPatient->getPriority();


            PatientNetwork.remove(0);

            cout << "\n\nPatient has been treated.\n\n";
            delete tempPatient;
          } catch (runtime_error) {
            cout << "\n\n> Output: ERROR! There are no more Paitents in the Hospital Queue.\n\n";
          }
        }
        // 3. Change Urgency - Complete!
        else if (option == 3) {
          if (!PatientNetwork.isEmpty()) {
            string alias, surname;
            int condition;

            cout << "Enter Patient's ID:\n";
            cout << "\nFirst Name: ";
            cin >> alias;
            cout << "\nLast Name: ";
            cin >> surname;

            bool recordFound = false;
            int index = 0;

            for (int i = 0; i < PatientNetwork.getSize(); i++) {
              if ( PatientNetwork.getEntry(i)->getFirstName() == alias &&
                  PatientNetwork.getEntry(i)->getLastName() == surname ) {
                    recordFound = true;
                    index = i;
              }
            }

            if (recordFound) {
              cout << "\n\nCurrent Patient listed:";
              cout << "\nFirst Name: " << PatientNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << PatientNetwork.getEntry(index)->getLastName();
              cout << "\nUrgency Rating: " << PatientNetwork.getEntry(index)->getPriority();

              cout << "\n\nEnter new Urgency Rating: ";
              cin >> condition;

              while(1) {
                if(cin.fail()) {
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(),'\n');
                  cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
                  cout << "\nEnter new Urgency Rating: ";
                  cin >> condition;
                } else {
                  PatientNetwork.remove(index);
                  tempPatient = new Person(alias, surname, condition);
                  PatientNetwork.add(tempPatient);
                  PatientNetwork.bottomUpHeapify();

                  cout << "\n\nPatient Record has been updated.\n\n";

                  break;
                }
              }
            } else {
              cout << "\n\nEntry not Found!\n\n";
            }
          } else {
            cout << "\n\n> Output: ERROR! There are no more Paitents in the Hospital Queue.\n\n";
          }
        }
        // 4. Next Patient - Complete!
        else if (option == 4) {
          if (!PatientNetwork.isEmpty()) {
            if (PatientNetwork.getSize() == 1) {
              cout << "\nThere is only the current patient listed:\n\n";
              cout << "\nFirst Name: " << PatientNetwork.getEntry(0)->getFirstName();
              cout << "\nLast Name: " << PatientNetwork.getEntry(0)->getLastName();
              cout << "\nUrgency Rating: " << PatientNetwork.getEntry(0)->getPriority();
            } else  {
              int index = 1;
              if (PatientNetwork.getSize() == 2) {
                index = 1;
              } else if (PatientNetwork.getSize() == 3) {
                if(PatientNetwork.getEntry(1)->getPriority() < PatientNetwork.getEntry(2)->getPriority()) {
                  index = 2;
                }
              } else {
                for (int i = 2; i <= 3; i++) {
        					if (PatientNetwork.getEntry(index)->getPriority() < PatientNetwork.getEntry(i)->getPriority()) {
        						index = i;
        					}
          			}
              }
              cout << "\nNext Patient listed:\n\n";
              cout << "\nFirst Name: " << PatientNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << PatientNetwork.getEntry(index)->getLastName();
              cout << "\nUrgency Rating: " << PatientNetwork.getEntry(index)->getPriority();
            }
            cout << "\n\n";
          } else {
            cout << "\n> Output: ERROR! There are no more Paitents in the Hospital Queue.\n\n";
          }
        }
        // 5. Last Patient - Complete!
        else if (option == 5) {
          if (!PatientNetwork.isEmpty()) {
            if (PatientNetwork.getSize() == 1) {
              cout << "\nThere is only the current patient listed:\n\n";
              cout << "\nFirst Name: " << PatientNetwork.getEntry(0)->getFirstName();
              cout << "\nLast Name: " << PatientNetwork.getEntry(0)->getLastName();
              cout << "\nUrgency Rating: " << PatientNetwork.getEntry(0)->getPriority();
            } else  {
              int index = 0;
              for (int i = 0; i < PatientNetwork.getSize(); i++) {
                if (PatientNetwork.getEntry(index)->getPriority() > PatientNetwork.getEntry(i)->getPriority()) {
                  index = i;
                }
              }
              cout << "\nLast Patient listed:\n\n";
              cout << "\nFirst Name: " << PatientNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << PatientNetwork.getEntry(index)->getLastName();
              cout << "\nUrgency Rating: " << PatientNetwork.getEntry(index)->getPriority();
            }
            cout << "\n\n";
          } else {
            cout << "\n> Output: ERROR! There are no more Paitents in the Hospital Queue.\n\n";
          }
        }
        // 6. Patient Token - Complete!
        else if (option == 6) {
          if (!PatientNetwork.isEmpty()) {
            string alias, surname;

            cout << "Enter Patient's ID:\n";
            cout << "\nFirst Name: ";
            cin >> alias;
            cout << "\nLast Name: ";
            cin >> surname;

            bool recordFound = false;
            int index = 0;

            for (int i = 0; i < PatientNetwork.getSize(); i++) {
              if ( PatientNetwork.getEntry(i)->getFirstName() == alias &&
                  PatientNetwork.getEntry(i)->getLastName() == surname ) {
                    recordFound = true;
                    index = i;
              }
            }

            if (recordFound) {
              cout << "\n\nCurrent Patient listed:";
              cout << "\nFirst Name: " << PatientNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << PatientNetwork.getEntry(index)->getLastName();
              cout << "\nPriority in Queue: ";
              index++;
              if (index % 10 == 1)
                cout << index << "st priority\n\n";
              else if (index % 10 == 2)
                cout << index << "nd priority\n\n";
              else if (index % 10 == 3)
                cout << index << "rd priority\n\n";
              else
                cout << index << "th priority\n\n";
            } else {
              cout << "\n\nEntry not Found!\n\n";
            }
          } else {
            cout << "\n\n> Output: ERROR! There are no more Paitents in the Hospital Queue.\n\n";
          }
        }
        // 7. Patient Count - Complete!
        else if (option == 7) {
          cout << "\nCurrent Patient count is: " << PatientNetwork.getSize() << "\n\n";
        }
        // 8. Patient Report - Complete!
        else if (option == 8) {
          cout << "\nCurrent Patients Report: ";
          for (int i = 0; i < PatientNetwork.getSize(); i++) {
            cout << "\n" << PatientNetwork.getEntry(i)->getFirstName();
            cout << ", " << PatientNetwork.getEntry(i)->getLastName();
            cout << ", " << PatientNetwork.getEntry(i)->getPriority();
          }
          cout << "\n\n";
        }
        // 9. Exit - Complete!
        else if (option == 9) {
          cout << "\nExiting Patient Management System...\n\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while (option != 9);
}

void Operator::DoctorManagementSystem() {
  do {
    printDoctorTerminal();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        printDoctorTerminal();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. New Doctor - Complete!
        if (option == 1) {
          string alias, surname;

          cout << "\nEnter New Doctor's ID:\n";
          cout << "\nFirst Name: ";
          cin >> alias;
          cout << "\nLast Name: ";
          cin >> surname;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
              cout << "\nCheck the input for New Doctor's ID:\n";
              cout << "\nFirst Name: ";
              cin >> alias;
              cout << "\nLast Name: ";
              cin >> surname;
            } else {
              bool notADuplicate = true;

              for (int i = 0; i < DoctorNetwork.getSize(); i++) {
                if ( DoctorNetwork.getEntry(i)->getFirstName() == alias &&
                    DoctorNetwork.getEntry(i)->getLastName() == surname) {
                      notADuplicate = false;
                }
              }

              if (notADuplicate) {
                tempDoctor = new Person(alias, surname, 0);
                DoctorNetwork.add(tempDoctor);
                DoctorNetwork.bottomUpHeapify();
              } else {
                cout << "\nERROR! Duplicate Entry Already Exists.\n\n";
              }

              cout << "\n\n";
              break;
            }
          }

        }
        // 2. Update Patients - Complete!
        else if (option == 2) {
          if (!DoctorNetwork.isEmpty()) {
            string alias, surname;
            int patients;

            cout << "Enter Doctor's ID for their Number of Patients Assigned to be updated:\n";
            cout << "\nFirst Name: ";
            cin >> alias;
            cout << "\nLast Name: ";
            cin >> surname;

            bool recordFound = false;
            int index = 0;

            for (int i = 0; i < DoctorNetwork.getSize(); i++) {
              if ( DoctorNetwork.getEntry(i)->getFirstName() == alias &&
                  DoctorNetwork.getEntry(i)->getLastName() == surname ) {
                    recordFound = true;
                    index = i;
              }
            }

            if (recordFound) {
              int increment, direction;
              cout << "\n\nCurrent Patient listed:";
              cout << "\nFirst Name: " << DoctorNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << DoctorNetwork.getEntry(index)->getLastName();
              cout << "\nNumber of Patients Assigned: " << DoctorNetwork.getEntry(index)->getPriority();

              cout << "\n\nSelect 1 to add patients or 0 to reduce patients: ";
              cin >> direction;

              while(1) {
                if (direction != 1 && direction != 0) {
                  cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
                  cout << "Select 1 to add patients or 0 to reduce patients: ";
                  cin >> direction;
                } else {
                  break;
                }
              }

              cout << "\n\n>Enter the updated count: ";
              cin >> increment;

              while(1) {
                if(cin.fail()) {
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(),'\n');
                  cout << "\nERROR! Invalid Input!\n\n"; //if not an int, must try again.
                  cout << "\nEnter the updated count: ";
                  cin >> increment;
                } else {
                  if (direction == 1) {
                    patients = DoctorNetwork.getEntry(index)->getPriority() + increment;
                  } else {
                    patients = DoctorNetwork.getEntry(index)->getPriority() - increment;
                  }

                  if (patients < 0) {
                    patients = 0;
                  } else if (patients > 25) {
                    patients = 25;
                  }

                  DoctorNetwork.remove(index);
                  tempDoctor = new Person(alias, surname, patients);
                  DoctorNetwork.add(tempDoctor);
                  DoctorNetwork.bottomUpHeapify();

                  cout << "\n\nDoctor Record has been updated.\n\n";

                  break;
                }
              }
            } else {
              cout << "\n\nEntry not Found!\n\n";
            }
          } else {
            cout << "\n\n> Output: ERROR! There are no more Doctors in the Hospital.\n\n";
          }
        }
        // 3. Remove Doctor - Complete!
        else if (option == 3) {
          try {
            tempDoctor = DoctorNetwork.getEntry(0);
            cout << "\nRemoving Doctor with the lowest Number of Assigned Patients from the network...\n";

            cout << "\nDocter listed:";
            cout << "\nFirst Name: " << tempDoctor->getFirstName();
            cout << "\nLast Name: " << tempDoctor->getLastName();
            cout << "\nNumber of Patients Assigned: " << tempDoctor->getPriority();

            DoctorNetwork.remove(0);

            cout << "\n\nDoctor has been remove from the network.\n\n";
            delete tempDoctor;
          } catch (runtime_error) {
            cout << "\n\n> Output: ERROR! There are no more Doctors in the Hospital.\n\n";
          }
        }
        // 4. Next Available Doctor - Complete!
        else if (option == 4) {
          if (!DoctorNetwork.isEmpty()) {
            if (DoctorNetwork.getSize() == 1) {
              cout << "\nThere is only the current Doctor Available:\n\n";
              cout << "\nFirst Name: " << DoctorNetwork.getEntry(0)->getFirstName();
              cout << "\nLast Name: " << DoctorNetwork.getEntry(0)->getLastName();
              cout << "\nNumber of Patients Assigned: " << DoctorNetwork.getEntry(0)->getPriority();
            } else  {
              int index = 1;
              if (PatientNetwork.getSize() == 2) {
                index = 1;
              } else if (PatientNetwork.getSize() == 3) {
                if(DoctorNetwork.getEntry(1)->getPriority() > DoctorNetwork.getEntry(2)->getPriority()) {
                  index = 2;
                }
              } else {
                for (int i = 2; i <= 3; i++) {
        					if (DoctorNetwork.getEntry(index)->getPriority() > DoctorNetwork.getEntry(i)->getPriority()) {
        						index = i;
        					}
          			}
              }
              cout << "\nNext Doctor Available:\n\n";
              cout << "\nFirst Name: " << DoctorNetwork.getEntry(index)->getFirstName();
              cout << "\nLast Name: " << DoctorNetwork.getEntry(index)->getLastName();
              cout << "\nNumber of Patients Assigned: " << DoctorNetwork.getEntry(index)->getPriority();
            }
            cout << "\n\n";
          } else {
            cout << "\n> Output: ERROR! There are no more Doctors in the Hospital.\n\n";
          }
        }
        // 5. Check Availability - Complete!
        else if (option == 5) {
          if (!DoctorNetwork.isEmpty()) {
            string alias, surname;

            cout << "Enter Doctor's ID for their Number of Patients Assigned to be updated:\n";
            cout << "\nFirst Name: ";
            cin >> alias;
            cout << "\nLast Name: ";
            cin >> surname;

            bool recordFound = false;
            int index = 0;

            for (int i = 0; i < DoctorNetwork.getSize(); i++) {
              if ( DoctorNetwork.getEntry(i)->getFirstName() == alias &&
                  DoctorNetwork.getEntry(i)->getLastName() == surname ) {
                    recordFound = true;
                    index = i;
                    if (DoctorNetwork.getEntry(i)->getPriority() < 22) {
                      cout << "\n\nThis doctor is available.\n\n";
                    } else {
                      cout << "\n\nThis doctor is NOT available.\n\n";
                    }
              }
            }

            if (!recordFound) {
              cout << "\n\nRecord not Found!\n\n";
            }
          } else {
            cout << "\n\n> Output: ERROR! There are no more Doctors in the Hospital.\n\n";
          }
        }
        // 6. Total Doctor Count - Complete!
        else if (option == 6) {
          cout << "\nTotal Doctor count is: " << DoctorNetwork.getSize() << "\n\n";
        }
        // 7. Available Doctor Count - Complete!
        else if (option == 7) {
          int count = 0;
          for (int i = 0; i < DoctorNetwork.getSize(); i++) {
            if (DoctorNetwork.getEntry(i)->getPriority() < 22) {
              count++;
            }
          }
          cout << "\nAvailable Doctor count is: " << count << "\n\n";
        }
        // 8. Available Doctors Report - Complete!
        else if (option == 8) {
          if (!DoctorNetwork.isEmpty()) {
            cout << "\nAvailable Doctors Report: ";
            for (int i = 0; i < DoctorNetwork.getSize(); i++) {
              if (DoctorNetwork.getEntry(i)->getPriority() < 22) {
                cout << "\n" << DoctorNetwork.getEntry(i)->getFirstName();
                cout << ", " << DoctorNetwork.getEntry(i)->getLastName();
                cout << ", " << DoctorNetwork.getEntry(i)->getPriority();
              }
            }
            cout << "\n\n";
          } else {
            cout << "\n> Output: ERROR! There are no more Doctors in the Hospital.\n\n";
          }
        }
        // 9. Busy Doctors List - Complete!
        else if (option == 9) {
          if (!DoctorNetwork.isEmpty()) {
            cout << "\nBusy Doctors List: ";
            for (int i = 0; i < DoctorNetwork.getSize(); i++) {
              if (DoctorNetwork.getEntry(i)->getPriority() >= 22) {
                cout << "\n" << DoctorNetwork.getEntry(i)->getFirstName();
                cout << ", " << DoctorNetwork.getEntry(i)->getLastName();
                cout << ", " << DoctorNetwork.getEntry(i)->getPriority();
              }
            }
            cout << "\n\n";
          } else {
            cout << "\n> Output: ERROR! There are no more Doctors in the Hospital.\n\n";
          }
        }
        // 10. Exit - Complete!
        else if (option == 10) {
          cout << "\nExiting Doctor Management System...\n\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while (option != 10);
}
