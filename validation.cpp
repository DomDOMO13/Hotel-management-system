#include<iostream>
#include <string>
#include "BadInputException.cpp"
class validation
{
private:
  const int maxchar = 12;
  bool boolean;
public:

bool length_check (std::string input) {
  return boolean = input.length() < maxchar;
};
void setlength_check(const bool boolean) {
     if(boolean != 1 || boolean != 0){
        this->boolean = boolean;
    }else{
        throw BadInputException();
    }
}
bool getlength_check() const {
  return boolean;
}



};