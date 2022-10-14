// определите оператор== и оператор!= как внешние функции
//DONE
#include <iostream>

class Wrapper {
 public:
  explicit Wrapper(int i) : data_(i) {}

 private:
  friend bool operator==(const Wrapper &one, const Wrapper &two);
  friend bool operator!=(const Wrapper &one, const Wrapper &two);
  int data_;
};

bool operator==(const Wrapper &one,const Wrapper &two){
    return one.data_ == two.data_;
}

bool operator!=(const Wrapper &one,const Wrapper &two){
    return !(one==two);
}

int main () {
  Wrapper w1(1);
  Wrapper w2(2);
  std::cout << (w1 == w2) << std::endl;
}