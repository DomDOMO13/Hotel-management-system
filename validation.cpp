#include<iostream>
#include <string>
class validation
{
private:
  const int maxchar = 12;
  bool boolean;
public:

bool length_check (std::string input) {

  return boolean = input.length() < maxchar;

};

void setlength_check(bool boolean) {

  this->boolean = boolean;

}

bool getlength_check() {

  return boolean;

}

};