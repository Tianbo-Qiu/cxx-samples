#include "vec.h"
#include <algorithm>

vec1::vec1(size_t _sz) : sz{_sz}, elem{new double[_sz]} {
  // init elements
  for (size_t i = 0; i < _sz; ++i)
    elem[i] = 0;
}

vec1::vec1(std::initializer_list<double> lst)
    : sz{lst.size()}, elem{new double[lst.size()]} {
  std::copy(lst.begin(), lst.end(), elem);
}

/**
 * copy constructor
 */
vec1::vec1(const vec1 &other) : sz{other.sz}, elem{new double[other.sz]} {
  std::copy(other.elem, other.elem + other.sz, elem);
}

/**
 * copy assignment
 */
vec1 &vec1::operator=(const vec1 &other) {
  // first copy into another array
  // make sure we don't need it anymore before deletion
  // e.g. what about assign to itself
  double *p = new double[other.sz];
  std::copy(other.elem, other.elem + other.sz, p);
  delete[] elem;
  elem = p;
  sz = other.sz;
  return *this;
}

// move is kind of a shallow copy

/**
 * move constructor
 */
vec1::vec1(vec1 &&other) : sz{other.sz}, elem{other.elem} {
  other.sz = 0;
  other.elem = nullptr;
}

/**
 * move assignment
 */
vec1 &vec1::operator=(vec1 &&other) {
  delete[] elem;
  elem = other.elem;
  sz = other.sz;
  other.sz = 0;
  other.elem = nullptr;
  return *this;
}

/**
 * destructor
 */
vec1::~vec1() { delete[] elem; }

size_t vec1::size() { return sz; }

double vec1::get(size_t i) const { return elem[i]; }

void vec1::set(size_t i, double n) { elem[i] = n; }

double vec1::operator[](size_t i) const { return elem[i]; }

double &vec1::operator[](size_t i) { return elem[i]; }
