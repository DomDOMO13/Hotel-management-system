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
using namespace std;

enum {

  FINDNUM , FINDNAME

};

enum {

  SORTNUM , SORTNAME

};

class Receptionist : public AccountDAO {

private:
  vector<Account*> Acc;

public:

  ~Receptionist() {
    for (auto& account : Acc) {
      delete account;
    }
  }

  void addguest(Account* rAcc){
    auto receptionistAccount = make_unique<ReceptionistAccount>();  
    receptionistAccount->input();
    Acc.push_back(receptionistAccount.release());
  }

  void viewguest() {
    for (const auto& it : Acc) {
      try {
          it->output();
          cout << endl;
      } catch (const std::exception& e) {
          cerr << "Exception: " << e.what() << endl;
      }
    }
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
  }

  void updateGuestinformation (Account* account, ReceptionistAccount* raccount) {
    int choice;
    cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by RoomID" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin>> choice;
        switch (choice)
        {
          case FINDNUM: {
            char performChoice;
            int RoomNumber;
            cout << "Enter account number: ";
            cin >> RoomNumber;
            auto it = find_if(Acc.begin(),Acc.end(),[RoomNumber](const Account* account) { return account->getroom() == RoomNumber; });
            do{
                  if(it != Acc.end()){
                  int choice;
                  cout << "==========EDIT MENU==========" << endl;
                  cout << "1.	Account number" << endl;
                  cout << "2.	Name" << endl;
                  cout << "3.	PhoneNumber" << endl;
                  cout << "4.	Days" << endl;
                  cout << "5. Back" << endl;
                  cout << "Enter choice(1-5)-> ";
                  cin >> choice;
                  switch (choice)
                  {
                    case 1:{
                    int new_room;                    
                    cout << "Enter new account number: ";
                    cin >> new_room;
                    account->setroom(new_room);
                    cout << "Account number changed successfully" << endl;

                    }
                    break;

                    case 2:{
                        string new_name;                    
                        cout << "Enter new name: ";
                        cin >> new_name;    
                      account->setname(new_name);
                      cout << "Name changed successfully" << endl;
                    }
                    break;

                    case 3:{
                      string new_num;                    
                      cout << "Enter new PhoneNumber: ";
                      cin >> new_num;    
                      account->setnum(new_num);
                      cout << "Name changed successfully" << endl;
                    }
                    break;

                    case 4:{
                      int new_days;                    
                      cout << "Enter new name: ";
                      cin >> new_days;    
                      raccount->setdays(new_days);
                      cout << "Name changed successfully" << endl;
                    }
                    break;

                    case 5:
                    break;
                  
                  default:
                  cout << "Invalid Choice. Please try again" << endl;
                      break;
                  }
                  }else {
                      cout << "Account not found" << endl;
                      cout << "Do you want to continue? (y/n) -> ";
                      cin >> performChoice; 
                    }
              }while(performChoice == 'y' || performChoice == 'Y');
              
          }
          break;

            case FINDNAME: {
              char performChoice;
              int RoomNumber;
              cout << "Enter account number: ";
              cin >> RoomNumber;
              auto it = find_if(Acc.begin(),Acc.end(),[RoomNumber](const Account* account) { return account->getroom() == RoomNumber; });
              do{
                    if(it != Acc.end()){
                    int choice;
                    cout << "==========EDIT MENU==========" << endl;
                    cout << "1.	Account number" << endl;
                    cout << "2.	Name" << endl;
                    cout << "3.	PhoneNumber" << endl;
                    cout << "4.	Days" << endl;
                    cout << "5. Back" << endl;
                    cout << "Enter choice(1-5)-> ";
                    cin >> choice;
                    switch (choice)
                    {
                      case 1:{
                      int new_room;                    
                      cout << "Enter new account number: ";
                      cin >> new_room;
                      account->setroom(new_room);
                      cout << "Account number changed successfully" << endl;

                      }
                      break;

                      case 2:{
                          string new_name;                    
                          cout << "Enter new name: ";
                          cin >> new_name;    
                        account->setname(new_name);
                        cout << "Name changed successfully" << endl;
                      }
                      break;

                      case 3:{
                        string new_num;                    
                        cout << "Enter new PhoneNumber: ";
                        cin >> new_num;    
                        account->setnum(new_num);
                        cout << "Name changed successfully" << endl;
                      }
                      break;

                      case 4:{
                        int new_days;                    
                        cout << "Enter new name: ";
                        cin >> new_days;    
                        raccount->setdays(new_days);
                        cout << "Name changed successfully" << endl;
                      }
                      break;

                      case 5:
                      break;
                    
                    default:
                    cout << "Invalid Choice. Please try again" << endl;
                        break;
                    }
                    }else {
                        cout << "Account not found" << endl;
                        cout << "Do you want to continue? (y/n) -> ";
                        cin >> performChoice; 
                    }
                }while(performChoice == 'y' || performChoice == 'Y');
                
            }
            break;
          


          default:
          cout << "Invalid choice." << endl;
          cout << "Press any key to continue...";
          cin.ignore();
          cin.get();
          break;
        }

  }

  void deleteGuestinformation (Account* account, ReceptionistAccount* raccount) {
    int choice;
    cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by RoomID" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin>> choice;
        switch (choice)
        {
          case FINDNUM: {
            char performChoice;
            int RoomNumber;
            cout << "Enter account number: ";
            cin >> RoomNumber;
            auto it = find_if(Acc.begin(),Acc.end(),[RoomNumber](const Account* account) { return account->getroom() == RoomNumber; });

            if(it != Acc.end()){
            cout << "Account information to be deleted:\n";
            account->output();
            cout << "Do you want to delete this account? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
              auto iter = find(Acc.begin(), Acc.end(), account);
              Acc.erase(iter);
              cout << "Account deleted successfully.\n";

            } else {
              cout << "Deletion canceled.\n";

            }
            } else {
              cout << "Bank info not found" << endl;
              cout << "Press any key to continue..." << endl;
              cin.ignore();
              cin.get();
            }

                
          }
          break;
        }
  }
};