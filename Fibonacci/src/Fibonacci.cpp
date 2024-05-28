//============================================================================
// Name        : Fibonacci.cpp
// Author      : Philip Rexroth
// Version     :
// Copyright   : @2024 Philip Rexroth
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define LENGTH 47

int fibonacci(int i);

int main() {

	//f(n)=f(n-1)+f(n-2)
	int nums[LENGTH];

	for (int i=0; i<LENGTH; i++){
		nums[i]=fibonacci(i);
	}

	for (int j=0; j<LENGTH; j++){
		std::cout << nums[j] << std::endl;
	}

	return 0;
}

int fibonacci(int k){

	if (k<=0){return 0;};
	if (k==1){return 1;};

	return (fibonacci(k-1)+fibonacci(k-2));
}
