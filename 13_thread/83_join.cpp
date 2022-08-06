#include <pthread.h>
#include <iostream>
#include <thread>
using std::thread;

void func1() {
  for (int i=0; i<10; i++)
    std::cout << "쓰레드 1 작동중! \n";
}

void func2() {
  for (int i=0; i<10; i++)
    std::cout << "쓰레드 2 작동중! \n";
}

void func3() {
  for (int i=0; i<10; i++)
    std::cout << "쓰레드 3 작동중! \n";
}

int main() {
  thread t1(func1);
  thread t2(func2);
  thread t3(func3);
  
  // join 은 해당하는 쓰레드들이 실행을 종료하면 리턴하는 함수
  t1.join();
  t2.join();
  t3.join();
}