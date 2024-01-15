#include <iostream>
#include "Account.cpp"
using namespace std;

class AccountDAO {
public:
virtual void addguest(Account* account) = 0;
virtual void viewguest() = 0;
virtual void updateGuestinformation(Account* account) = 0;
virtual void deleteGuestinformation(Account* account) = 0;
virtual void sortGuestinformation() = 0;
virtual void searchGuestinformation(Account* account) = 0;
virtual void saveGuestinformation() = 0;
virtual void loadGuestinformation() = 0;
};