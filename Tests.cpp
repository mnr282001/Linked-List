// TODO(student): the rest of the LinkedList
#include <cmath>
#include <iostream>
#include <string>
// #include <istream>
// #include <ostream>
// #include <sstream>
// #include <stdexcept>
#include "LinkedList.h"
using std::cout, std::cin, std::endl, std::string, std::size_t;


int main() {
  LinkedList list;
  list.display();
  cout << "The size of the list is " << list.size() << endl;
  list.push_back(6);
  list.push_back(5);
  list.push_back(4);
  list.push_back(3);
  list.push_back(2);
  list.push_back(1);
  // list.push_back(2);
  // list.push_back(11);
  // list.push_back(4);
  // list.push_back(3);
  // list.push_back(9);
  // list.push_back(8);
  cout <<"the lenght of the max decreasing is " << list.length_max_decreasing() << endl;
  list.display();
  cout << "The size of the list is " << list.size() << endl;
  cout << "Find the last iteration of 11: " << list.find_last_of(11) << endl;
  list.display();
  cout << "The size of the lsit is " << list.size() << endl;
  list.remove_duplicates();
  cout << endl;
  list.display();
  cout << "The size of the list is " << list.size() << endl;
  // cout <<"the lenght of the max decreasing is " << list.length_max_decreasing() << endl;

  LinkedList list_A;
  for (int n = 1; n <= 3; ++n) {
    list_A.push_back(n);
  }
  cout << "list a: ";
  list_A.display();
  cout << endl;
  LinkedList list_B(list_A);
  cout << "list b: ";
  list_B.display();
  cout << endl;
  list_B.push_back(4);
  cout << "list b: ";
  list_B.display();
  cout << endl;
  list_A = list_B;
  cout << "list a: ";
  list_A.display();
  list.remove(1);
  list.display();
  cout << "The size of the list is " << list.size() << endl;
  // list.remove_first();
  list.display();
  cout << "The size of the list is " << list.size() << endl;
  list.remove(1);
  list.display();
  cout << "Thes size of the list is " << list.size() << endl;
  list.head();
  cout << list.contains(1) << endl;
  return 0;
}
