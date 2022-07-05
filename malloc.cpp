#include<iostream>

void Code1(){
	int* p=new int;
	*p=10;
	
	std::cout << *p << std::endl;
	
	delete p;
}

void Code2(){
	int arr_size;
	std::cout < "array size : ";
	std::cin >> arr_size;
	int* list=new int[arr_size];
	for(itn i=0; i<arr_size; i++)
		std::cin >> list[i];
	for(int i=0; i<arr_size; i++)
		std::cout << i << "th element of list : " << list[i] << std::endl;
	delete[] list;
}

int main(){
	std::cout << "\n" << "new와 delete" << "\n";
	Code1();
	std::cout << "\n" << "new로 배열 할당" << "\n";
	Code2();
}