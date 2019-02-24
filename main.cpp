#include <fstream>
#include <iostream>
#include "SortedLinkedList.h"

//main input.txt Commands:                                                     //  (i) - Insert value                                                        
//  (d) - Delete value                                                        
//  (s) - Search value                                                        
//  (n) - Print next iterator value                                            
//  (r) - Reset iterator                                                      
//  (p) - Print list                                                           
//  (l) - Print length                                                         //  (b) - Reverse                                                              
//  (q) - Quit program                                                          
int main(int argc, const char *argv[]){
  SortedLinkedList list;
  ItemType item;
  int input;
  std::fstream fs;
  fs.open(argv[1], std::fstream::in);
  if (fs.is_open()) {
    fs >> input;
    while (!fs.eof()) {
      item.initialize(input);
      list.insertItem(item);
      fs >> input;
    }
  }
  else {
    std::cout << "Failed to open the input file" << std::endl;
    return 0;
  }
  while(true){
    char userInput;
    std::cout << list.displayList();
    std::cout << "Enter a comand: ";
    std::cin >> userInput;
    if(userInput == 'i'){
      std::cout << list.displayList();
      std::cout << "Enter a number: ";
      std::cin >> input;
      item.initialize(input);
      list.insertItem(item);
      std::cout << list.displayList();
    }
    else if(userInput == 'd'){
      std::cout << list.displayList();
      std::cout << "Enter value to delete: ";
      std::cin >> input;
      item.initialize(input);
      list.deleteItem(item);
      std::cout << list.displayList();
    }
    else if(userInput == 's'){
      std::cout << "Enter a value to search: ";
      std::cin >> input;
      item.initialize(input);
      std::cout << list.searchItem(item) << std::endl;
    }
    else if(userInput == 'n'){
      list.getNextItem();
      std::cout << list.getPos() << std::endl;
    }
    else if(userInput == 'r'){
      list.resetList();
      std::cout << "Iterator reset" << std::endl;
    }
    else if(userInput == 'p')
      std::cout << list.displayList();
    else if(userInput == 'l')
      std::cout << "List length is " << list.getLength() << std::endl;
    else if(userInput == 'b'){
      std::cout << "Before:\n" << list.displayList();
      list.reverse();
      std::cout << "After:\n";
    }
    else if(userInput == 'q'){
      std::cout << "Quitting program...\n" << std::endl;
      return 0;
    }
    else
      std::cout << "Invalid input" << std::endl;
  }
}
