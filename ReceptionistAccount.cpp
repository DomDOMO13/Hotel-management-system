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

void setdays(int Days) {
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
    Account::output();
    cout << setw(18) << getdays();
}

istream &read(std::istream &in)
{
  in.read(reinterpret_cast<char *>(&RoomID), sizeof(RoomID));

  int length;
  in.read(reinterpret_cast<char *>(&length), sizeof(length));
  name.resize(length);
  in.read(&name[0], length);

  in.read(reinterpret_cast<char *>(&length), sizeof(length));
  phone_num.resize(length);
  in.read(&phone_num[0], length);

  return in;
}

ofstream &write(std::ofstream &out)
{
  out.write(reinterpret_cast<const char *>(&RoomID), sizeof(RoomID));

  int length = name.length();
  out.write(reinterpret_cast<const char *>(&length), sizeof(length));
  out.write(name.c_str(), length);

  length = phone_num.length();
  out.write(reinterpret_cast<const char *>(&length), sizeof(length));
  out.write(phone_num.c_str(), length);

  out.write(reinterpret_cast<const char *>(&RoomID), sizeof(RoomID));
  return out;
}


};

