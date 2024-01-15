#pragma once
#include <iostream>
#include <iomanip>
#include "validation.cpp"
#include "BadInputException.cpp"
using namespace std;

class guestlist {

protected:

int RoomID;
string name;
string phone_num;
validation val;

public:

guestlist () {

RoomID = 0;
name = "unknown";
phone_num = "012345789";

}

guestlist (int RoomID, string name, string phone_num) {

  setroom(RoomID);
  setname(name);
  setnum(phone_num);


}

void setroom(const int RoomID) {
  if(RoomID > 0) {
    this-> RoomID = RoomID;
  }
  else {
    throw BadInputException();
  }
}
int getroom() const {
  return RoomID;
}

void setname(const string name) {

  if (!name.empty() ) {

    this->name = name;

  }
  else
  {
    throw BadInputException();
  }
}

string getname() const {
  return name;
}

void setnum(const string phone_num) {

  if (!phone_num.empty() ) {

    this->phone_num = phone_num;

  }
  else
  {
    throw BadInputException();
  }
}

string getnum() const {
  return phone_num;
}


virtual void output(){
    
  cout << setw(8) << getroom() << setw(16) << getname() << setw(13) << getnum();
}
  

};