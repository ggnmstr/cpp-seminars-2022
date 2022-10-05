#include "vector.hpp"
#include <iostream>
#include <cassert>

vector::vector(int capacity):
  capacity_(capacity), size_(0), data_(new int[capacity_]) {
  }

vector::vector(const vector &other): capacity_(other.capacity_), size_(other.size_),
  data_(new int[capacity_]) {
    std::copy(other.data_, other.data_ + size_, data_);
  }

vector& vector::operator=(const vector &other){
    if (capacity_ < other.capacity_) resize(other.capacity_);
    size_ = other.size_;
    for (int i = 0; i < size_; i++){
      data_[i] = other.data_[i];
    }
    return *this;
  }

int & vector::operator[](int idx){
    assert(idx >= 0 && idx < size_);
    return data_[idx];
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


vector::~vector() { delete[] data_; }

  // adds element to the last avaialable position,
  // resizes vector if current capacity is reached
void vector::push_back(int num){
    //case if data is full
    if (size_ == capacity_){
      resize(capacity_*2);
    }
    data_[size_] = num;
    size_++;
  }
int vector::size() { return size_;}
void vector::set(int num, int idx){
    if (idx < 0 || idx >= size_) return;
    data_[idx] = num;
  }
int vector::at(int idx){
    if (idx < 0 || idx >= size_) return 0;
    return data_[idx];
  };

  // resizes vector to given capacity
void vector::resize(int new_capacity){
    int *data2 = new int[new_capacity]();
    for (int i = 0; i < size_; i++){
      data2[i] = data_[i];
    }
    capacity_ = new_capacity;
    delete[] data_;
    data_ = data2;
  }


vector::iterator vector::begin(){
  return vector::iterator(0,*this);
}

vector::iterator vector::end(){
  return vector::iterator(size_,*this);
}

// iterator

int & vector::iterator::operator*() {
  return v_[idx_];
}

// int a = ++it;
vector::iterator & vector::iterator::operator++() {
  idx_++;
  return *this;
}

// int a = it++;
vector::iterator vector::iterator::operator++(int) {
  iterator tmp(*this);
  idx_++;
  return tmp;
}

bool vector::iterator::operator==(const vector::iterator & other) const{
  return (&this->v_ == &other.v_ && this->idx_ == other.idx_); 
}

bool vector::iterator::operator!=(const vector::iterator & other) const{
  return !(*this == other); 
}

int main(int argc, char **argv) {
}