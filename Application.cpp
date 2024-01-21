#pragma once
#include <iostream>
#include "Receptionist.cpp"
#include "ReceptionistAccount.cpp"
#include "registration.cpp"
#include "validation.cpp"
using namespace std;

enum {
    ADDGUEST = 1,
    DISPLAYGUEST,
    UPDATEGUEST,
    DELETEGUEST,
    SORTGUEST,
    SEARCHGUEST,
    SAVEGUEST,
    LOGOUT,
};

class Application {
    private:

        Receptionist re;
        Account* account;
        validation val;

        void HotelMenu() {
            cout << "==========Hotel Management Menu==========" << endl;
            cout << "1. Add Guest information" << endl;
            cout << "2. View Guest information" << endl;
            cout << "3. Update a specific Guest information" << endl;
            cout << "4. Delete a specific Guest information" << endl;
            cout << "5. Sort Guest information" << endl;
            cout << "6. Search for a specific Guest information" << endl;
            cout << "7. Save guest data" << endl;
            cout << "8. Log out" << endl;
        }

        void authenticationMenu(){
            cout <<"==========Hotel Management System==========" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "3. Exit" << endl;
        }
        
    public:

        void HotelManagement() {
            int choice = 0;
            do {
                HotelMenu();
                choice = val.getChoice();
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
                choice = val.getChoice();
                switch (choice)
                {
                case 1:
                    if (log.userLogin() == true) {
                        system("cls");
                        re.loadGuestinformation();
                        HotelManagement();
                    }
                    break;

                case 2:
                    log.userRegister();
                    break;

                case 3:
                    cout << "Exiting Programm..." << endl;
                    exit(1);

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            } while (choice != 0);
        }
};