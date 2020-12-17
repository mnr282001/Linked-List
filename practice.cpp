#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string;


struct Name {
  string data;
};
void name(Name name) {
  name.data = "";
}
void setName(Name name) {
  cout << "What is your name: ";
  cin >> name.data;
}
void printName(Name name) {
  cout << "Your name is " << name.data << endl;
}

int main() {
  Name Nayab;
  name(Nayab);
  setName(Nayab);
  printName(Nayab);
}
