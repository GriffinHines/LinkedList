#ifndef SortedLinkedList_h
#define SortedLinkedList_h

#include <iostream>
#include <string>
#include <stdio.h>
#include "ListNode.h"
class SortedLinkedList{
 private:
  int length;
  int iteratorPos = 0;
  ListNode *head;
  ListNode *currentPos;
 public:
  SortedLinkedList();
  ~SortedLinkedList();
  int getLength() const;
  void insertItem(ItemType item);
  void deleteItem(ItemType item);
  int searchItem(ItemType &item);
  ItemType getNextItem ();
  void resetList();
  void reverse();
  std::string displayList();
  int getPos();
};

#endif /* DataType_h */

