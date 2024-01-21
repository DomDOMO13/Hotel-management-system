#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Account.cpp"
#include "ReceptionistAccount.cpp"
#include "AccountDAO.cpp"
#include "validation.cpp"
using namespace std;

enum {

  FINDNUM = 1 , FINDNAME

};

enum {

  SORTNUM = 1 , SORTNAME

};

class Receptionist : public AccountDAO {

private:

  vector<ReceptionistAccount*> Acc;

public:

  validation val;

  ~Receptionist() {
    for (auto& account : Acc) {
      delete account;
    }
  }

  void info_edit_menu() {
    cout << "==========EDIT MENU==========" << endl;
    cout << "1.	Roomid" << endl;
    cout << "2.	Name" << endl;
    cout << "3.	Phone number" << endl;
    cout << "4.	Hours" << endl;
    cout << "5. Back" << endl;
  }

  void search_menu() {
    cout << "==========Search MENU==========" << endl;
    cout << "1. Seach by roomid" << endl;
    cout << "2. Seach by name" << endl;
    cout << "3. Back to main menu" << endl;
  }

  void Button_to_Continue() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
  }

  void DotDotDot() {
    for (int i = 0; i < 5; i++) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << endl;
  }

  void output_title() {
    cout << "------------------------------------------------------------------\n";
    cout << "    Roomid           Name           PhoneNumber              Hour \n";
    cout << "------------------------------------------------------------------\n";
  }

  void addguest(Account* account){
    auto receptionistAccount = make_unique<ReceptionistAccount>();
    receptionistAccount->input();
    Acc.push_back(receptionistAccount.release());
  }

  void viewguest() {
    output_title();
    for (const auto& it : Acc) {
      try {
          it->output();
          cout << endl;
      }
      catch (const std::exception& e) {
          cerr << "Exception: " << e.what() << endl;
      }
    }
    Button_to_Continue();
  }

  void updateGuestinformation (Account* account) {
    int choice;
    char ans = 'N';
    search_menu();
    choice = val.getChoice();
    switch (choice) {
    case FINDNUM: {
      int RoomNumber;
      RoomNumber = val.room_input_validation();
      auto it = find_if(Acc.begin(), Acc.end(), [RoomNumber](Account *account) { return account->getroom() == RoomNumber; });
      do {
        if (it != Acc.end()) {
          int choice;
          info_edit_menu();
          choice = val.getChoice();
          switch (choice) {
            case 1: {
              int new_room;
              cout << "Enter new roomid: ";
              cin >> new_room;
              Account *target = (*it);
              target->setroom(new_room);
              cout << "Roomid changed successfully" << endl;
            }
            break;

            case 2: {
              string new_name;
              cout << "Enter new name: ";
              cin >> new_name;
              Account *target = (*it);
              target->setname(new_name);
              cout << "Name changed successfully" << endl;
            }
            break;

            case 3: {
              string new_num;
              cout << "Enter new PhoneNumber: ";
              cin >> new_num;
              Account *target = (*it);
              target->setnum(new_num);
              cout << "Phone number changed successfully" << endl;
            }
            break;

            case 4: {
              int new_days;
              cout << "Enter new hours stay: ";
              cin >> new_days;
              dynamic_cast<ReceptionistAccount *>(*it)->setdays(new_days);
              cout << "Hours changed successfully" << endl;
            }
            break;

            case 5:
              break;

            default:
              cout << "Invalid Choice. Please try again" << endl;
              break;
          }
        }
        else {
          cout << "Guest not found" << endl;
        }
        if (Acc.empty()) {
          cout << "Nothing left to update" << endl;
          Button_to_Continue();
          break;
        }
        cout << "Do you want to continue (Y/N)? ";
        cin >> ans;
      } while ((ans == 'Y') || (ans == 'y'));
    }
    break;

    case FINDNAME:
    {
      string name;
      cout << "Enter name: ";
      cin >> name;
      auto it = find_if(Acc.begin(), Acc.end(), [name](const Account *account) { return account->getname() == name; });
      do {
        if (it != Acc.end()) {
          int choice;
          Account *target = (*it);
          info_edit_menu();
          choice = val.getChoice();
          switch (choice) {
          case 1: {
            int new_room;
            cout << "Enter new Roomid: ";
            cin >> new_room;
            target->setroom(new_room);
            cout << "Roomid changed successfully" << endl;
          }
          break;

          case 2: {
            string new_name;
            cout << "Enter new name: ";
            cin >> new_name;
            target->setname(new_name);
            cout << "Name changed successfully" << endl;
          }
          break;

          case 3: {
            string new_num;
            cout << "Enter new Phone number: ";
            cin >> new_num;
            target->setnum(new_num);
            cout << "Phone number changed successfully" << endl;
          }
          break;

          case 4: {
            int new_days;
            cout << "Enter new hours stay: ";
            cin >> new_days;
            dynamic_cast<ReceptionistAccount *>(*it)->setdays(new_days);
            cout << "hours changed successfully" << endl;
          }
          break;

          case 5:
            break;

          default:
            cout << "Invalid Choice. Please try again" << endl;
            break;
          }
        }

        else
        {
          cout << "Guest not found" << endl;
        }

        if (Acc.empty()) {
          cout << "Nothing left to update" << endl;
          Button_to_Continue();
          break;
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> ans;

      } while ((ans == 'Y') || (ans == 'y'));
    }
    break;

    case 3:
      break;

    default:
      cout << "Invalid choice." << endl;
      cout << "Press any key to continue...";
      cin.ignore();
      cin.get();
      updateGuestinformation(account);
    }
  }

  void deleteGuestinformation (Account* account) {
    int choice;
    char ans = 'N';
    search_menu();
    choice = val.getChoice();
    switch (choice) {
    case FINDNUM: {
      int RoomNumber;
      do {
        RoomNumber = val.room_input_validation();
        auto it = find_if(Acc.begin(), Acc.end(), [RoomNumber](const Account *account) { return account->getroom() == RoomNumber; });
        if (it != Acc.end())
        {
          cout << "Guest information to be deleted:\n";
          Account *target = (*it);
          output_title();
          target->output();
          cout << endl;
          char choice;
          cout << "Do you want to delete this information? (y/n): ";
          cin >> choice;
          if (choice == 'y' || choice == 'Y') {
            Acc.erase(it);
            cout << "Guest information deleted successfully.\n";
          }
          else {
            cout << "Deletion canceled.\n";
          }
        }
        else {
          cout << "Guest info not found" << endl;
        }
        if (Acc.empty()) {
          cout << "Nothing left to delete" << endl;
          Button_to_Continue();
          break;
        }
        cout << "Do you want to continue (Y/N)? ";
        cin >> ans;
      } while ((ans == 'Y') || (ans == 'y'));
    }
    break;

    case FINDNAME: {
      string name;
      do {
        cout << "Enter name: ";
        cin >> name;
        auto it = find_if(Acc.begin(), Acc.end(), [name](const Account *account) { return account->getname() == name; });
        if (it != Acc.end()) {
          cout << "Guest information to be deleted:\n";
          Account *target = (*it);
          output_title();
          target->output();
          cout << "Do you want to delete this information? (y/n): ";
          char choice;
          cin >> choice;
          if (choice == 'y' || choice == 'Y') {
            Acc.erase(it);
            cout << "Guest information deleted successfully.\n";
          }
          else {
            cout << "Deletion canceled.\n";
          }
        }
        else {
          cout << "Guest info not found" << endl;
        }
        if (Acc.empty()) {
          cout << "Nothing left to delete" << endl;
          cout << "Press Enter to continue...";
          cin.ignore();
          cin.get();
          break;
        }
        cout << "Do you want to continue (Y/N)? ";
        cin >> ans;
      } while ((ans == 'Y') || (ans == 'y'));
    }
    break;

    case 3:
      break;

    default:
      cout << "Invalid choice." << endl;
      Button_to_Continue();
      deleteGuestinformation(account);
    }
  }

  void sortGuestinformation() {
    int choice;
    cout << "==========SORT METHOD==========" << endl;
    cout << "1. Sort by Ascending" << endl;
    cout << "2. Sort by Descending" << endl;
    cout << "3. Back to main menu" << endl;
    choice = val.getChoice();
    switch (choice)
    {
    case 1:
      sort(Acc.begin(), Acc.end(), [](const Account *a, const Account *b) { return a->getnum() < b->getnum(); });
      cout << "Sorting";
      DotDotDot();
      cout << "Sorted successfully" << endl;
      Button_to_Continue();
      break;

    case 2:
      sort(Acc.begin(), Acc.end(), [](const Account *a, const Account *b) { return a->getnum() > b->getnum(); });
      cout << "Sorting";
      DotDotDot();
      cout << "Sorted successfully" << endl;
      Button_to_Continue();
      break;

    case 3:
      break;

    default:
      cout << "Invalid choice." << endl;
      Button_to_Continue();
      sortGuestinformation();
    }
  }

  void searchGuestinformation(Account* account){
    int choice;
    char ans = 'N';
    search_menu();
    choice = val.getChoice();
    switch (choice) {
    case FINDNUM: {
      int RoomNumber;
      do {
        RoomNumber = val.room_input_validation();
        auto it = find_if(Acc.begin(), Acc.end(), [RoomNumber](const Account *account) { return account->getroom() == RoomNumber; });
        if (it != Acc.end()) {
          cout << "Roomid found:" << endl;
          output_title();
          Account *target = (*it);
          target->output();
          cout << endl;
        }
        else {
          cout << "Guest info not found" << endl;
        }
        if (Acc.empty()) {
          cout << "Nothing left to search" << endl;
          Button_to_Continue();
          break;
        }
        cout << "Do you want to continue (Y/N)? ";
        cin >> ans;
      } while ((ans == 'Y') || (ans == 'y'));
    }
    break;

    case FINDNAME: {
      string name;
      do {
        cout << "Enter name: ";
        cin >> name;
        auto it = find_if(Acc.begin(), Acc.end(), [name](const Account *account) { return account->getname() == name; });
        if (it != Acc.end()) {
          cout << "Name found:" << endl;
          output_title();
          Account *target = (*it);
          target->output();
          cout << endl;
        }
        else {
          cout << "Guest info not found" << endl;
        }
        if (Acc.empty()) {
          cout << "Nothing left to search" << endl;
          Button_to_Continue();
          break;
        }
        cout << "Do you want to continue (Y/N)? ";
        cin >> ans;
      } while ((ans == 'Y') || (ans == 'y'));
    }
    break;

    case 3:
      break;

    default:
      cout << "Invalid choice." << endl;
      Button_to_Continue();
      searchGuestinformation(account);
    }
  }

  void saveGuestinformation() {
    ofstream outputFile("C:\\Users\\dombu\\Desktop\\Hotel-management-system\\Guest.dat", ios::out |ios::app |ios::binary);
    if (!outputFile.is_open()) {
      cout << "Error in creating file...\n";
      exit(1);
    }
    else {
      for (ReceptionistAccount *Raccount : Acc) {
        Raccount->write(outputFile);
      }
      cout << "File saved successfully" << endl;
    }
    outputFile.close();
  }

  void loadGuestinformation() {
    ifstream inputFile("C:\\Users\\dombu\\Desktop\\Hotel-management-system\\Guest.dat", ios::in|ios::binary);
    if (!inputFile.is_open()) {
        cout << "Error in opening file...\n";
        exit(1);
    }
    Acc.clear();
    while (inputFile) {
      ReceptionistAccount *Raccount = new ReceptionistAccount();
      Raccount->read(inputFile);
      if (inputFile.eof()) {
        delete Raccount;
        break;
      }
      Acc.push_back(Raccount);
    }
    cout << "File loaded successfully" << endl;
    inputFile.close();
  }

};