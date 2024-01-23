#pragma once
#include <iostream>
#include "Account.cpp"
#include "validation.cpp"
#include <iomanip>
using namespace std;

class ReceptionistAccount : public Account {

  private:
    int hour;

  public:
    ReceptionistAccount() : Account() {
      hour = 0;
    }

    ReceptionistAccount(int RoomID, string name, string phone_num, int hour) : Account (RoomID, name, phone_num) {
      setdays(hour);
    }

    void setdays(int hour) {
      if(hour > 0) {
        this-> hour = hour;
      }
      else {
        throw BadInputException();
      }
    }

    int getdays () const {
      return hour;
    }

    void input() {
      int hour;
      Account::input();
      hour = vali.input_day();
      setdays(hour);
    }

    void output() override {
      Account::output();
      cout << setw(18) << getdays();
    }

    ofstream &write(std::ofstream &out) {
      Account::write(out);
      out.write(reinterpret_cast<const char *>(&hour), sizeof(hour));
      return out;
    }

    istream &read(std::istream &in) {
      Account::read(in);
      in.read(reinterpret_cast<char *>(&hour), sizeof(hour));
      return in;
    }

};