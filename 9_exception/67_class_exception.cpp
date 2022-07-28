#include <exception>
#include <iostream>

class Parent : public std::exception {
 public:
  virtual const char* what() const noexcept override { return "Parent!\n"; }
};

class Child : public Parent {
 public:
  const char* what() const noexcept override { return "Child!\n"; }
};

int func(int c) {
  if (c == 1)
    throw Parent();
  else if (c == 2)
    throw Child();
  return 0;
}

int main() {
  int c;
  std::cin >> c;

  // earlier hander 먼저 접근하기 때문에
  // child - parent 순서로 쓴다!
  try {
    func(c);
  } catch (Child& c) {
    std::cout << "Child Catch!" << std::endl;
    std::cout << c.what();
  } catch (Parent& p) {
    std::cout << "Parent Catch!" << std::endl;
    std::cout << p.what();
  }
}