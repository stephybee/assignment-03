/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Diem-Huong Bui <diemhuongbui@csu.fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/*
 A series of programs including exception, template, STL (vector, set, map), and recursive/iterative functions.
 */

/*
References: 
http://stackoverflow.com/questions/10956543/gcd-function-in-c-sans-cmath-library
http://www.sanfoundry.com/cpp-program-find-fibonacci-numbers-iteration/
http://www.cplusplus.com/forum/beginner/21504/
http://www.cprogramming.com/tutorial/stl/stlmap.html
http://www.cplusplus.com/reference/vector/vector/clear/
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include "functions.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

/*part 1 --------------------------------------------------------------------------------------------------*/

	std::cout << "Enter number: ";
	int num, a;
	std::cin >> num;

	if (num % 2 == 0) //multiples will result in the first if and case listed
		a = 1;
	else if (num % 3 == 0)
		a = 2;
	else if (num % 5 == 0)
		a = 3;
	else if (num % 7 == 0)
		a = 4;

	try{
		f(a);
	}
	catch (const char * caught) {
		std::cout << "Wow, you caught a " << caught << "!\n";
	}

/*part 2 -------------------------------------------------------------------------------------------------*/

	double money;
	cout << "How much money would you like to invest? ";
	cin >> money;
	if (money < 0) throw "Invalid amount.";
	cout << "You invested $" << money << " and earned a total of $" << invest(money) + money << "." << endl;

/*part 3 -------------------------------------------------------------------------------------------------*/

	//vector 
	int total;
	cout << "How many items would you like to list? ";
	cin >> total;

	if (total < 0) throw "Invalid number of items.";
	std::vector < std::string > list(total);
	cout << "Please enter the items: " << endl;
	for (int i = 0; i < total; i++){
		cin >> list[i];
	}

	cout << "Your list of items includes: " << endl;
	for (int i = 0; i < total; i++){
		cout << list[i] << endl;
	}

	cout << "Would you like to add another item? (y/n) ";
	char add;
	cin >> add;
	if (add == 'y' || add == 'Y'){
		do {
			cout << "What item would you like to add?" << endl;
			std::string item;
			cin >> item;
			list.push_back(item);
			cout << "Would you like to add another item? (y/n) ";
			cin >> add;
		} while (add == 'y' || add == 'Y');
		cout << "Your list now contains: " << endl;
		for (int i = 0; i <= total; i++)
			cout << list[i] << endl;
	}
	cout << "Would you like to clear your list? (y/n) ";
	char clear;
	cin >> clear;
	if (clear == 'y' || clear == 'Y'){
		list.clear();
		cout << "Your list is cleared!" << endl;
	}

	//set
	int setLimit;
	cout << "How many numbers would you like to enter? ";
	cin >> setLimit;
	cout << "Enter numbers to be singled out and sorted in ascending order." << endl;

	std::set<int> s = {};
	int index;
	for (int i = 0; i < setLimit; i++){
		cin >> index;
		s.insert(index);
	}

	cout << "Your organized set of numbers is: ";
	for (int e : s)
		cout << e << " ";
	cout << endl;

	//map
	std::map<std::string, int> animalsTracker;
	cout << "Name an animal and include its quantity." << endl;
	std::string animal;
	int quantity;
	char choice;

	do {
		cin >> animal;
		cin >> quantity;
		animalsTracker[animal] = quantity;
		cout << "Would you like to add another animal and quantity? (y/n) ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');

		cout << "Your animal list includes: " << endl;
	for (std::pair<std::string, int> e : animalsTracker)
			cout << e.second << " " << e.first << "s " << endl;

/*part 4 -------------------------------------------------------------------------------------------------*/

	//test gcd
	cout << "The greatest common denominator of 4 and 2 is " << gcd(4, 2) << "." << endl;
	cout << "The greatest common denominator of 0 and 2 is " << gcd(0, 2) << "." << endl;
	cout << "The greatest common denominator of 2 and 0 is " << gcd(2, 0) << "." << endl;
	cout << "The greatest common denominator of -7 and 14 is " << gcd(-7, 14) << "." << endl;

	//test fib
	cout << "The 1st Fibonacci number is " << fib(1) << "." << endl;
	cout << "The 2nd Fibonacci number is " << fib(2) << "." << endl;
	cout << "The 3rd Fibonacci number is " << fib(3) << "." << endl;
	cout << "The 4th Fibonacci number is " << fib(4) << "." << endl;
	cout << "The 5th Fibonacci number is " << fib(5) << "." << endl;

	//test pow
	cout << "7 to the 4th power is " << pow(7, 4) << "." << endl;

	//test tri
	cout << "The triangular number of 3 is " << tri(3) << "." << endl;
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3 - i; j++)
			cout << " ";
		for (int j = 1; j <= i; j++)
			cout << "* ";
		cout << endl;
	}

	//test tri(triangular)
	int triangular;
	cout << "Enter an n to calculate the nth triangular number: ";
	std::cin >> triangular;
	cout << "The triangular number of " << triangular << " is " << tri(triangular) << "." << endl;

	for (int i = 1; i <= triangular; i++){
		for (int j = 1; j <= triangular - i; j++)
			cout << " ";
		for (int j = 1; j <= i; j++)
			cout << "* ";
		cout << endl;
	}

/*part 5 -------------------------------------------------------------------------------------------------*/

	cout << "The greatest common denominator of 4 and 2 using the iterative function is " << gcd_iter(4, 2) << "." << endl;
	cout << "The greatest common denominator of 0 and 2 using the iterative function is " << gcd_iter(0, 2) << "." << endl;
	cout << "The greatest common denominator of 2 and 0 using the iterative function is " << gcd_iter(2, 0) << "." << endl;
	cout << "The greatest common denominator of -7 and 14 using the iterative function is " << gcd_iter(-7, 14) << "." << endl;

	cout << "The 1st Fibonacci number using the iterative function is " << fib_iter(1) << "." << endl;
	cout << "The 2nd Fibonacci number using the iterative function is " << fib_iter(2) << "." << endl;
	cout << "The 3rd Fibonacci number using the iterative function is " << fib_iter(3) << "." << endl;
	cout << "The 4th Fibonacci number using the iterative function is " << fib_iter(4) << "." << endl;
	cout << "The 5th Fibonacci number using the iterative function is " << fib_iter(5) << "." << endl;

	cout << "7 to the 4th power using the iterative function is " << pow_iter(7, 4) << "." << endl;
	
	cout << "The triangular number of 3 using the iterative function is " << tri_iter(3) << "." << endl;

	system("pause");
	return 0;
}
