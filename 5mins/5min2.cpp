#include <initializer_list>
#include <iostream>

class linked_list {
 public:
  linked_list(const std::initializer_list<int>& initializer) {
    node* prev = nullptr;
    head_ = nullptr;
    for (int i : initializer) {
      node* n = new node{i, nullptr};
      if (prev != nullptr) {
        prev->next = n;
        prev = n;
      } else {
        head_ = n;
        prev = n;
      }
    }
  }

  ~linked_list() {
    while (head_ != nullptr) {
      node* next = head_->next;
      delete head_;
      head_ = next;
    }
  }


 private:
  
  struct node {
    int data;
    node* next;
  };

  node * head_;

   public:
  class iterator{
    public:
        iterator(node *cur): cur_(cur){};
        iterator(iterator &other) = default;
        bool operator==(const iterator &other) const{
            return (cur_ == other.cur_);
        };
        bool operator!=(const iterator &other) const{
            return !(*this == other);
        };

        int& operator*(){
            return cur_->data;
        };

        // prefix ++it
        iterator & operator++(){
            cur_ = cur_->next;
            return *this;
        };
        // postfix it++
        iterator operator++(int){
            iterator tmp(*this);
            cur_ = cur_->next;
            return tmp;
        };

    private:
        node* cur_;
  };

  iterator begin() {
    return iterator(head_);
  }

  iterator end() {
    return iterator(nullptr);
  }
  

};

int main(int argc, char** argv) {
  linked_list list = {1, 2, 3};
  for (int i : list) {
    std::cout << i << std::endl;
  }
}