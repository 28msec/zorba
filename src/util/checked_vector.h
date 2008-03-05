#ifndef ZORBA_CHECKED_VECTOR_H
#define ZORBA_CHECKED_VECTOR_H

#include <vector>

namespace zorba {
  
  template<typename T> class checked_vector : public std::vector<T> {
  public:
    checked_vector () {}
    checked_vector (int n) : std::vector<T> (n) {}
    checked_vector (const std::vector<T> &other)
      : std::vector<T> (other)
    {}
    checked_vector (const checked_vector<T> &other)
      : std::vector<T> (other)
    {}
    checked_vector<T> &operator= (const std::vector<T> &other) {
      std::vector<T>::operator= (other);
      return *this;
    }
    checked_vector<T> &operator= (const checked_vector<T> &other) {
      std::vector<T>::operator= (other);
      return *this;
    }
#ifndef NDEBUG
    T &operator[] (typename std::vector<T>::size_type i) { return std::vector<T>::at (i); }
    const T &operator[] (typename std::vector<T>::size_type i) const { return std::vector<T>::at (i); }
#endif
  };

}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
