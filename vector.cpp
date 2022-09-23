#include <iostream>
#include <cassert>
class vector {
  public:
    vector(int capacity = 8):
    capacity_(capacity), size_(0), data_(new int[capacity_]) {
    }

    vector(const vector &other): capacity_(other.capacity_), size_(other.size_),
    data_(new int[capacity_]) {
      std::copy(other.data_, other.data_ + size_, data_);
    }

    vector& operator=(const vector &other){
      if (capacity_ < other.capacity_) resize(other.capacity_);
      size_ = other.size_;
      for (int i = 0; i < size_; i++){
        data_[i] = other.data_[i];
      }
      return *this;
    }
    /* operator= with swap
    vector & operator=(vector other) {
    // copy ctor, new data_ initialized
    capacity_ = other.capacity_;
    size_ = other.size_;
    // data_ -> other, other.data_ -> this
    std::swap(data_, other.data_);
    // return *this;
  }
  */


    ~vector() { delete[] data_; }

    // adds element to the last avaialable position,
    // resizes vector if current capacity is reached
    void push_back(int num){
      //case if data is full
      if (size_ == capacity_){
        resize(capacity_*2);
      }
      data_[size_] = num;
      size_++;
    }
    int size() { return size_;}
    void set(int num, int idx){
      if (idx < 0 || idx >= size_) return;
      data_[idx] = num;
    }
    int at(int idx){
      if (idx < 0 || idx >= size_) return 0;
      return data_[idx];
    };

  private:
    int *data_;
    int size_;
    int capacity_;
    // resizes vector to given capacity
    void resize(int new_capacity){
      int *data2 = new int[new_capacity]();
      for (int i = 0; i < size_; i++){
        data2[i] = data_[i];
      }
      capacity_ = new_capacity;
      delete[] data_;
      data_ = data2;
    }
};


int main(int argc, char **argv) {

}