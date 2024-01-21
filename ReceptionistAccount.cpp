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

    ofstream &write(std::ofstream &out) {
      Account::write(out);
      out.write(reinterpret_cast<const char *>(&Days), sizeof(Days));
      return out;
    }

    istream &read(std::istream &in) {
      Account::read(in);
      in.read(reinterpret_cast<char *>(&Days), sizeof(Days));
      return in;
    }

};