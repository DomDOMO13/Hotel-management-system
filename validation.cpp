#pragma once
#include<iostream>
#include <string>
#include "BadInputException.cpp"
class validation
{
  private:
    const int maxchar = 12;
    bool boolean;

    bool validate_room(int num) {
      if (cin.fail() || num > 200) {
        return false;
      }
      return true;
    }

    bool validate_name(string name) {
      if (name.length() > 10) {
        return false;
      }
      for(int i = 0;i<name.length();i++){
        if(!(name[i] >= 65 && name[i] <= 122)) {
          return false;
        }
      }
      return true;
    }

    bool validate_num(string num) {
      if (num.length() > 10) {
        return false;
      }
      return true;
    }

  public:

    bool length_check (std::string input) {
      return boolean = input.length() < maxchar;
    };

    void setlength_check(const bool boolean) {
        if(boolean != 1 || boolean != 0) {
            this->boolean = boolean;
        }
        else {
            throw BadInputException();
        }
    }
    
    bool getlength_check() const {
      return boolean;
    }

    int input_room() {
      int room;
        while (true)
        {
          cout << "Enter RoomID: ";
          cin >> room;
          if (!validate_room(room)) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Error: Invalid Input" << endl;
          }
          else {
            return room;
          }
        }
    }

    string input_name() {
      string name;
      while (true)
      {
        cout << "Enter Name: ";
        cin >> name;
        if (!validate_name(name)) {
          cout << "Error: Invalid/max letter reached" << endl;
        }
        else {
          return name;
        }
      }
    }

    string input_num() {
      string num;
      while (true) {
        cout << "Enter Phone Number: ";
        cin >> num;
        if (!validate_num(num)) {
          cout << "Error: Invalid Input" << endl;
        }
        else {
          return num;
        }
      }
    }

    int input_day() {
      int day;
      while (true) {
        cout << "Enter hour check-ins: ";
        cin >> day;
        if (!validate_room(day)) {     
          cin.clear();
          cin.ignore(200, '\n');
          cout << "Error: Invalid Input" << endl;
          }
        else {
            return day;
        }
      }
    }

    int room_input_validation() {
      int RoomNumber;
      bool valid = false;
      do {
        cout << "Enter a Roomid: " << flush;
        cin >> RoomNumber;
        if (cin.good()) {
          valid = true;
        }
        else {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input! please re-enter." << endl;
        }
      } while (!valid);
      return RoomNumber;
    }

    int getChoice() {
      int choice;
      bool valid = false;
      do {
        cout << "Enter a number: " << flush;
        cin >> choice;
        if (cin.good()) {
          valid = true;
        }
        else {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input! please re-enter." << endl;
        }
      } while (!valid);
      return choice;
    }

};