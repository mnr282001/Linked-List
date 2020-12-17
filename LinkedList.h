#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;
// TODON'T(student): change the visibility, types, or names of the members
// TOMAYBE(student): the optional-rest of the Node
};


class LinkedList {
// the type to use for sizes and indices is size_t.
// TODO(student): the rest of the LinkedList
private:
  size_t _size;
  Node* _head;
  Node* _tail;

public:
  LinkedList();//default constructor
  LinkedList(const LinkedList &list);//default (zero size, null head) with the extra bit
  ~LinkedList();//deconstructor
  LinkedList& operator=(const LinkedList &list);//assignment operator
  size_t size() const;//return number of elements in the list
  const Node* head() const;//return pointer to the head of the list
  void push_back(int value);//append the value to the end of the list
  void display();//display the linked list
  // void remove_first();//remove the first element of the List
  void remove(size_t index);//remove the ith element of the list
  void remove_duplicates();//remove duplicates in the list
  size_t length_max_decreasing();//returns the length of the maximum subsequence of strictly decreasing values
  bool contains(int value) const;//returns whether the list contains the specificed value
  size_t find_last_of(int value) const;//return the last element equal to the given value

};

#endif  // LINKEDLIST_H
