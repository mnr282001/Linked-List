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
LinkedList::LinkedList() :_size(0), _head(nullptr), _tail(nullptr) {

}
LinkedList::LinkedList(const LinkedList &list) : _size(0), _head(nullptr), _tail(nullptr) {
  // _size = 0;
  // _head = nullptr;
  // _tail = nullptr;
  Node* temp = list._head;
  while(temp != nullptr) {
    this->push_back(temp->data);
    temp = temp->next;
  }
}
LinkedList::~LinkedList() {
  Node* temp = _head;
  while(temp != nullptr) {
    Node* next = temp->next;
    delete temp;
    temp = next;
  }
}
LinkedList& LinkedList::operator=(const LinkedList &list) {
  Node* temp = _head;
  while (temp->next != nullptr) {
    _head = _head->next;
    delete temp;
    temp = _head;
  }
  temp = list._head;

  while(temp != nullptr) {
    this->push_back(temp->data);
    temp = temp->next;
  }
  return *this;
}
size_t LinkedList::size() const {
  return _size;
}
void LinkedList::push_back(int value) {
  Node* temp = new Node;
  temp->data = value;
  temp->next = nullptr;

  if (_head == nullptr) {
    _head = _tail = temp;
    //tail = temp;
    //temp = nullptr;
  } else {
    _tail->next = temp;
    _tail = temp;
  }
  ++_size;
  //delete temp;
}
const Node* LinkedList::head() const{
  if (_size == 0) {
    return nullptr;
  }
  return _head;
}
void LinkedList::display() {
  Node* temp = _head;
  if(_size == 0) {
    cout << "The linked list is empty" << endl;
    return;
  }
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// void LinkedList::remove_first() {
//   if (_head != nullptr) {
//     Node* temp = _head;
//     _head = _head->next;
//     delete temp;
//     if (_head == nullptr) {
//       _tail = nullptr;
//     }
//   }
//   --_size;
// }
//
void LinkedList::remove(size_t index) {
  Node* curr = _head;
  size_t pos = 0;
  Node* prev = nullptr;
  while (curr != nullptr && pos < index) {
    prev = curr;
    curr = curr->next;
    ++pos;
  }
  if (pos == index && curr != nullptr) {
    if (prev != nullptr) {
      prev->next = curr->next;
    } else {
      _head = curr->next;
    }
    if (curr == _tail) {
      _tail = prev;
    }
    delete curr;
    --_size;
  } else {
    cout << index << endl;
    if(index >= size()) {
      throw std::out_of_range("index too large");
    }
  }

}

void LinkedList::remove_duplicates() {
  Node* temp = _head;
  //Node* tempNext;
  int counter;
  // while(temp != nullptr) { //while loop doesnt work, try for loop method
  //   Node* tempNext = temp->next;
  //   counter = 0;
  //   while (tempNext != nullptr) {
  //     if (tempNext->data == temp->data) {
  //       Node* other = tempNext;
  //       tempNext = tempNext->next;
  //       delete other;
  //       ++counter;
  //     } else {
  //       tempNext = tempNext->next;
  //     }
  //   }
  //   _size = _size-counter;
  //   temp= temp->next;
  // }
  for(size_t i = 0; i < size(); ++i) { //for loop method works
    Node* tempNext = temp;
    counter = 0;
    for(size_t j = i+1; j<size(); ++j) {
      if(temp->data == tempNext->next->data) {
        ++counter;
        Node* tempPrev = tempNext->next;
        // tempNext = tempNext->next;
        // tempNext = tempNext->next;
        tempNext->next = tempNext->next->next;
        // delete tempNext;
        // delete temp;
        //
        delete tempPrev;

        // --_size;
      } else {
        tempNext = tempNext->next;
      }
    }
    //decrease the size by the counter

    _size = _size - counter;
    //move onto the next node of temp
    temp = temp->next;
  }
}

size_t LinkedList::length_max_decreasing() {
  size_t counter = 1;
  size_t output = 0;

  Node* temp = _head;
  Node* tempChecker = temp;

  //temp = _head;
  while(temp->next!=nullptr) {
    tempChecker = temp;
    temp = temp->next;
    if(temp->data < tempChecker->data) {
      ++counter;
    } else {
      counter = 1;
    }
    if(counter > output) {
      output = counter;
    }
  }
  //delete temp;
  //delete tempChecker;
  if (output == 0 && _size != 0) {
    output = 1;
  }
  return output;
}

bool LinkedList::contains(int value) const {
  bool checker = false;
  Node* temp = _head;
  while(temp->next != nullptr) {
    if(temp->data == value) {
      checker = true;
      return checker;
    }
    temp=temp->next;
  }
  delete temp;
  return checker;
}

size_t LinkedList::find_last_of(int value) const {
  size_t holder = -1;
  size_t iterator = 0;
  holder = static_cast<size_t>(holder);
  Node* temp = _head;
  while(temp->next != nullptr) {
    if(temp->data == value) {
      holder = iterator;
    }
    ++iterator;
    temp = temp->next;
  }
  return holder;
}
