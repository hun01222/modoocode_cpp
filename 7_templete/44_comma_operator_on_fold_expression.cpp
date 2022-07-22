#include<iostream>

class A{
 public:
  void do_something(int x) const {
    std::cout << "Do something with " << x << std::endl;
  }
};

template <typename T, typename... Ints>
void do_many_things(const T &t, Ints... nums){
  (t.do_something(nums), ...);
}

int main(){
  A a;
  do_many_things(a, 1, 3, 2, 4);
}