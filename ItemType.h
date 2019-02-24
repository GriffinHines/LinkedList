#ifndef ItemType_h
#define ItemType_h
enum Comparison{Greater, Less, Equal};
class ItemType{
 private:
  int value;

 public:
  ItemType();
  Comparison compareTo(ItemType item);
  int getValue() const;
  void initialize(int num);
};
#endif /* DataType_h */
