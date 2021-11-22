#include <iostream>
#include <assert.h>
#include <stdexcept>
#include "../src/Integer.h"

using namespace std;

void constructor_tests();
void addition_tests();
void subtraction_tests();
void multiplication_tests();
void division_tests();
void modulo_tests();

int main(){
    printf("Constructor module. Starting tests...\n");
    constructor_tests();
    printf("All constructor tests passed!\n\n");
    
    printf("Addition module. Starting tests...\n");
    addition_tests();
    printf("All addition tests passed!\n\n");
    
    printf("Subtraction module. Starting tests...\n");
    subtraction_tests();
    printf("All subtraction tests passed!\n\n");
    
    printf("Multiplication module. Starting tests...\n");
    multiplication_tests();
    printf("All multiplication tests passed!\n\n");
    
    printf("Division module. Starting tests...\n");
    division_tests();
    printf("All division tests passed!\n\n");
    
    printf("Modulo module. Starting tests...\n");
    modulo_tests();
    printf("All modulo tests passed!\n\n");
    
    printf("All tests passed!\n\n");
    return 0;
}

void constructor_tests(){
    Integer* a = new Integer();
    printf("Test that Integer() works...\n");
    assert(a->toString() == "0");
    delete a;
    a = new Integer((unsigned int)123456);
    printf("Test that Integer(123456) works...\n");
    assert(a->toString() == "123456");
    delete a;
    a = new Integer(-123456);
    printf("Test that Integer(-123456) works...\n");
    assert(a->toString() == "-123456");
    delete a;
    a = new Integer((unsigned short)12);
    printf("Test that Integer((unsigned short)12) works...\n");
    assert(a->toString() == "12");
    delete a;
    a = new Integer((short)-12);
    printf("Test that Integer((short)-12) works...\n");
    assert(a->toString() == "-12");
    delete a;
    a = new Integer((unsigned long)1234567890);
    printf("Test that Integer((unsigned long)1234567890) works...\n");
    assert(a->toString() == "1234567890");
    delete a;
    a = new Integer((long)-1234567890);
    printf("Test that Integer((long)-1234567890) works...\n");
    assert(a->toString() == "-1234567890");
    delete a;
    
    int n[4] = { -1, 3, 2, 1};
    a = new Integer(n, 4);
    printf("Test that Integer({-1, 3, 2, 1}) works...\n");
    assert(a->toString() == "-321");
    delete a;
    int m[4] = { 1, 4, 3, 2 };
    a = new Integer(m, 4);
    printf("Test that Integer({1, 4, 3, 2}) works...\n");
    assert(a->toString() == "432");
    delete a;

    string s = "1234556709159591230592856";
    a = new Integer(s);
    printf("Test that Integer(\'1234556709159591230592856\') works...\n");
    assert(a->toString() == "1234556709159591230592856");
    delete a;
    a = new Integer(s.c_str());
    printf("Second test that Integer(\'1234556709159591230592856\') works...\n");
    assert(a->toString() == "1234556709159591230592856");
    delete a;
    s = "-" + s;
    a = new Integer(s);
    printf("Test that Integer(\'-1234556709159591230592856\') works...\n");
    assert(a->toString() == "-1234556709159591230592856");
    delete a;
    a = new Integer(s.c_str());
    printf("Second test that Integer(\'-1234556709159591230592856\') works...\n");
    assert(a->toString() == "-1234556709159591230592856");
    delete a;
    
    vector<int> p;
    p.push_back(1);
    p.push_back(5);
    p.push_back(6);
    a = new Integer(p);
    printf("Test that Integer(vector<int>({1, 5, 6})) works...\n");
    assert(a->toString() == "651");
    delete a;
}

void addition_tests(){
    Integer a;
    a += Integer(1);
    printf("Test that += Integer(1) works...\n");
    assert(a.toString() == "1");
    
    a = Integer();
    ++a;
    printf("Test that ++ Integer works...\n");
    assert(a.toString() == "1");
    
    a = Integer(1) + Integer(1);
    printf("Test that + Integer works...\n");
    assert(a.toString() == "2");
    
    a = Integer(12345) + Integer((unsigned long)292929123);
    assert(a.toString() == "292941468");
    
    a = Integer(123412345) + Integer(292929123);
    assert(a.toString() == "416341468");

    a = Integer(-12345) + Integer((long)-292929123);
    assert(a.toString() == "-292941468");

    a = Integer((long)-292929123) + Integer(-12345);
    assert(a.toString() == "-292941468");
    
    a = Integer(12345) + Integer((long)-292929123);
    assert(a.toString() == "-292916778");
    
    a = Integer((long)-292929123) + Integer(12345);
    assert(a.toString() == "-292916778");
    
    a = Integer((long)292929123) + Integer(-12345);
    assert(a.toString() == "292916778");
}

void subtraction_tests(){
    Integer a(2);
    a -= Integer(1);
    printf("Test that -= Integer(1) works...\n");
    assert(a.toString() == "1");
    
    a = Integer(2);
    --a;
    printf("Test that -- Integer works...\n");
    assert(a.toString() == "1");
    
    a = Integer(9) - Integer(6);
    printf("Test that - Integer works...\n");
    assert(a.toString() == "3");
    
    a = Integer(12345) - Integer((unsigned long)292929123);
    assert(a.toString() == "-292916778");
    
    a = Integer(123412345) - Integer(292929123);
    assert(a.toString() == "-169516778");

    a = Integer(-12345) - Integer((long)-292929123);
    assert(a.toString() == "292916778");

    a = Integer((long)-292929123) - Integer(-12345);
    assert(a.toString() == "-292916778");
    
    a = Integer(12345) - Integer((long)-292929123);
    assert(a.toString() == "292941468");
    
    a = Integer((long)-292929123) - Integer(12345);
    assert(a.toString() == "-292941468");
    
    a = Integer((long)292929123) - Integer(-12345);
    assert(a.toString() == "292941468");
}

void multiplication_tests(){
    Integer a(2);
    a *= Integer(1);
    printf("Test that *= Integer(1) works...\n");
    assert(a.toString() == "2");
    
    a = Integer(9) * Integer(6);
    printf("Test that * Integer works...\n");
    assert(a.toString() == "54");
    
    a = Integer(12345) * Integer((unsigned long)29292);
    assert(a.toString() == "361609740");

    a = Integer(-12345) * Integer((long)-29292);
    assert(a.toString() == "361609740");

    a = Integer((long)-29292) * Integer(-12345);
    assert(a.toString() == "361609740");
    
    a = Integer(12345) * Integer((long)-29292);
    assert(a.toString() == "-361609740");
    
    a = Integer((long)-29292) * Integer(12345);
    assert(a.toString() == "-361609740");
    
    a = Integer((long)29292) * Integer(-12345);
    assert(a.toString() == "-361609740");
}

void division_tests(){
    Integer a(2);
    a /= Integer(1);
    printf("Test that /= Integer(1) works...\n");
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "2");
    
    a = Integer(9) / Integer(3);
    printf("Test that / Integer works...\n");
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "3");
    
    a = Integer(12345) / Integer((unsigned long)29292);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "0");

    a = Integer(-12345) / Integer((long)-29292);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "0");

    a = Integer((long)-29292) / Integer(-12345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "2");
    
    a = Integer((long)-29292) / Integer(12345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-2");
    
    a = Integer((long)29292) / Integer(-12345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-2");
    
    a = Integer(292929123) / Integer(2345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "124916");
    
    a = Integer(292929123) / Integer(-2345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-124916");
    
    a = Integer(-292929123) / Integer(2345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-124916");
    
    a = Integer(-292929123) / Integer(-2345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "124916");
    
    a = Integer((long)-292929123) / Integer(9929);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-29502");
    
    a = Integer((long)292929123) / Integer(-9929);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-29502");
}

void modulo_tests(){
    Integer a(2);
    a %= Integer(1);
    printf("Test that mod= Integer(1) works...\n");
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "0");
    
    a = Integer(9) % Integer(5);
    printf("Test that mod Integer works...\n");
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "4");
    
    a = Integer(12345) % Integer((unsigned long)29292);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "12345");

    a = Integer(-12345) % Integer((long)-29292);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "12345");

    a = Integer((long)-29292) % Integer(-12345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "4602");
    
    a = Integer((long)-29292) % Integer(12345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-4602");
    
    a = Integer((long)29292) % Integer(-12345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-4602");
    
    a = Integer(292929123) % Integer(2345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "1103");
    
    a = Integer(292929123) % Integer(-2345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-1103");
    
    a = Integer(-292929123) % Integer(2345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-1103");
    
    a = Integer(-292929123) % Integer(-2345);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "1103");
    
    a = Integer((long)-292929123) % Integer(9929);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-3765");
    
    a = Integer((long)292929123) % Integer(-9929);
    printf("%s", a.debug().c_str()); printf("\n");
    assert(a.toString() == "-3765");
}