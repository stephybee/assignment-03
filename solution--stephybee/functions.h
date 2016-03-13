#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>

std::string f(int a) {
	switch (a) {
	case 1:
		throw "grape";
		break;
	case 2:
		throw "strawberry";
		break;
	case 3:
		throw "melon";
		break;
	case 4:
		throw "banana";
		break;
	}
}

template <typename T>
T invest(T a) {
	a = 6 + a / 8;
	return a;
}

int gcd(int a, int b) {
	if (b == 0) return abs(a);
	if (a == 0) return abs(b);
	if (a < 0)
		a = abs(a);
	if (b < 0)
		b = abs(b);
	if (a > b)
		return gcd(a - b, b);
	if (b > a)
		return gcd(a, b - a);
}

int fib(int n) {
	if (n < 0) throw "Error, invalid number.";
	if (n == 1) return 1;
	if (n == 2) return 1;
	return fib(n - 1) + fib(n - 2);
}

int pow(int b, int e) {
	if (e < 0) throw "Negative exponent.";
	if (e == 0) return 1;
	return b * pow(b, e - 1);
}

int tri(int n) {
	if (n < 0) throw "Invalid input.";
	if (n == 0) return 0;
	return n + tri(n - 1);
}

int gcd_iter(int a, int b){ 
	if (a == b)
		return a;
	else{
		int num;
		while (b != 0){
			num = a%b;
			a = b;
			b = num;
		}
		return abs(a);
	}
}

int fib_iter(int n){
	if (n < 0) throw "Invalid number.";
	if (n == 1 || n == 2) return 1;
	else{
		int num1 = 1, num2 = 1, fibNum = 1;
		for (int i = 3; i <= n; i++){
			fibNum = num2 + num1;
			num1 = num2;
			num2 = fibNum;
		}
		return fibNum;
	}
}

int pow_iter(int b, int e){
	if (e < 0) throw "Negative exponent.";
	int total = 1;
	for (int i = 1; i <= e; i++){
		total *= b;
	}
	return total;
}

int tri_iter(int n){
	if (n <= 0) throw "Invalid number.";
	int triNum = 0;
	for (int i = 1; i <= n; i++){
		triNum += i;
	}
	return triNum;
}
