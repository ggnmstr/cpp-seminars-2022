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
        iterator(iterator &other) = default;
        bool operator==(iterator &other) const;
        bool operator!=(iterator &other) const;

        int& operator*();

        // prefix ++it
        iterator & operator++();
        // postfix it++
        iterator /*???*/ operator++(int);
      
      private:
        int idx_;
        vector & v;
  };

  iterator /*???*/ begin();

  iterator /*???*/ end();

  private:
    int *data_;
    int size_;
    int capacity_;
    // resizes vector to given capacity
    void resize(int new_capacity);
};
