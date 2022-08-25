#pragma once
#include <initializer_list>

class vec1 {
private:
  size_t sz;    // the size
  double *elem; // a pointer to the element
public:
  // constructor
  explicit vec1(size_t);
  // constructor
  vec1(std::initializer_list<double>);
  // copy constructor
  vec1(const vec1 &);
  // copy assignment
  vec1 &operator=(const vec1 &);
  // move constructor
  vec1(vec1 &&);
  // move assignment
  vec1 &operator=(vec1 &&);
  // destructor
  ~vec1();
  // get size
  size_t size();
  // get element
  double get(size_t) const;
  // set element
  void set(size_t, double);
  // operator get element
  double operator[](size_t) const;
  // operator set element
  double &operator[](size_t);
};
