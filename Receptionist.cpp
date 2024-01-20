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
  vector<Account*> Acc;

public:

  validation val;

  ~Receptionist() {
    for (auto& account : Acc) {
      delete account;
    }
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
      } catch (const std::exception& e) {
          cerr << "Exception: " << e.what() << endl;
      }
    }
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();
  }

  void updateGuestinformation (Account* account) {
    int choice;

    cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by roomid" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        choice = val.getChoice();
        switch (choice)
        {
          case FINDNUM: {
            char ans = 'N';
            int RoomNumber;
            RoomNumber = val.room_input_validation();
            auto it = find_if(Acc.begin(),Acc.end(),[RoomNumber](Account* account) { return account->getroom() == RoomNumber; });
            do
            {
              if (it != Acc.end())
                {
                int choice;
                cout << "==========EDIT MENU==========" << endl;
                cout << "1.	Roomid" << endl;
                cout << "2.	Name" << endl;
                cout << "3.	Phone number" << endl;
                cout << "4.	Hours" << endl;
                cout << "5. Back" << endl;
                choice = val.getChoice();
                switch (choice)
                {
                case 1:
                {
                  int new_room;
                  cout << "Enter new roomid: ";
                  cin >> new_room;
                  Account *target = (*it);
                  target->setroom(new_room);
                  cout << "Roomid changed successfully" << endl;
                }
                break;

                case 2:
                {
                  string new_name;
                  cout << "Enter new name: ";
                  cin >> new_name;
                  Account *target = (*it);
                  target->setname(new_name);
                  cout << "Name changed successfully" << endl;
                }
                break;

                case 3:
                {
                  string new_num;
                  cout << "Enter new PhoneNumber: ";
                  cin >> new_num;
                  Account *target = (*it);
                  target->setnum(new_num);
                  cout << "Phone number changed successfully" << endl;
                }
                break;

                case 4:
                {
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
              else
              {
                cout << "Guest not found" << endl;
              }

              if (Acc.empty())
              {
                cout << "Nothing left to update" << endl;
                cout << "Press Enter to Continue...";
                cin.ignore();
                cin.get();
                break;
              }

              cout << "Do you want to continue (Y/N)? ";
              cin >> ans;
            } while ((ans == 'Y') || (ans == 'y'));
            
          }
          break;

          case FINDNAME:
          {
            char ans = 'N';
            string name;
            cout << "Enter name: ";
            cin >> name;
            auto it = find_if(Acc.begin(), Acc.end(), [name](const Account *account) { return account->getname() == name; });

            do
            {
              if (it != Acc.end())
              {
                int choice;
                Account *target = (*it);
                cout << "==========EDIT MENU==========" << endl;
                cout << "1.	Roomid" << endl;
                cout << "2.	Name" << endl;
                cout << "3.	Phone number" << endl;
                cout << "4.	Hours" << endl;
                cout << "5. Back" << endl;
                choice = val.getChoice();
                switch (choice)
                {
                case 1:
                {
                  int new_room;
                  cout << "Enter new Roomid: ";
                  cin >> new_room;
                  target->setroom(new_room);
                  cout << "Roomid changed successfully" << endl;
                }
                break;

                case 2:
                {
                  string new_name;
                  cout << "Enter new name: ";
                  cin >> new_name;
                  target->setname(new_name);
                  cout << "Name changed successfully" << endl;
                }
                break;

                case 3:
                {
                  string new_num;
                  cout << "Enter new Phone number: ";
                  cin >> new_num;
                  target->setnum(new_num);
                  cout << "Phone number changed successfully" << endl;
                }
                break;

                case 4:
                {
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

              if (Acc.empty())
              {
                cout << "Nothing left to update" << endl;
                cout << "Press Enter to Continue...";
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
          cout << "Press any key to continue...";
          cin.ignore();
          cin.get();
          updateGuestinformation(account);
        }

  }

  void deleteGuestinformation (Account* account) {
    int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by RoomID" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        choice = val.getChoice();
        switch (choice)
        {
          case FINDNUM: {
            char ans = 'N';
            int RoomNumber;
            do {
              
              RoomNumber = val.room_input_validation();
              auto it = find_if(Acc.begin(),Acc.end(),[RoomNumber](const Account* account) { return account->getroom() == RoomNumber; });
              if(it != Acc.end()){
              cout << "Guest information to be deleted:\n";
              Account* target = (*it);
              output_title();
              target->output();
              cout << endl;
              char choice;
              cout << "Do you want to delete this information? (y/n): ";
              cin >> choice;
              if (choice == 'y' || choice == 'Y') {
                Acc.erase(it);
                cout << "Guest information deleted successfully.\n";
              } else {
                cout << "Deletion canceled.\n";
              }
              } else {
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

          case FINDNAME: {
            char ans = 'N';
            string name;
            do {
              
              cout << "Enter name: ";
              cin >> name;
              auto it = find_if(Acc.begin(),Acc.end(),[name](const Account* account) { return account->getname() == name; });
              if(it != Acc.end()){
              cout << "Guest information to be deleted:\n";
              Account* target = (*it);
              output_title();
              target->output();
              cout << "Do you want to delete this information? (y/n): ";
              char choice;
              cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                  Acc.erase(it);
                  cout << "Guest information deleted successfully.\n";
                } else {
                  cout << "Deletion canceled.\n";
                }
              } else {
                cout << "Guest info not found" << endl;
              }

              if (Acc.empty())
              {
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
          cout << "Press enter to retry...";
          cin.ignore();
          cin.get();
          deleteGuestinformation(account);
        }
  }

  void DotDotDot() {
    for (int i = 0; i < 5; i++) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << endl;
  }

  void sortGuestinformation() {
    int choice;
        cout << "==========EDIT METHOD==========" << endl;
        cout << "1. Sort by Ascending" << endl;
        cout << "2. Sort by Descending" << endl;
        cout << "3. Back to main menu" << endl;
        choice = val.getChoice();
        switch (choice)
        {
        case 1:
          sort(Acc.begin(), Acc.end(), [](const Account* a, const Account* b) {
            return a->getnum() < b->getnum();                
          });    
          cout << "Sorting";
          DotDotDot();
          cout << "Sorted successfully" << endl;
          cout << "Press any key to continue...";
          cin.ignore();
          cin.get(); 
          break;
        case 2:
          sort(Acc.begin(), Acc.end(), [](const Account* a, const Account* b) {
          return a->getnum() > b->getnum();
        });
          cout << "Sorting";
          DotDotDot();
          cout << "Sorted successfully" << endl;
          cout << "Press any key to continue...";
          cin.ignore();
          cin.get();  
        break;

        case 3:
        break;

        default:
        cout << "Invalid choice." << endl;
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();      
        sortGuestinformation();
        }

  }

  void searchGuestinformation(Account* account){
    int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by roomid" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        choice = val.getChoice();
        switch (choice)
        {
        case FINDNUM:{
          int RoomNumber;
          char ans = 'N';
          do
          {
            
            RoomNumber = val.room_input_validation();
            auto it = find_if(Acc.begin(), Acc.end(), [RoomNumber](const Account *account) { return account->getroom() == RoomNumber; });
            if (it != Acc.end())
            {
              cout << "Roomid found:" << endl;
              output_title();
              Account *target = (*it);
              target->output();
              cout << endl;
            }
            else
            {
              cout << "Guest info not found" << endl;
            }

            if (Acc.empty())
              {
                cout << "Nothing left to search" << endl;
                cout << "Press Enter to Continue...";
                cin.ignore();
                cin.get();
                break;
              }

            cout << "Do you want to continue (Y/N)? ";
            cin >> ans;

            } while ((ans == 'Y') || (ans == 'y'));;
          
        }
        break;

        case FINDNAME:{
          string name;
          char ans = 'N';
          do {
            
            cout << "Enter name: ";
            cin >> name;
            auto it = find_if(Acc.begin(), Acc.end(), [name](const Account *account) { return account->getname() == name; });
            if (it != Acc.end())
            {
              cout << "Name found:" << endl;
              output_title();
              Account *target = (*it);
              target->output();
              cout << endl;
            }
            else
            {
              cout << "Guest info not found" << endl;
            }

            if (Acc.empty())
              {
                cout << "Nothing left to search" << endl;
                cout << "Press Enter to Continue...";
                cin.ignore();
                cin.get();
                break;
              }

            cout << "Do you want to continue (Y/N)? ";
            cin >> ans;

          } while ((ans == 'Y') || (ans == 'y'));;
          
        }
        break;

        case 3:
        break;

        default:
          cout << "Invalid choice." << endl;
          cout << "Press any key to continue...";
          cin.ignore();
          cin.get();
          searchGuestinformation(account);
        
        }
  }

  void saveGuestinformation() {
    ofstream outputFile("C:\\Users\\dombu\\Desktop\\Hotel-management-system\\Guest.dat", ios::out |ios::app);

    if (!outputFile.is_open()) {
        cout << "Error in creating file...\n";
        exit(1);
    } else {
        for (Account* account: Acc) {

            cout << "<<<=====" << (char*)& account;

            outputFile.write((char*)& account, sizeof(Account));
        }

        cout << "File saved successfully" << endl;
    }

    outputFile.close();
  }    

  void loadGuestinformation() {

    ifstream inputFile("C:\\Users\\dombu\\Desktop\\Hotel-management-system\\Guest.dat", ios::in|ios::app);

    if (!inputFile.is_open()) {
        cout << "Error in opening file...\n";
        exit(1);
    }


    Account account;
    
    try
    {
      while (inputFile.read((char* )& account, sizeof(Account)))
      {
        cout << "====>" << account.getname();
        // Acc.push_back(&account);
      }
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    

    cout << "File loaded successfully" << endl;
    inputFile.close();
  }

};
