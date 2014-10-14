#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <sstream>
#include "LargeNumber.h"
using namespace std;

const int LargeNumber::POSITIVE_TAG = 1;
const int LargeNumber::NEGATIVE_TAG = -1;

/** constructors and assignment operators */
LargeNumber::LargeNumber(){
	copy(0);
}
LargeNumber::LargeNumber(int n){
	copy(n);
}
LargeNumber::LargeNumber(int* num, int size){
	copy(num, size);
}
LargeNumber::LargeNumber(vector<int> num){
	m_number = num;
}
LargeNumber::~LargeNumber(){
	m_number.clear();
}
LargeNumber & LargeNumber::operator=(const LargeNumber &rhs){
	m_number.clear();
	m_number = rhs.m_number;
	return *this;
}
LargeNumber & LargeNumber::operator=(const int &rhs){
	copy(rhs);
}
/** end construction and assignment operators */

/** incremental operators */
LargeNumber & LargeNumber::operator++(){
	*this += 1;
	return *this;
}
LargeNumber & LargeNumber::operator++(int n){
	*this += LargeNumber(n);
	return *this;
}
LargeNumber & LargeNumber::operator--(){
	*this -= 1;
	return *this;
}
LargeNumber & LargeNumber::operator--(int n){
	*this += LargeNumber(n);
	return *this;
}
/** end incremental operators */

/** LargeNumber operators */
LargeNumber & LargeNumber::operator+=(const LargeNumber &rhs){
	if (rhs.getNumber().empty()) return *this;
	if (m_number.empty()){
		*this = rhs;
		return *this;
	}
	vector<int> number;
	vector<int>::iterator lhsIter = m_number.begin();
	vector<int>::const_iterator rhsIter = rhs.getNumber().begin();
	const int lhsSign = *lhsIter;
	const int rhsSign = *rhsIter;
	++lhsIter; ++rhsIter;
	number.push_back(LargeNumber::POSITIVE_TAG); //just keep it positive for now and change it later
	while (lhsIter != m_number.end() && rhsIter != rhs.getNumber().end()){
		if (lhsSign == LargeNumber::POSITIVE_TAG && rhsSign == LargeNumber::POSITIVE_TAG){
			number.push_back(*lhsIter + *rhsIter);
		} else if (lhsSign == LargeNumber::POSITIVE_TAG && rhsSign == LargeNumber::NEGATIVE_TAG){
			number.push_back(*lhsIter - *rhsIter);
		} else if (lhsSign == LargeNumber::NEGATIVE_TAG && rhsSign == LargeNumber::POSITIVE_TAG){
			number.push_back(*rhsIter - *lhsIter);
		} else if (lhsSign == LargeNumber::NEGATIVE_TAG && rhsSign == LargeNumber::NEGATIVE_TAG){
			number.push_back(-(*rhsIter + *lhsIter));
		} else {
			throw invalid_argument("Received LargeNumbers with invalid signs");
		}
		++lhsIter; ++rhsIter;
	}
	while (lhsIter != m_number.end()){
		number.push_back(*lhsIter);
		++lhsIter;
	}
	while (rhsIter != rhs.getNumber().end()){
		number.push_back(*rhsIter);
		++rhsIter;
	}
	m_number = refactor(number);
	return *this;
}

LargeNumber & LargeNumber::operator-=(const LargeNumber &rhs){
	if (rhs.getNumber().empty()) return *this;
	if (m_number.empty()){
		m_number = LargeNumber::changeSign(rhs.getNumber());
		return *this;
	}
	vector<int> number;
	vector<int>::iterator lhsIter = m_number.begin();
	vector<int>::const_iterator rhsIter = rhs.getNumber().begin();
	const int lhsSign = *lhsIter;
	const int rhsSign = *rhsIter;
	++lhsIter; ++rhsIter;
	number.push_back(LargeNumber::POSITIVE_TAG); //just keep it positive for now and change it later
	while (lhsIter != m_number.end() && rhsIter != rhs.getNumber().end()){
		if (lhsSign == LargeNumber::POSITIVE_TAG && rhsSign == LargeNumber::POSITIVE_TAG){
			number.push_back(*lhsIter - *rhsIter);
		} else if (lhsSign == LargeNumber::POSITIVE_TAG && rhsSign == LargeNumber::NEGATIVE_TAG){
			number.push_back(*lhsIter + *rhsIter);
		} else if (lhsSign == LargeNumber::NEGATIVE_TAG && rhsSign == LargeNumber::POSITIVE_TAG){
			number.push_back(*rhsIter - *lhsIter);
		} else if (lhsSign == LargeNumber::NEGATIVE_TAG && rhsSign == LargeNumber::POSITIVE_TAG){
			number.push_back(-(*lhsIter + *rhsIter));
		} else {
			throw invalid_argument("Received LargeNumbers with invalid signs");
		}
		++lhsIter; ++rhsIter;
	}
	while (lhsIter != m_number.end()){
		number.push_back(*lhsIter);
		++lhsIter;
	}
	while (rhsIter != rhs.getNumber().end()){
		number.push_back(*rhsIter);
		++rhsIter;
	}
	m_number = refactor(number);
	return *this;
}

LargeNumber & LargeNumber::operator*=(const LargeNumber &rhs){
	return *this;
}
LargeNumber & LargeNumber::operator/=(const LargeNumber &rhs){
	return *this;
}
LargeNumber & LargeNumber::operator%=(const LargeNumber &rhs){
	return *this;
}

const LargeNumber LargeNumber::operator+(const LargeNumber &other) const{
	LargeNumber p = *this;
	return (p += other);
}
const LargeNumber LargeNumber::operator-(const LargeNumber &other) const{
	LargeNumber p = *this;
	return (p -= other);
}
const LargeNumber LargeNumber::operator*(const LargeNumber &other) const{
	LargeNumber p = *this;
	return (p *= other);
}
const LargeNumber LargeNumber::operator/(const LargeNumber &other) const{
	LargeNumber p = *this;
	return (p /= other);
}
const LargeNumber LargeNumber::operator%(const LargeNumber &other) const{
	LargeNumber p = *this;
	return (p %= other);
}
/** end LargeNumber operators */

/** integer operators */
LargeNumber & LargeNumber::operator+=(const int &rhs){
	return (*this += LargeNumber(rhs));
}
LargeNumber & LargeNumber::operator-=(const int &rhs){
	return (*this -= LargeNumber(rhs));
}
LargeNumber & LargeNumber::operator*=(const int &rhs){
	return (*this *= LargeNumber(rhs));
}
LargeNumber & LargeNumber::operator/=(const int &rhs){
	return (*this /= LargeNumber(rhs));
}
LargeNumber & LargeNumber::operator%=(const int &rhs){
	return (*this %= LargeNumber(rhs));
}
const LargeNumber LargeNumber::operator+(const int &other) const{
	LargeNumber p = *this;
	return (p += LargeNumber(other));
}
const LargeNumber LargeNumber::operator-(const int &other) const{
	LargeNumber p = *this;
	return (p -= LargeNumber(other));
}
const LargeNumber LargeNumber::operator*(const int &other) const{
	LargeNumber p = *this;
	return (p *= LargeNumber(other));
}
const LargeNumber LargeNumber::operator/(const int &other) const{
	LargeNumber p = *this;
	return (p /= LargeNumber(other));
}
const LargeNumber LargeNumber::operator%(const int &other) const{
	LargeNumber p = *this;
	return (p %= LargeNumber(other));
}
/** end integer operators */


/** comparison operators */
const bool LargeNumber::operator==(const int& rhs) const { return (*this == LargeNumber(rhs)); }
const bool LargeNumber::operator!=(const int& rhs) const { return (*this != LargeNumber(rhs)); }
const bool LargeNumber::operator> (const int& rhs) const { return (*this >  LargeNumber(rhs)); }
const bool LargeNumber::operator< (const int& rhs) const { return (*this <  LargeNumber(rhs)); }
const bool LargeNumber::operator>=(const int& rhs) const { return (*this >= LargeNumber(rhs)); }
const bool LargeNumber::operator<=(const int& rhs) const { return (*this <= LargeNumber(rhs)); }

const bool LargeNumber::operator==(const LargeNumber& rhs) const { return false; }
const bool LargeNumber::operator!=(const LargeNumber& rhs) const { return !(*this == rhs); }
const bool LargeNumber::operator> (const LargeNumber& rhs) const { return false; }
const bool LargeNumber::operator< (const LargeNumber& rhs) const { return !((*this > rhs) && (*this == rhs)); }
const bool LargeNumber::operator>=(const LargeNumber& rhs) const { return ((*this > rhs) || (*this == rhs)); }
const bool LargeNumber::operator<=(const LargeNumber& rhs) const { return ((*this < rhs) || (*this == rhs)); }
/** end comparison operators */

/** accessibility operators */
const void LargeNumber::print() const{
	cout << this->toString() << endl;
}
const string LargeNumber::toString() const{
	string toReturn = (*(m_number.begin()) == LargeNumber::NEGATIVE_TAG) ? "- " : " ";
	for (vector<int>::const_reverse_iterator iter = m_number.rbegin(); iter + 1 != m_number.rend(); ++iter){
		toReturn += LargeNumber::intToString(*iter);
	}
	return toReturn;
}
const string LargeNumber::debug() const{
	string toReturn = (*(m_number.begin()) == LargeNumber::NEGATIVE_TAG) ? "- " : " ";
	for (vector<int>::const_reverse_iterator iter = m_number.rbegin(); iter + 1 != m_number.rend(); ++iter){
		toReturn += LargeNumber::intToString(*iter) + " ";
	}
	return toReturn;
}
/** end accessibility operators */

/** private operators */
string LargeNumber::intToString(int n)
{
	ostringstream ss;
    ss << n;
    return ss.str();
}
vector<int> LargeNumber::refactor(vector<int> source){
	vector<int> number;
	bool isNegative = false;
	for (vector<int>::const_iterator iter = source.begin(); iter != source.end(); ++iter){
		number.push_back(*iter);
	}
	return number;
}
vector<int> LargeNumber::changeSign(vector<int> source){
	vector<int> number = source;
	int sign = number.front();
	if (sign == LargeNumber::POSITIVE_TAG){
		number.front() = LargeNumber::NEGATIVE_TAG;
	} else if (sign == LargeNumber::NEGATIVE_TAG){
		number.front() == LargeNumber::POSITIVE_TAG;
	} else {
		throw invalid_argument("Invalid sign");
	}
	return number;
}
	
void LargeNumber::copy(int source){
	m_number.clear();
	m_number.push_back((source < 0) ? LargeNumber::NEGATIVE_TAG : LargeNumber::POSITIVE_TAG);
	if (source == 0) { m_number.push_back(0); return; }
	while (source != 0){
		m_number.push_back(abs(source % 10));
		source /= 10;
	}
}
void LargeNumber::copy(int* source, int size){
	m_number.clear();
	m_number.push_back((source[0] == LargeNumber::NEGATIVE_TAG) ? LargeNumber::NEGATIVE_TAG : LargeNumber::POSITIVE_TAG);
	for (int i = size - 1; i > 0; i--){
		m_number.push_back(abs(source[i]));
	}
}
bool LargeNumber::isNegative(){
	return ((m_number.front() < 0) ? true : false);
}
/** end private operators */