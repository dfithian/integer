#include <iostream>
#include <assert.h>
#include <stdexcept>
#include "../src/LargeNumber.h"

using namespace std;

void constructor_tests();
void addition_tests();
void subtraction_tests();

int main(){
	printf("Constructor module. Starting tests...\n");
	constructor_tests();
	printf("All constructor tests passed!\n");
	
	printf("Addition module. Starting tests...\n");
	addition_tests();
	printf("All addition tests passed!\n");
	
	printf("Subtraction module. Starting tests...\n");
	subtraction_tests();
	printf("All subtraction tests passed!\n");
	
	printf("All tests passed!\n");
	return 0;
}

void constructor_tests(){
	LargeNumber* a = new LargeNumber();
	printf("Test that LargeNumber() works...\n");
	assert(a->toString() == " 0");
	delete a;
	a = new LargeNumber(123456);
	printf("Test that LargeNumber(123456) works...\n");
	assert(a->toString() == " 123456");
	delete a;
	a = new LargeNumber(-123456);
	printf("Test that LargeNumber(-123456) works...\n");
	assert(a->toString() == "- 123456");
	delete a;
	
	int n[4] = { -1, 3, 2, 1};
	a = new LargeNumber(n, 4);
	printf("Test that LargeNumber({-1, 3, 2, 1}) works...\n");
	assert(a->toString() == "- 321");
	delete a;
	int m[4] = { 1, 4, 3, 2 };
	a = new LargeNumber(m, 4);
	printf("Test that LargeNumber({1, 4, 3, 2}) works...\n");
	assert(a->toString() == " 432");
	delete a;
	
	vector<int> p;
	p.push_back(LargeNumber::NEGATIVE_TAG);
	p.push_back(1);
	p.push_back(5);
	a = new LargeNumber(p);
	printf("Test that LargeNumber(vector<int>({-1, 1, 5})) works...\n");
	assert(a->toString() == "- 51");
	delete a;
}

//TODO: big numbers
//TODO: negative numbers, all combinations of lhs, rhs, and sum
void addition_tests(){
	LargeNumber a;
	a += LargeNumber(1);
	printf("Test that += LargeNumber(1) works...\n");
	assert(a.toString() == " 1");
	
	a = LargeNumber();
	++a;
	printf("Test that ++ LargeNumber works...\n");
	assert(a.toString() == " 1");
	
	a = LargeNumber(1) + LargeNumber(1);
	printf("Test that + LargeNumber works...\n");
	assert(a.toString() == " 2");
}

//TODO: big numbers
//TODO: negative numbers, all combinations of lhs, rhs, and sum
void subtraction_tests(){
	LargeNumber a(2);
	a -= LargeNumber(1);
	printf("Test that -= LargeNumber(1) works...\n");
	assert(a.toString() == " 1");
	
	a = LargeNumber(2);
	--a;
	printf("Test that -- LargeNumber works...\n");
	assert(a.toString() == " 1");
	
	a = LargeNumber(9) - LargeNumber(6);
	printf("Test that - LargeNumber works...\n");
	assert(a.toString() == " 3");
}