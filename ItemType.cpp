#include "ItemType.h"

ItemType::ItemType(){
}

Comparison ItemType::compareTo(ItemType item){
  if(value > item.value)
    return Greater;
  else if(value < item.value)
    return Less;
  else
    return Equal;
}

int ItemType::getValue() const{
  return value;
}

void ItemType::initialize(int num){
  value = num;
}
