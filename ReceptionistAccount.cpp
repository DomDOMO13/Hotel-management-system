#pragma once
#include <iostream>
#include "Account.cpp"
#include "validation.cpp"
#include <iomanip>
using namespace std;

class ReceptionistAccount : public Account {
private:
int Days;

public:
ReceptionistAccount() : Account() {
  Days = 0;
}

ReceptionistAccount(int RoomID, string name, string phone_num, int Days) : Account (RoomID, name, phone_num) {
  setdays(Days);
}

void setdays(const int Days) {
  if(Days > 0) {
    this-> Days = Days;
  }
  else {
    throw BadInputException();
  }
}

int getdays () const {
  return Days;
}

void input() {
  int day;
  Account::input();
  day = val.input_day();
  setdays(day);
}

void output() override {
    cout << "------------------------------------------------------------------\n";
    cout << "    Roomid           Name           PhoneNumber              Days \n";
    cout << "------------------------------------------------------------------\n";
    Account::output();
    cout << setw(18) << getdays() << endl;
}

};
