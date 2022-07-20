#include<iostream>

namespace{
	int OnlyInThisFile() {} // static int func() 과 동일
	
	int only_in_this_file=0; // static int x 와 동일
}

int main(){
	OnlyInThisFile();
	only_in_this_file=3;
}