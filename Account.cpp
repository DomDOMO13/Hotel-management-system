#pragma once
#include <iostream>
#include <iomanip>
#include "validation.cpp"
#include "BadInputException.cpp"
using namespace std;

class Account {

protected:

int RoomID;
string name;
string phone_num;
validation val;

public:

Account () {
RoomID = 0;
name = "unknown";
phone_num = "";
}

Account (int RoomID, string name, string phone_num) {
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
  if (!name.empty()) {
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
  if (!phone_num.empty()) {
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
   cout << setw(8) << getroom() << setw(17) << getname() << setw(22) << getnum();
}
  
virtual void input(){
  int room;
  string name;
  string num;
  validation val;

  room = val.input_room();
  setroom(room);

  name = val.input_name();
  setname(name);

  num = val.input_num();
  setnum(num);

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

  return out;
}

istream &read(std::istream &in)
{
  int length;

  in.read(reinterpret_cast<char *>(&RoomID), sizeof(RoomID));

  in.read(reinterpret_cast<char *>(&length), sizeof(length));
  name.resize(length);
  in.read(&name[0], length);

  in.read(reinterpret_cast<char *>(&length), sizeof(length));
  phone_num.resize(length);
  in.read(&phone_num[0], length);


  return in;
}

};