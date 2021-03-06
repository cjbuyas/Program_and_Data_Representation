// Charles Buyas, cjb8qf, 1-29-17, List.cpp

#include <iostream>
#include "List.h"
using namespace std;

List::List() {
  head = new ListNode;
  tail = new ListNode;
  count = 0;
  head->next = tail;
  head->previous = NULL;
  tail->previous = head;
  tail->next = NULL;
}



List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
  if (this->size() == 0) {
    return true;
  }
  else {
    return false;
  }
}

void List::makeEmpty() {
  ListItr currentNew(head);
  currentNew.moveForward();
  while (!currentNew.isPastEnd()) {
      currentNew.moveForward();
      delete currentNew.current->previous;
  }
  count = 0;
}

ListItr List::first() {
  ListItr currentNew = head->next;
  return currentNew;
}

ListItr List::last() {
  ListItr currentNew = tail->previous;
  return currentNew;
}

void List::insertAfter(int x, ListItr position) {
  ListNode *newNode = new ListNode();
  newNode->value = x;
  ListNode *tempNode = position.current->next;
  tempNode->previous = newNode;
  newNode->next = tempNode;
  newNode->previous = position.current;
  position.current->next = newNode;
  count++;
}

void List::insertBefore(int x, ListItr position) {
  ListNode *newNode = new ListNode();
  newNode->value = x;
  ListNode *tempNode = position.current->previous;
  tempNode->next = newNode;
  newNode->previous = tempNode;
  newNode->next = position.current;
  position.current->previous = newNode;
  count++;
}

void List::insertAtTail(int x) {
  ListItr itr(tail);
  this->insertBefore(x, itr);
  //count++;
}

void List::remove(int x) {
  ListItr found = this->find(x);
  found.current->previous->next = found.current->next;
  found.current->next = found.current->previous;
  delete found.current;
  count--;
}

ListItr List::find(int x) {
  ListItr itr(head);
  if (itr.current->next != tail) {
    while (itr.current->value != x) {
      itr.moveForward();
    }
  }
  return itr;
}

int List::size() const {
  return count;
}

void printList(List& source, bool direction) {
  if (direction == true) {
    ListItr printItr(source.first());
    while (printItr.isPastEnd() == false) {
      cout << printItr.retrieve() << ", " << endl;
      printItr.moveForward();
    }
  }
  
  else {
    ListItr backItr(source.last());
    while (!backItr.isPastBeginning()) {
      cout << backItr.retrieve() << "," << endl;
      backItr.moveBackward();
    }
  }
}
