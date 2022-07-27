#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
 public:
  Vector(size_t size) : size_(size) {
    data_ = new T[size_];
    for(int i=0; i<size_; i++)
      data_[i] = 3;
  }
  const T& at(size_t index) const {
    if(index >= size_)
      throw std::out_of_range("vector 의 index 가 범위를 초가하였습니다.");
    return data_[index];
  }
  ~Vector() { delete[] data_; }

 private:
  T* data_;
  size_t size_;
};