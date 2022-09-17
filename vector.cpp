class vector {
  public:
    //default constructor 
    vector(){
      capacity_ = 8;
      size_ = 0;
      data_ = new int[capacity_]();
    }
    vector(int capacity) {
      capacity_ = capacity;
      size_ = 0;
      data_ = new int[capacity]();
    }
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
    void set(int num, int idx);
    int at(int idx);

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
      delete[] data_;
      data_ = data2;
    }
};

int main(int argc, char **argv) {
  //vector v1;
  //v1.push_back(5);
}