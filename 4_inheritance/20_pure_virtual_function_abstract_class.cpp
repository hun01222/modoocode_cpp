#include <iostream>

class Animal{ // 추상 클래스: 순수 가상 함수를 포함하는 class
 public:
  Animal() {}
  virtual ~Animal() {}
  virtual void speak()=0; // 순수 가상 함수: 반드시 override 되어야 되는 함수
};
class Dog : public Animal{
 public:
  Dog() : Animal() {}
  void speak() override {std::cout << "왈왈" << std::endl;}
};
class Cat : public Animal{
 public:
  Cat() : Animal() {}
  void speak() override {std::cout << "야옹야옹" << std::endl;}
};

int main(){
  Animal *dog=new Dog(); // Animal 객체 생성 불가능
  Animal *cat=new Cat();

  dog->speak();
  cat->speak();
}