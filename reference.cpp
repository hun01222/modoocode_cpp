#include<iostream>

void Code1(){
	int a=3;
	int& another_a=a;
	
	another_a=5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
}

int ChangeVal(int &p){
	p=3;
	return 0;
}

void Code2(){
	int number=5;
	
	std::cout << number << std::endl;
	ChangeVal(number);
	std::cout << number << std::endl;
}

int main()
{
	std::cout << "\n" << "레퍼런스 기본" << "\n";
	Code1();
	std::cout << "\n" << "함수 인자로 레퍼런스 받기" << "\n";
	Code2();
}