#pragma once


class vector {
  public:
    vector(int capacity = 8);

    ~vector();

    vector(const vector &other);

    vector& operator=(const vector &other);

    int & operator[](int idx);

    void push_back(int num);
    int size();
    void set(int num, int idx);
    int at(int idx);

    class iterator{
      public:
        iterator(int idx, vector &v): idx_(idx),v_(v){};
        iterator(iterator &other) = default;
        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;

        int& operator*();

        // prefix ++it
        iterator & operator++();
        // postfix it++
        iterator /*???*/ operator++(int);
      
      private:
        int idx_;
        vector & v_;
  };

  iterator /*???*/ begin();

  iterator /*???*/ end();

  private:
    int capacity_;
    int size_;
    int *data_;
    
    // resizes vector to given capacity
    void resize(int new_capacity);
};
