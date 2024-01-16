#pragma once
#include <iostream>
#include "Receptionist.cpp"
#include "ReceptionistAccount.cpp"
#include "registration.cpp"
using namespace std;

enum {
    ADDGUEST = 1,
    DISPLAYGUEST,
    UPDATEGUEST,
    DELETEGUEST,
    SORTGUEST,
    SEARCHGUEST,
    SAVEGUEST,
    LOADGUEST,
    LOGOUT

};

class Application {
 private:

Receptionist re;
Account* account{};

    void bankMenu() {
        cout << "==========Bank Management Menu==========" << endl;
        cout << "1. Create bank account" << endl;
        cout << "2. View all bank account" << endl;
        cout << "3. Update a specific bank account" << endl;
        cout << "4. Delete a specific bank account" << endl;
        cout << "5. Sort bank account" << endl;
        cout << "6. Search for a specific bank account" << endl;
        cout << "7. Save bank data" << endl;
        cout << "8. Log out" << endl;
    }

    void authenticationMenu(){
        cout <<"==========Bank Management System==========" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
    }


    int getChoice() {
        int choice;

        cout << "Enter your choice(1-10)-> ";
        cin >> choice;
        return choice;

    }

    
 public:

 void HotelManagement(){
    
        int choice = 0;
    int option = 0;

   
    do {
        bankMenu();
        choice = getChoice();

        switch (choice) {
            case ADDGUEST: {
                re.addguest(account);
                break;
            }

            case DISPLAYGUEST:
                re.viewguest();
                break;

            case UPDATEGUEST: {
                re.updateGuestinformation(account);
                break;
            }

            case DELETEGUEST:
                re.deleteGuestinformation(account);
                break;

            case SORTGUEST:
                 re.sortGuestinformation();
                break;

            case SEARCHGUEST:
                re.searchGuestinformation(account);
                break;

            case SAVEGUEST:
                re.saveGuestinformation();
                break;
            case LOGOUT:
                break;

            default:
                cout << "Invalid Choice, Try again" << endl;
                break;
            }    
        
        }while (choice != 8);
 }

    void run() {
     int choice = 0;
     login log;


     do {
     
      authenticationMenu();
      choice = getChoice();
      switch (choice)
      {
      case 1:
        if(log.userLogin()==true){
          system("cls");
          re.loadGuestinformation();
          HotelManagement();
        }else{
          cout << "Login failed. Please try again." << endl;
        }
      break;
      case 2:
        log.userRegister();
      break;
      case 3:
      exit(1);
     
      default:
      cout << "Invalid choice. Please try again." << endl;
        break;
      }


     }while(choice != 0);
    }







};