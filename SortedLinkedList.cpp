#include "SortedLinkedList.h"
#include "ListNode.h"

SortedLinkedList::SortedLinkedList(){
  length = 0;
}

SortedLinkedList::~SortedLinkedList(){
  while(length > 0){
    ListNode *p = head;
    head = head->next;
    delete p;
    length--;
  }
}

int SortedLinkedList::getLength() const{
  return length;
}

void SortedLinkedList::insertItem(ItemType item){
  struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode *\
							      ));
  struct ListNode* current;
  struct ListNode* predLoc = (struct ListNode*) malloc(sizeof(struct ListNode *\
							      ));
  predLoc->next = head;
  newNode->item = item;
  int location = 0;
  if(length == 0){
    head = newNode;
    currentPos = (struct ListNode*) malloc(sizeof(struct ListNode *));
    currentPos->next = head;
  }
  else{
    current = head;
    bool moreToSearch = location < length;
    while(moreToSearch){
      if(item.compareTo(current->item) == Less)
        moreToSearch = false;
      else if(item.compareTo(current->item) == Equal)
	return;
      else if(item.compareTo(current->item) == Greater){
        location++;
	moreToSearch = location < length;
        predLoc = current;
        current = current->next;
      }
    }
  }
  newNode->next = current;
  if(location == 0)
    head = newNode;
  else
    predLoc->next = newNode;
  length++;
}

void SortedLinkedList::deleteItem(ItemType item){
  int location = 0;
  bool moreToSearch = location < length;
  ListNode *current = head;
  ListNode *previous;
  while(moreToSearch){
    if (current->item.compareTo(item) == Equal){
      if(location == 0){
        head = head->next;
      }
      else{
        previous->next = current->next;
      }
      delete current;
      length--;
      return;
    }
    else{
      previous = current;
      current = current->next;
      location++;
    }
    moreToSearch = location < length;
  }
  std::cout << "Item not found" << std::endl;
}

int SortedLinkedList::searchItem(ItemType &item){
  int location = 0;
  bool moreToSearch = location < length;
  ListNode *current = head;
  while(moreToSearch){
    if(current->item.compareTo(item) == Equal){
      std::cout << "Index: ";
      return location;
    }
    current = current->next;
    location++;
    moreToSearch = location < length;
  }
  std::cout << "Item not found" << std::endl;
}

ItemType SortedLinkedList::getNextItem(){
  if(iteratorPos >= length){
    std::cout << "End of list" << std::endl;
    return currentPos->item;
  }
  iteratorPos++;
  currentPos = currentPos->next;
  return currentPos->item;
}

void SortedLinkedList::resetList(){
  ListNode *start = (struct ListNode*) malloc(sizeof(struct ListNode *));
  start->next = head;
  currentPos = start;
  iteratorPos = 0;
}

void SortedLinkedList::reverse(){
  ListNode *prev = head;
  ListNode *current = head->next;
  ListNode *after = head->next->next;

  int currentPos = 1;
  bool moreToSet = currentPos < length;
  while(moreToSet){
    current->next = prev;
    prev = current;
    current = after;
    after = current->next;
    currentPos++;
    moreToSet = currentPos < length;
  }
  head = prev;
}

std::string SortedLinkedList::displayList(){
  std::string list = "";
  int loc = 0;
  bool moreToRead = loc<length;
  struct ListNode* temp = head;
  while(moreToRead){
    list = list + std::to_string(temp->item.getValue()) + " ";
    temp = temp->next;
    loc++;
    moreToRead = loc<length;
  }
  list = list + "\n";
  return list;
}

int SortedLinkedList::getPos(){
  return iteratorPos;
}
