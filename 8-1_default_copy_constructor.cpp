#include<string.h>
#include<iostream>

class PhotonCannon{
  int hp, shield;
  int coord_x, coord_y;
  int damage;
  
  char* name;
  
 public:
  PhotonCannon(int x, int y);
  PhotonCannon(int x, int y, const char* cannon_name);
  PhotonCannon(const PhotonCannon& pc);
  ~PhotonCannon();
  
  void ShowStatus();
};

PhotonCannon::PhotonCannon(int x, int y){
  hp=shield=100;
  coord_x=x;
  coord_y=y;
  damage=20;
  
  name=NULL;
}

PhotonCannon::PhotonCannon(const PhotonCannon& pc){
  std::cout << "복사 생성자 호출 !" << std::endl;
  hp=pc.hp;
  shield=pc.shield;
  coord_x=pc.coord_x;
  coord_y=pc.coord_y;
  damage=pc.damage;
  
  name=new char[strlen(pc.name)+1]; // deep copy: 다른 메모리에 동적할당해서 그 내용만 복사 cf) shallow copy: 단순 대입
  strcpy(name, pc.name);
}

PhotonCannon::PhotonCannon(int x, int y, const char* cannon_name){
  hp=shield=100;
  coord_x=x;
  coord_y=y;
  damage=20;
  
  name=new char[strlen(cannon_name)+1];
  strcpy(name, cannon_name);
}

PhotonCannon::~PhotonCannon(){
  if(name) delete[] name;
}

void PhotonCannon::ShowStatus(){
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main(){
  PhotonCannon pc1(3, 3, "Cannon");
  PhotonCannon pc2=pc1;
  
  pc1.ShowStatus();
  pc2.ShowStatus();
  
  return 0;
}