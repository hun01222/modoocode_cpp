#include<iostream>

class Marine{
  static int total_marine_num;
  const static int i=0;
  
  int hp;
  int coord_x, coord_y;
  bool is_dead;
  
  const int default_damage;
  
 public:
  Marine();
  Marine(int x, int y);
  Marine(int x, int y, int default_damage);
  
  int Attack() const;
  Marine& BeAttacked(int damage_earn);
  void Move(int x, int y);
  
  void ShowStatus();
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num=0;
void Marine::show_total_marine(){
  std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) { total_marine_num++; }
Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) { total_marine_num++; }
Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) { total_marine_num++; }

void Marine::Move(int x, int y){
  coord_x=x;
  coord_y=y;
}
int Marine::Attack() const { return default_damage; }
Marine& Marine::BeAttacked(int damage_earn){
  hp-=damage_earn;
  if(hp<=0) is_dead=true;
  
  return *this;
}
void Marine::ShowStatus(){
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void CreateMarine(){
  Marine marine3(10, 10, 4);
  marine3.ShowStatus();
}

int main(){
  Marine marine1(2, 3, 10);
  marine1.ShowStatus();
  Marine::show_total_marine();
  
  Marine marine2(3, 5, 10);
  marine2.ShowStatus();
  Marine::show_total_marine();
  
  CreateMarine();
  
  std::cout << std::endl << "마린1이 마린2를 두 번 공격! " << std::endl;
  marine2.BeAttacked(marine1.Attack()).BeAttacked(marine1.Attack());
  
  marine1.ShowStatus();
  marine2.ShowStatus();
}