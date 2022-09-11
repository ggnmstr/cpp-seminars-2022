class vector {
  int *data;
  int size;
  int capacity;

  vector(int capacity) {
    this->capacity = capacity;
    this->size = size;
    this->data = new int[capacity]();
  }

  ~vector() { delete[] data; }

  // adds element to the last avaialable position,
  // resizes vector if current capacity is reached
  void push_back(int num);
  // resizes vector to given capacity
  void resize(int new_capacity);

  int size() { return this->size; }

  void set(int num, int idx);
  int at(int idx);
  void push_back(int num){
    //case if data is full
    //if (size = )
    this->data[size++] = num;
  }
  void resize(int new_capacity){

  }
};

int main(int argc, char **argv) {
  // vector v;
  // v.size();
  // // size(&v)
  // vector v1;
  // v1.size();
}