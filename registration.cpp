#include<iostream>
#include<fstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "validation.cpp"
using namespace std;
class login
{
private:
    string username;
    string length;
    string password;
public:

validation vali;


bool userLogin() {
    cout << "Enter the username: ";
    cin >> username;
    cout << "Enter the password: ";
    cin >> password;

    bool userFound = false;
    ifstream fin("users.dat", ios::in);

    if (!fin.is_open()) {
        cerr << "Cannot open file" << endl;
        return false;
    }

    string fileUsername, filePassword;
    while (fin >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            cout << "Welcome to Hotel management system" << " "<< username << endl;
            userFound = true;
            break;
        }
    }
    fin.close();

    if (!userFound) {
        cout << "User not found" << endl;
    }
    return userFound;
}

void userRegister() {

    while (1)
    {
        cout << "Enter the Username: ";
        cin >> username;
        vali.length_check(username);
        if (!vali.length_check(username)) {
            cout << "The input is too long." << endl;
        } 
        else{
            break;
        }
    }
     while (1)
    {
        cout << "Enter the password: ";
        cin >> password;
        vali.length_check(password);
        if (!vali.length_check(password)) {
            cout << "The input is too long." << endl;
        }
        else {
            break;
        }
    }

    // ----exited validation-------
    // string fileUsername, filePassword;
    // ifstream fin("users.dat", ios::in);
    // while (fin >> fileUsername >> filePassword) {
    //         if (fileUsername == username) {
    //                 // system("cls");
    //                 cout << "This shit already exist" << endl;
    //                 userRegister();
    //             }
    //         else {

    //             break;

    //         }
    // }
    // fin.close();

    ofstream fout("users.dat", ios::out | ios::app);

    if (!fout.is_open()) {
        cerr << "Cannot open file" << endl;
        return;
    }

    fout << username << " " << password << endl;
    fout.close();
    cout << "User created" << endl;
    
    
}


};