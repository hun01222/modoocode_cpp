#include<iostream>

class Animal{
 private: // 1 space 들여쓰기 (google c++ stytle guide)
  int food; // 2 space 들여쓰기
  int weight;

 public:
  void SetAnimal(int _food, int _weight){
	  food=_food;
	  weight=_weight;
  }
  void IncreaseFood(int inc){
	  food+=inc;
	  weight+=(inc/3);
  }
  void ViewStat(){
	  std::cout << "이 동물의 food : " << food << std::endl;
	  std::cout << "이 동물의 weight : " <<weight << std::endl;
  }
};

int main(){
	Animal animal;
	animal.SetAnimal(100, 50);
	animal.IncreaseFood(30);
	
	animal.ViewStat();
}