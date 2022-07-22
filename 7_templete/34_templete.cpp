#include<iostream>
#include<string>

template<typename T>
// template<class T> 도 가능

class Vector{
  T *data;
  int capacity;
  int length;

 public:
  // 템플릿 인스턴스화
  // typedef T value_type;
  // Vector(int n=1) : data(new int[n]), capacity(n), length(0) {}

  Vector(int n=1) : data(new T[n]), capacity(n), length(0) {}

  void push_back(T s){
    if(capacity<=length){
      T *temp=new T[capacity*2];
      for(int i=0; i<length; i++)
        temp[i]=data[i];
      delete[] data;
      data=temp;
      capacity*=2;
    }

    data[length]=s;
    length++;
  }

  T operator[](int i) {return data[i];}

  void remove(int x){
    for(int i=x+1; i<length; i++)
      data[i-1]=data[i];
    length--;
  }
  int size() {return length;}

  ~Vector(){
    if(data)
      delete[] data;
  }
};

int main(){
  Vector<int> int_vec;
  int_vec.push_back(3);
  int_vec.push_back(2);

  std::cout << "------- int vector -------" << std::endl;
  std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

  Vector<std::string> str_vec;
  str_vec.push_back("hello");
  str_vec.push_back("world");

  std::cout << "------- std::string vector -------" << std::endl;
  std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << int_vec[1] << std::endl;
}