#include <iostream>
#include <stdexcept>
#include "LargeNumber.h"
using namespace std;

/*constructors and assignment operators*/
LargeNumber::LargeNumber(){
	m_number = new int[1];
	m_number[0] = 0;
	m_size = 1;
}

LargeNumber::LargeNumber(int n){
	if (n != 0){
		int m = n;
		int i = 0;
		while (m != 0) {
			m /= 10;
			i++;
		}
		m_number = new int[i];
		i = 0;
		while (n != 0) {
			m_number[i] = n % 10;
			n /= 10;
			i++;
		}
		m_size = i;
	} else {
		//define 0 as the only entry in an array of length 1
		m_number = new int[1];
		m_number[0] = 0;
		m_size = 1;
	}
}
	
LargeNumber::LargeNumber(int* n, int s){
	if (s > 0) {
		//copy
  		m_number = new int[s];
  		for (int i = 0; i < s; i++){
  		  	m_number[i] = n[s - i - 1];
  		}
  		m_size = s;
  	} else {
  		m_number = new int[1];
  		m_number[0] = 0;
  		m_size = 1;
  	}
}

LargeNumber::~LargeNumber(){
}

LargeNumber & LargeNumber::operator=(const LargeNumber &rhs){
  	if (m_number != NULL) delete m_number;
  	//copy
  	m_number = new int[rhs.m_size];
  	for (int i = 0; i < rhs.m_size; i++){
  	  m_number[i] = rhs.m_number[i];
  	}
  	m_size = rhs.m_size;
}

LargeNumber & LargeNumber::operator=(const int &rhs){
	if (rhs != 0){
		int temp = rhs;
  		int i = digits(temp);
  		if (m_number != NULL) delete m_number;
  		//copy digit by digit
  		m_number = new int[i];
  		for (int j = 0; j < i; j++){
  			m_number[j] = temp % 10;
    		temp /= 10;
    	}
  		m_size = i;
  		return *this;
  	} else {
  		if (m_number != NULL) delete m_number;
  		//define 0
		m_number = new int[1];
		m_number[0] = 0;
		m_size = 1;
	}
}
/*end construction and assignment operators*/



/*incremental operators*/
LargeNumber & LargeNumber::operator++(){
	*this += 1;
	return *this;
}

LargeNumber LargeNumber::operator++(int){
	LargeNumber p(*this);
	operator++();
	return p;
}

LargeNumber & LargeNumber::operator--(){
	*this -= 1;
	return *this;
}

LargeNumber LargeNumber::operator--(int){
	LargeNumber p(*this);
	operator--();
	return p;
}
/*end incremental operators*/



/*large int operations*/
LargeNumber & LargeNumber::operator+=(const LargeNumber &rhs){
	if (rhs.m_number == NULL) return *this;
	if (m_number == NULL) {
		m_number = rhs.m_number;
		m_size = rhs.m_size;
		return *this;
	}
	LargeNumber p;
	if (m_size >= rhs.m_size){
		//grow the array to the max m_size
		p.m_number = new int[m_size + 1];
		p.m_size = m_size + 1;
		for (int i = 0; i < m_size + 1; i++){
			p.m_number[i] = 0;
		}
		for (int i = 0; i < rhs.m_size; i++){
			p.m_number[i] = rhs.m_number[i] + m_number[i];
		}
		for (int i = rhs.m_size; i < m_size; i++){
			p.m_number[i] = m_number[i];
		}
  	} else {
  		//grow the array to the max m_size
  		p.m_number = new int[rhs.m_size + 1];
  		p.m_size = rhs.m_size + 1;
  		for (int i = 0; i < rhs.m_size; i++){
  			p.m_number[i] = 0;
  		}
  		for (int i = 0; i < m_size; i++){
  			p.m_number[i] = rhs.m_number[i] + m_number[i];
  		}
  		for (int i = m_size; i < rhs.m_size; i++){
  			p.m_number[i] = rhs.m_number[i];
  	  	}
  	}
  	int remainder;
  	for (int i = 0; i < p.m_size - 1; i++){
  		remainder = p.m_number[i];
  		p.m_number[i] %= 10;
  		remainder /= 10;
  		p.m_number[i + 1] += remainder;
  	}
  	//find out how small to shrink the array
  	int j = p.m_size - 1;
  	while (p.m_number[j] == 0 && j != 0){
  		j--;
  	}
  	m_size = j + 1;
  	delete m_number;
  	//shrink the array
  	m_number = new int[m_size];
  	for (int i = 0; i < m_size; i++){
  		m_number[i] = p.m_number[i];
  	}
  	return *this;
}

LargeNumber & LargeNumber::operator-=(const LargeNumber &rhs){
	if (rhs.m_number == NULL) return *this;
	if (m_number == NULL) {
		m_number = rhs.m_number;
		m_size = rhs.m_size;
		return *this;
	}
  	if (*this < rhs){
  		throw new invalid_argument("Sum cannot be negative");
  	}
  	LargeNumber p;
  	p.m_number = new int[m_size];
  	p.m_size = m_size;
  	for (int i = 0; i < m_size; i++){
  		p.m_number[i] = m_number[i];
  	}
  	for (int i = 0; i < rhs.m_size; i++){
  		p.m_number[i] -= rhs.m_number[i];
  	}
  	for (int i = 0; i < m_size - 1; i++){
    	if (p.m_number[i] < 0){
      		p.m_number[i] += 10;
      		p.m_number[i + 1]--;
    	}
  	}
  	//find out how small to shrink the array
  	int j = p.m_size - 1;
  	while (p.m_number[j] == 0 && j != 0){
  		j--;
  	}
  	m_size = j + 1;
  	delete m_number;
  	//shrink the array
  	m_number = new int[m_size];
  	for (int i = 0; i < m_size; i++){
  		m_number[i] = p.m_number[i];
  	}
  	return *this;
}

LargeNumber & LargeNumber::operator*=(const LargeNumber &rhs){
	if (rhs.m_number == NULL) return *this;
	if (m_number == NULL){
		m_number = rhs.m_number;
		m_size = rhs.m_size;
		return *this;
	}
	if (rhs == 0){
		m_number = new int[1];
		m_number[0] = 0;
		m_size = 1;
		return *this;
	}
	if (*this == 0) return *this;
	LargeNumber p;
	//grow the array to the max m_size
  	p.m_number = new int[m_size + rhs.m_size];
  	for (int i = 0; i < m_size + rhs.m_size; i++){
		p.m_number[i] = 0;
  	}
  	p.m_size = m_size + rhs.m_size;
  	//do multiplication
  	for (int i = 0; i < rhs.m_size; i++){
  	  	for (int j = 0; j < m_size; j++){
      		p.m_number[j + i] += (m_number[j] * rhs.m_number[i]);
    	}
  	}
  	//carry remainders (ensure single digits)
  	int remainder;
  	for (int i = 0; i < p.m_size - 1; i++){
    	remainder = p.m_number[i];
    	p.m_number[i] %= 10;
    	remainder /= 10;
    	p.m_number[i + 1] += remainder;
  	}
  	//find out how small to shrink the array
  	int j = p.m_size - 1;
  	while (p.m_number[j] == 0 && j != 0){
  		j--;
  	}
  	m_size = j + 1;
  	delete m_number;
  	//shrink the array
  	m_number = new int[m_size];
  	for (int i = 0; i < m_size; i++){
  		m_number[i] = p.m_number[i];
  	}
  	return *this;
}

LargeNumber & LargeNumber::operator/=(const LargeNumber &rhs){
	if (rhs.m_number == NULL) return *this;
	if (m_number == NULL){
		m_number = rhs.m_number;
		m_size = rhs.m_size;
		return *this;
	}
	if (rhs == 0){
		throw new invalid_argument("Cannot divide by zero");
	}
	if (*this == 0) return *this;
	if (*this < rhs){
		m_number = new int[1];
		m_number[0] = 0;
		m_size = 1;
		return *this;
	}
	LargeNumber p;
	p.m_number = new int[m_size];
	p.m_size = m_size;
	for (int i = 0; i < p.m_size; i++){
		p.m_number[i] = m_number[i];
	}
	//make a quotient
	LargeNumber d;
	//grow the quotient
	for (d; p >= rhs; p -= rhs, d++){  
		//d grows by one and p decrements by rhs on each loop
		//loop is broken when p < rhs
	}
	//find out how small to shrink the array
	int j = d.m_size - 1;
  	while (d.m_number[j] == 0 && j != 0){
  		j--;
  	}
  	m_size = j + 1;
  	delete m_number;
  	//shrink the array
  	m_number = new int[m_size];
  	for (int i = 0; i < m_size; i++){
  		m_number[i] = d.m_number[i];
  	}
  	return *this;
}

LargeNumber & LargeNumber::operator%=(const LargeNumber &rhs){
	if (rhs.m_number == NULL) return *this;
	if (m_number == NULL){
		m_number = rhs.m_number;
		m_size = rhs.m_size;
		return *this;
	}
	if (rhs == 0){
		throw new invalid_argument("Cannot divide by zero");
	}
	if (*this == 0) return *this;
	if (*this < rhs){
		return *this;
	}
	LargeNumber p;
	p.m_number = new int[m_size];
	p.m_size = m_size;
	for (int i = 0; i < p.m_size; i++){
		p.m_number[i] = m_number[i];
	}
	//make a quotient
	LargeNumber d;
	//grow the quotient
	for (d; p >= rhs; p -= rhs, d++){
		//d grows by one and p decrements by rhs on each loop
		//loop is broken when p < rhs
	}
	//find out how small to shrink the array
	int j = p.m_size - 1;
	while (p.m_number[j] == 0 && j != 0){
		j--;
	}
	m_size = j + 1;
	delete m_number;
	//shrink the array
	m_number = new int[m_size];
	for (int i = 0; i < m_size; i++){
		m_number[i] = p.m_number[i];
	}
	return *this;
}

const LargeNumber LargeNumber::operator+(const LargeNumber &other) const{
	if (other.m_number == NULL) return *this;
  	if (m_number == NULL) return other;
  	LargeNumber p;
  	if (m_size >= other.m_size){
  		p.m_number = new int[m_size + 1];
  		p.m_size = m_size + 1;
  		for (int i = 0; i < p.m_size; i++){
  			p.m_number[i] = 0;
  		}
  		for (int i = 0; i < other.m_size; i++){
  			p.m_number[i] = m_number[i] + other.m_number[i];
  		}
  		for (int i = other.m_size; i < m_size; i++){
  			p.m_number[i] = m_number[i];
  		}
  	}else{
  		p.m_number = new int[other.m_size + 1];
  		p.m_size = other.m_size + 1;
  		for (int i = 0; i < p.m_size; i++){
  			p.m_number[i] = 0;
  		}
  		for (int i = 0; i < m_size; i++){
  			p.m_number[i] = m_number[i] + other.m_number[i];
  		}
  		for (int i = m_size; i < other.m_size; i++){
  			p.m_number[i] = other.m_number[i];
  		}
  	}
  	int remainder;
  	for (int i = 0; i < p.m_size - 1; i++){
  		remainder = p.m_number[i];
  		p.m_number[i] %= 10;
  		remainder /= 10;
  		p.m_number[i + 1] += remainder;
  	}
  	//find out how small to shrink the array
  	int j = p.m_size - 1;
  	while (p.m_number[j] == 0 && j != 0){
  		j--;
  	}
  	LargeNumber n;
  	n.m_size = j + 1;
  	n.m_number = new int[n.m_size];
  	for (int i = 0; i < n.m_size; i++){
  		n.m_number[i] = p.m_number[i];
  	}
  	return n;
}

const LargeNumber LargeNumber::operator-(const LargeNumber &other) const{
  	if (other.m_number == NULL) return *this;
	if (m_number == NULL) return other;
  	if (*this < other){
  		throw new invalid_argument("Sum cannot be negative");
  	}
  	LargeNumber p;
  	p.m_number = new int[m_size];
  	p.m_size = m_size;
  	for (int i = 0; i < m_size; i++){
  		p.m_number[i] = m_number[i];
  	}
  	for (int i = 0; i < other.m_size; i++){
  		p.m_number[i] -= other.m_number[i];
  	}
  	for (int i = 0; i < m_size - 1; i++){
    	if (p.m_number[i] < 0){
      		p.m_number[i] += 10;
      		p.m_number[i + 1]--;
    	}
  	}
  	//find out how small to shrink the array
  	int j = p.m_size - 1;
  	while (p.m_number[j] == 0 && j != 0){
  		j--;
  	}
  	LargeNumber n;
  	n.m_size = j + 1;
  	n.m_number = new int[n.m_size];
  	for (int i = 0; i < n.m_size; i++){
  		n.m_number[i] = p.m_number[i];
  	}
  	return n;
}

const LargeNumber LargeNumber::operator*(const LargeNumber &other) const{
  	if (other.m_number == NULL) return *this;
	if (m_number == NULL) return other;
	if (other == 0) return other;
	if (*this == 0) return *this;
	LargeNumber p;
	//grow the array to the max m_size
  	p.m_number = new int[m_size + other.m_size];
  	for (int i = 0; i < m_size + other.m_size; i++){
		p.m_number[i] = 0;
  	}
  	p.m_size = m_size + other.m_size;
  	//do multiplication
  	for (int i = 0; i < other.m_size; i++){
  	  	for (int j = 0; j < m_size; j++){
      		p.m_number[j + i] += (m_number[j] * other.m_number[i]);
    	}
  	}
  	//carry remainders (ensure single digits)
  	int remainder;
  	for (int i = 0; i < p.m_size - 1; i++){
    	remainder = p.m_number[i];
    	p.m_number[i] %= 10;
    	remainder /= 10;
    	p.m_number[i + 1] += remainder;
  	}
  	//find out how small to shrink the array
  	int j = p.m_size - 1;
  	while (p.m_number[j] == 0 && j != 0){
  		j--;
  	}
  	LargeNumber n;
  	n.m_size = j + 1;
  	n.m_number = new int[n.m_size];
  	for (int i = 0; i < n.m_size; i++){
  		n.m_number[i] = p.m_number[i];
  	}
  	return n;
}

const LargeNumber LargeNumber::operator/(const LargeNumber &other) const{
  	if (other.m_number == NULL) return *this;
	if (m_number == NULL) return other;
	if (other == 0){
		throw new invalid_argument("Cannot divide by zero");
	}
	if (*this == 0) return *this;
	if (*this < other){
		return LargeNumber(0);
	}
	LargeNumber p;
	p.m_number = new int[m_size];
	p.m_size = m_size;
	for (int i = 0; i < p.m_size; i++){
		p.m_number[i] = m_number[i];
	}
	//make a quotient
	LargeNumber d;
	//grow the quotient
	for (d; p >= other; p -= other, d++){  
		//d grows by one and p decrements by other on each loop
		//loop is broken when p < other
	}
	//find out how small to shrink the array
	int j = d.m_size - 1;
  	while (d.m_number[j] == 0 && j != 0){
  		j--;
  	}
  	LargeNumber n;
  	n.m_size = j + 1;
  	n.m_number = new int[n.m_size];
  	for (int i = 0; i < n.m_size; i++){
  		n.m_number[i] = d.m_number[i];
  	}
  	return n;
}

const LargeNumber LargeNumber::operator%(const LargeNumber &other) const{
	if (other.m_number == NULL) return *this;
	if (m_number == NULL) return other;
	if (other == 0){
		cout << "undefined" << endl;
		return *this;
	}
	if (*this == 0) return *this;
	if (*this < other){
		return *this;
	}
	LargeNumber p;
	p.m_number = new int[m_size];
	p.m_size = m_size;
	for (int i = 0; i < p.m_size; i++){
		p.m_number[i] = m_number[i];
	}
	//make a quotient
	LargeNumber d;
	//grow the quotient
	for (d; p >= other; p -= other, d++){
		//d grows by one and p decrements by other on each loop
		//loop is broken when p < other
	}
	//we are going to return p
	int j = p.m_size - 1;
	while (p.m_number[j] == 0 && j != 0){
		j--;
	}
	LargeNumber n;
	n.m_size = j + 1;
	n.m_number = new int[n.m_size];
	for (int i = 0; i < n.m_size; i++){
		n.m_number[i] = p.m_number[i];
	}
	return n;
}
/*end large int operations*/




/*small int operations*/
LargeNumber & LargeNumber::operator+=(const int &rhs){
  	LargeNumber p(rhs);
  	*this += p;
  	return *this;
}

LargeNumber & LargeNumber::operator-=(const int &rhs){
	LargeNumber p(rhs);
  	*this -= p;
  	return *this;
}

LargeNumber & LargeNumber::operator*=(const int &rhs){
	LargeNumber p(rhs);
	*this *= p;
	return *this;
}

LargeNumber & LargeNumber::operator/=(const int &rhs){
  	LargeNumber p(rhs);
  	*this /= p;
  	return *this;
}

LargeNumber & LargeNumber::operator%=(const int &rhs){
	LargeNumber p(rhs);
	*this /= p;
	return *this;
}

const LargeNumber LargeNumber::operator+(const int &other) const{
  LargeNumber result = *this;
  result += other;
  return result;
}

const LargeNumber LargeNumber::operator-(const int &other) const{
  LargeNumber result = *this;
  result -= other;
  return result;
}

const LargeNumber LargeNumber::operator*(const int &other) const{
  LargeNumber result = *this;
  result *= other;
  return result;
}

const LargeNumber LargeNumber::operator/(const int &other) const{
  LargeNumber result = *this;
  result /= other;
  return result;
}

const LargeNumber LargeNumber::operator%(const int &other) const{
	LargeNumber result = *this;
	result %= other;
	return result;
}

const void LargeNumber::print() const{
  cout << this->toString();
}

const string LargeNumber::toString() const{
  string toReturn = "";
  for (int i = m_size - 1; i >= 0; i--){
  	toReturn += m_number[i];
  }
  return toReturn;
}
/*end small int operations*/



/*private functions*/
const int LargeNumber::digits(int n) const{
  if (n < 0) return -1;
  int i = 0;
  while (n != 0){
    n /= 10;
    i++;
  }
  return i;
}
/*end private functions*/



/*comparison operators*/
const bool LargeNumber::operator==(const int& rhs) const{
	LargeNumber p(rhs);
	if (*this == p) return true;
	return false;
}

const bool LargeNumber::operator!=(const int& rhs) const{
	LargeNumber p(rhs);
	if (*this != p) return true;
	return false;
}

const bool LargeNumber::operator <(const int& rhs) const{
	LargeNumber p(rhs);
	if (*this < p) return true;
	return false;
}

const bool LargeNumber::operator >(const int& rhs) const{
	LargeNumber p(rhs);
	if (*this > p) return true;
	return false;
}

const bool LargeNumber::operator<=(const int& rhs) const{
	LargeNumber p(rhs);
	if (*this <= p) return true;
	return false;
}

const bool LargeNumber::operator>=(const int& rhs) const{
	LargeNumber p(rhs);
	if (*this >= p) return true;
	return false;
}

const bool LargeNumber::operator==(const LargeNumber& rhs) const{ 
	if (m_number == NULL || rhs.m_number == NULL) return false;
	if (m_size != rhs.m_size) return false;
	for (int i = 0; i < m_size; i++){
		if (m_number[i] != rhs.m_number[i]) return false;
	}
	return true;
}

const bool LargeNumber::operator!=(const LargeNumber& rhs) const{
	if (m_number == NULL || rhs.m_number == NULL) return true;
	if (m_size != rhs.m_size) return true;
	for (int i = 0; i < m_size; i++){
		if (m_number[i] != rhs.m_number[i]) return true;
	}
	return false;
}

const bool LargeNumber::operator< (const LargeNumber& rhs) const{
	if (m_size > rhs.m_size) return false;
	if (m_size < rhs.m_size) return true;
	for (int i = m_size - 1; i >= 0; i--){
		if (m_number[i] > rhs.m_number[i]) return false;
		if (m_number[i] < rhs.m_number[i]) return true;
	}
	return false; //m_numbers are equal
}

const bool LargeNumber::operator> (const LargeNumber& rhs) const{
	if (m_size > rhs.m_size) return true;
	if (m_size < rhs.m_size) return false;
	for (int i = m_size - 1; i >= 0; i--){
		if (m_number[i] > rhs.m_number[i]) return true;
		if (m_number[i] < rhs.m_number[i]) return false;
	}
	return false; //m_numbers are equal
}

const bool LargeNumber::operator<=(const LargeNumber& rhs) const{
	if (m_size > rhs.m_size) return false;
	if (m_size < rhs.m_size) return true;
	for (int i = m_size - 1; i >= 0; i--){
		if (m_number[i] > rhs.m_number[i]) return false;
		if (m_number[i] < rhs.m_number[i]) return true;
	}
	return true; //m_numbers are equal
}

const bool LargeNumber::operator>=(const LargeNumber& rhs) const{
	if (m_size > rhs.m_size) return true;
	if (m_size < rhs.m_size) return false;
	for (int i = m_size - 1; i >= 0; i--){
		if (m_number[i] > rhs.m_number[i]) return true;
		if (m_number[i] < rhs.m_number[i])return false;
	}
	return true;
}
/*end comparison operators*/