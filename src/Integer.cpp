#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <sstream>
#include "Integer.h"
using namespace std;

/** constructors and assignment operators */
Integer::Integer(){
	copy(0);
}
Integer::Integer(int n){
	copy(n);
}
Integer::Integer(unsigned int n){
	copy(n);
}
Integer::Integer(short n){
	copy(n);
}
Integer::Integer(unsigned short n){
	copy(n);
}
Integer::Integer(long n){
	copy(n);
}
Integer::Integer(unsigned long n){
	copy(n);
}
Integer::Integer(int* num, int size){
	copy(num, size);
}
Integer::Integer(vector<int> num){
	m_number = num;
	m_sign = POS;
}
Integer::Integer(const Integer &old){
	m_number.clear();
	vector<int> thatNumber = old.getNumber();
	for(vector<int>::const_iterator iter = thatNumber.begin(); iter != thatNumber.end(); ++iter){
		m_number.push_back(*iter);
	}
	m_sign = old.getSign();
}
Integer::~Integer(){
	m_number.clear();
}
Integer & Integer::operator=(const Integer &rhs){
	m_number.clear();
	vector<int> thatNumber = rhs.getNumber();
	for (vector<int>::const_iterator iter = thatNumber.begin(); iter != thatNumber.end(); ++iter){
		m_number.push_back(*iter);
	}
	m_sign = rhs.getSign();
	return *this;
}
Integer & Integer::operator=(const int &rhs){
	copy(rhs);
	return *this;
}
Integer & Integer::operator=(const unsigned int &rhs){
	copy(rhs);
	return *this;
}
Integer & Integer::operator=(const short &rhs){
	copy(rhs);
	return *this;
}
Integer & Integer::operator=(const unsigned short &rhs){
	copy(rhs);
	return *this;
}
Integer & Integer::operator=(const long &rhs){
	copy(rhs);
	return *this;
}
Integer & Integer::operator=(const unsigned long &rhs){
	copy(rhs);
	return *this;
}
/** end construction and assignment operators */

/** incremental operators */
Integer & Integer::operator++(){
	*this += Integer(1);
	return *this;
}
Integer & Integer::operator--(){
	*this -= Integer(1);
	return *this;
}
Integer & Integer::operator++(int n){
	*this += Integer(n);
	return *this;
}
Integer & Integer::operator--(int n){
	*this -= Integer(n);
	return *this;
}
/** end incremental operators */

/** Integer operators */
Integer & Integer::operator+=(const Integer &rhs){
	if (!rhs.getNumber().empty() && m_number.empty()) *this = rhs;
	else if (m_sign == rhs.getSign()) this->m_number = addUnsigned(*this, rhs);
	else if (*this == rhs) *this = Integer(0);
	else if (this->value() > rhs.value()) this->m_number = subtractUnsigned(*this, rhs);
	else{
		this->m_number = subtractUnsigned(rhs, *this);
		this->m_sign = rhs.getSign();
	}
	return *this;
}

Integer & Integer::operator-=(const Integer &rhs){
	if (!rhs.getNumber().empty() && m_number.empty()) {
		*this = rhs;
		this->m_sign = (m_sign == POS) ? NEG : POS;
	}
	else if (m_sign != rhs.getSign()) this->m_number = addUnsigned(*this, rhs);
	else if (*this == rhs) *this = Integer(0);
	else if (this->value() >= rhs.value()) this->m_number = subtractUnsigned(*this, rhs);
	else{
		this->m_number = subtractUnsigned(rhs, *this);
		this->m_sign = (m_sign == NEG) ? POS : NEG;
	}
	return *this;
}

Integer & Integer::operator*=(const Integer &rhs){
	if (rhs.getNumber().empty() || m_number.empty()) *this = Integer(0);
	else{
		if (m_sign != rhs.getSign()) m_sign = NEG;
		else m_sign = POS;
		this->m_number = multiplyUnsigned(*this, rhs);
	}
	return *this;
}
Integer & Integer::operator/=(const Integer &rhs){
	if (rhs.getNumber().empty() || rhs == 0) throw invalid_argument("Divide by zero error");
	else if (m_number.empty() || *this == 0) *this = Integer(0);
	else {
		if (m_sign != rhs.getSign()) m_sign = NEG;
		else m_sign = POS;
		this->m_number = divideUnsigned(*this, rhs);
	}
	return *this;
}
Integer & Integer::operator%=(const Integer &rhs){
	if (rhs.getNumber().empty() || rhs == 0) throw invalid_argument("Divide by zero error");
	else if (m_number.empty() || *this == 0) *this = Integer(0);
	else {
		if (m_sign != rhs.getSign()) m_sign = NEG;
		else m_sign = POS;
		this->m_number = moduloUnsigned(*this, rhs);
	}
	return *this;
}

const Integer Integer::operator+(const Integer &other) const{
	Integer p = *this;
	return (p += other);
}
const Integer Integer::operator-(const Integer &other) const{
	Integer p = *this;
	return (p -= other);
}
const Integer Integer::operator*(const Integer &other) const{
	Integer p = *this;
	return (p *= other);
}
const Integer Integer::operator/(const Integer &other) const{
	Integer p = *this;
	return (p /= other);
}
const Integer Integer::operator%(const Integer &other) const{
	Integer p = *this;
	return (p %= other);
}
/** end Integer operators */

/** integer operators */
Integer & Integer::operator+=(const int &rhs){
	return (*this += Integer(rhs));
}
Integer & Integer::operator-=(const int &rhs){
	return (*this -= Integer(rhs));
}
Integer & Integer::operator*=(const int &rhs){
	return (*this *= Integer(rhs));
}
Integer & Integer::operator/=(const int &rhs){
	return (*this /= Integer(rhs));
}
Integer & Integer::operator%=(const int &rhs){
	return (*this %= Integer(rhs));
}
const Integer Integer::operator+(const int &other) const{
	Integer p = *this;
	return (p += Integer(other));
}
const Integer Integer::operator-(const int &other) const{
	Integer p = *this;
	return (p -= Integer(other));
}
const Integer Integer::operator*(const int &other) const{
	Integer p = *this;
	return (p *= Integer(other));
}
const Integer Integer::operator/(const int &other) const{
	Integer p = *this;
	return (p /= Integer(other));
}
const Integer Integer::operator%(const int &other) const{
	Integer p = *this;
	return (p %= Integer(other));
}
Integer & Integer::operator+=(const unsigned int &rhs){
	return (*this += Integer(rhs));
}
Integer & Integer::operator-=(const unsigned int &rhs){
	return (*this -= Integer(rhs));
}
Integer & Integer::operator*=(const unsigned int &rhs){
	return (*this *= Integer(rhs));
}
Integer & Integer::operator/=(const unsigned int &rhs){
	return (*this /= Integer(rhs));
}
Integer & Integer::operator%=(const unsigned int &rhs){
	return (*this %= Integer(rhs));
}
const Integer Integer::operator+(const unsigned int &other) const{
	Integer p = *this;
	return (p += Integer(other));
}
const Integer Integer::operator-(const unsigned int &other) const{
	Integer p = *this;
	return (p -= Integer(other));
}
const Integer Integer::operator*(const unsigned int &other) const{
	Integer p = *this;
	return (p *= Integer(other));
}
const Integer Integer::operator/(const unsigned int &other) const{
	Integer p = *this;
	return (p /= Integer(other));
}
const Integer Integer::operator%(const unsigned int &other) const{
	Integer p = *this;
	return (p %= Integer(other));
}
Integer & Integer::operator+=(const short &rhs){
	return (*this += Integer(rhs));
}
Integer & Integer::operator-=(const short &rhs){
	return (*this -= Integer(rhs));
}
Integer & Integer::operator*=(const short &rhs){
	return (*this *= Integer(rhs));
}
Integer & Integer::operator/=(const short &rhs){
	return (*this /= Integer(rhs));
}
Integer & Integer::operator%=(const short &rhs){
	return (*this %= Integer(rhs));
}
const Integer Integer::operator+(const short &other) const{
	Integer p = *this;
	return (p += Integer(other));
}
const Integer Integer::operator-(const short &other) const{
	Integer p = *this;
	return (p -= Integer(other));
}
const Integer Integer::operator*(const short &other) const{
	Integer p = *this;
	return (p *= Integer(other));
}
const Integer Integer::operator/(const short &other) const{
	Integer p = *this;
	return (p /= Integer(other));
}
const Integer Integer::operator%(const short &other) const{
	Integer p = *this;
	return (p %= Integer(other));
}
Integer & Integer::operator+=(const unsigned short &rhs){
	return (*this += Integer(rhs));
}
Integer & Integer::operator-=(const unsigned short &rhs){
	return (*this -= Integer(rhs));
}
Integer & Integer::operator*=(const unsigned short &rhs){
	return (*this *= Integer(rhs));
}
Integer & Integer::operator/=(const unsigned short &rhs){
	return (*this /= Integer(rhs));
}
Integer & Integer::operator%=(const unsigned short &rhs){
	return (*this %= Integer(rhs));
}
const Integer Integer::operator+(const unsigned short &other) const{
	Integer p = *this;
	return (p += Integer(other));
}
const Integer Integer::operator-(const unsigned short &other) const{
	Integer p = *this;
	return (p -= Integer(other));
}
const Integer Integer::operator*(const unsigned short &other) const{
	Integer p = *this;
	return (p *= Integer(other));
}
const Integer Integer::operator/(const unsigned short &other) const{
	Integer p = *this;
	return (p /= Integer(other));
}
const Integer Integer::operator%(const unsigned short &other) const{
	Integer p = *this;
	return (p %= Integer(other));
}
Integer & Integer::operator+=(const long &rhs){
	return (*this += Integer(rhs));
}
Integer & Integer::operator-=(const long &rhs){
	return (*this -= Integer(rhs));
}
Integer & Integer::operator*=(const long &rhs){
	return (*this *= Integer(rhs));
}
Integer & Integer::operator/=(const long &rhs){
	return (*this /= Integer(rhs));
}
Integer & Integer::operator%=(const long &rhs){
	return (*this %= Integer(rhs));
}
const Integer Integer::operator+(const long &other) const{
	Integer p = *this;
	return (p += Integer(other));
}
const Integer Integer::operator-(const long &other) const{
	Integer p = *this;
	return (p -= Integer(other));
}
const Integer Integer::operator*(const long &other) const{
	Integer p = *this;
	return (p *= Integer(other));
}
const Integer Integer::operator/(const long &other) const{
	Integer p = *this;
	return (p /= Integer(other));
}
const Integer Integer::operator%(const long &other) const{
	Integer p = *this;
	return (p %= Integer(other));
}
Integer & Integer::operator+=(const unsigned long &rhs){
	return (*this += Integer(rhs));
}
Integer & Integer::operator-=(const unsigned long &rhs){
	return (*this -= Integer(rhs));
}
Integer & Integer::operator*=(const unsigned long &rhs){
	return (*this *= Integer(rhs));
}
Integer & Integer::operator/=(const unsigned long &rhs){
	return (*this /= Integer(rhs));
}
Integer & Integer::operator%=(const unsigned long &rhs){
	return (*this %= Integer(rhs));
}
const Integer Integer::operator+(const unsigned long &other) const{
	Integer p = *this;
	return (p += Integer(other));
}
const Integer Integer::operator-(const unsigned long &other) const{
	Integer p = *this;
	return (p -= Integer(other));
}
const Integer Integer::operator*(const unsigned long &other) const{
	Integer p = *this;
	return (p *= Integer(other));
}
const Integer Integer::operator/(const unsigned long &other) const{
	Integer p = *this;
	return (p /= Integer(other));
}
const Integer Integer::operator%(const unsigned long &other) const{
	Integer p = *this;
	return (p %= Integer(other));
}
/** end integer operators */


/** comparison operators */
const bool Integer::operator==(const int& rhs) const { return (*this == Integer(rhs)); }
const bool Integer::operator!=(const int& rhs) const { return (*this != Integer(rhs)); }
const bool Integer::operator> (const int& rhs) const { return (*this >  Integer(rhs)); }
const bool Integer::operator< (const int& rhs) const { return (*this <  Integer(rhs)); }
const bool Integer::operator>=(const int& rhs) const { return (*this >= Integer(rhs)); }
const bool Integer::operator<=(const int& rhs) const { return (*this <= Integer(rhs)); }
const bool Integer::operator==(const unsigned int& rhs) const { return (*this == Integer(rhs)); }
const bool Integer::operator!=(const unsigned int& rhs) const { return (*this != Integer(rhs)); }
const bool Integer::operator> (const unsigned int& rhs) const { return (*this >  Integer(rhs)); }
const bool Integer::operator< (const unsigned int& rhs) const { return (*this <  Integer(rhs)); }
const bool Integer::operator>=(const unsigned int& rhs) const { return (*this >= Integer(rhs)); }
const bool Integer::operator<=(const unsigned int& rhs) const { return (*this <= Integer(rhs)); }
const bool Integer::operator==(const short& rhs) const { return (*this == Integer(rhs)); }
const bool Integer::operator!=(const short& rhs) const { return (*this != Integer(rhs)); }
const bool Integer::operator> (const short& rhs) const { return (*this >  Integer(rhs)); }
const bool Integer::operator< (const short& rhs) const { return (*this <  Integer(rhs)); }
const bool Integer::operator>=(const short& rhs) const { return (*this >= Integer(rhs)); }
const bool Integer::operator<=(const short& rhs) const { return (*this <= Integer(rhs)); }
const bool Integer::operator==(const unsigned short& rhs) const { return (*this == Integer(rhs)); }
const bool Integer::operator!=(const unsigned short& rhs) const { return (*this != Integer(rhs)); }
const bool Integer::operator> (const unsigned short& rhs) const { return (*this >  Integer(rhs)); }
const bool Integer::operator< (const unsigned short& rhs) const { return (*this <  Integer(rhs)); }
const bool Integer::operator>=(const unsigned short& rhs) const { return (*this >= Integer(rhs)); }
const bool Integer::operator<=(const unsigned short& rhs) const { return (*this <= Integer(rhs)); }
const bool Integer::operator==(const long& rhs) const { return (*this == Integer(rhs)); }
const bool Integer::operator!=(const long& rhs) const { return (*this != Integer(rhs)); }
const bool Integer::operator> (const long& rhs) const { return (*this >  Integer(rhs)); }
const bool Integer::operator< (const long& rhs) const { return (*this <  Integer(rhs)); }
const bool Integer::operator>=(const long& rhs) const { return (*this >= Integer(rhs)); }
const bool Integer::operator<=(const long& rhs) const { return (*this <= Integer(rhs)); }
const bool Integer::operator==(const unsigned long& rhs) const { return (*this == Integer(rhs)); }
const bool Integer::operator!=(const unsigned long& rhs) const { return (*this != Integer(rhs)); }
const bool Integer::operator> (const unsigned long& rhs) const { return (*this >  Integer(rhs)); }
const bool Integer::operator< (const unsigned long& rhs) const { return (*this <  Integer(rhs)); }
const bool Integer::operator>=(const unsigned long& rhs) const { return (*this >= Integer(rhs)); }
const bool Integer::operator<=(const unsigned long& rhs) const { return (*this <= Integer(rhs)); }

const bool Integer::operator==(const Integer& rhs) const {
	vector<int> thatNumber = rhs.getNumber();
	if (m_number.empty() && thatNumber.empty()) return true;
	else if (m_number.size() != thatNumber.size()) return false;
	else if (m_sign != rhs.getSign()) return false;
	vector<int>::const_iterator thatIter = thatNumber.begin();
	vector<int>::const_iterator thisIter = m_number.begin();
	while (thisIter != m_number.end() && thatIter != thatNumber.end()){
		if (*thisIter != *thatIter) return false;
		++thisIter; ++thatIter;
	}
	return true;
}
const bool Integer::operator> (const Integer& rhs) const {
	vector<int> thatNumber = rhs.getNumber();
	if (m_number.empty() && thatNumber.empty()) return false;
	else if (m_sign != rhs.getSign()) return (m_sign == POS);
	else if (m_number.size() > thatNumber.size()) return (m_sign == POS);
	else if (m_number.size() < thatNumber.size()) return (m_sign == NEG);
	else {
		//same size, same sign
		vector<int>::const_reverse_iterator thisIter = m_number.rbegin();
		vector<int>::const_reverse_iterator thatIter = thatNumber.rbegin();
		while (thisIter != m_number.rend() && thatIter != (const vector<int>::const_reverse_iterator)thatNumber.rend()){
			if (*thisIter > *thatIter) return true;
			else if (*thisIter < *thatIter) return false;
			++thisIter; ++thatIter;
		}
		return false; //numbers are equal
	}
}
const bool Integer::operator< (const Integer& rhs) const { return !((*this > rhs) || (*this == rhs)); }
const bool Integer::operator>=(const Integer& rhs) const { return  ((*this > rhs) || (*this == rhs)); }
const bool Integer::operator<=(const Integer& rhs) const { return  ((*this < rhs) || (*this == rhs)); }
const bool Integer::operator!=(const Integer& rhs) const { return !(*this == rhs); }
/** end comparison operators */

const Integer Integer::value() const{
	Integer newNumber(*this);
	newNumber.setSign(POS);
	return newNumber;
}

/** accessibility operators */
const void Integer::print() const{
	cout << this->toString() << endl;
}
const string Integer::toString() const{
	string toReturn = (m_sign == NEG) ? "-" : "";
	for (vector<int>::const_reverse_iterator iter = m_number.rbegin(); iter != m_number.rend(); ++iter){
		toReturn += Integer::intToString(*iter);
	}
	return toReturn;
}
const string Integer::debug() const{
	string toReturn = (m_sign == NEG) ? "- " : " ";
	for (vector<int>::const_reverse_iterator iter = m_number.rbegin(); iter != m_number.rend(); ++iter){
		toReturn += Integer::intToString(*iter) + " ";
	}
	return toReturn;
}
/** end accessibility operators */

/** private operators */
string Integer::intToString(int n)
{
	ostringstream ss;
    ss << n;
    return ss.str();
}

void Integer::copy(unsigned int source){
	copy((int)source);
}
void Integer::copy(int source){
	m_sign = (source < 0) ? NEG : POS;
	m_number.clear();
	if (source == 0) { m_number.push_back(0); return; }
	while (source != 0){
		m_number.push_back(abs(source) % 10);
		source /= 10;
	}
}
void Integer::copy(unsigned short source){
	copy((int)source);
}
void Integer::copy(short source){
	copy((int)source);
}
void Integer::copy(unsigned long source){
	copy((long)source);
}
void Integer::copy(long source){
	m_sign = (source < 0) ? NEG : POS;
	m_number.clear();
	if (source == 0) { m_number.push_back(0); return; }
	while (source != 0){
		m_number.push_back(abs(source) % 10);
		source /= 10;
	}
}
void Integer::copy(int* source, int size){
	m_sign = ((source[0] == -1) ? NEG : POS);
	m_number.clear();
	for (int i = size - 1; i > 0; i--){
		m_number.push_back(abs(source[i]));
	}
}
/** end private operators */

vector<int> Integer::addUnsigned(const Integer &lhs, const Integer &rhs){
	vector<int> newNumber;
	int remainder = 0;
	vector<int> thisNumber = lhs.getNumber();
	vector<int>::const_iterator thisIter = thisNumber.begin();
	vector<int> thatNumber = rhs.getNumber();
	vector<int>::const_iterator thatIter = thatNumber.begin();
	
	while (thisIter != thisNumber.end() && thatIter != thatNumber.end()){
		newNumber.push_back(*thisIter + *thatIter);
		++thisIter; ++thatIter;
	}
	while (thisIter != thisNumber.end()){
		newNumber.push_back(*thisIter);
		++thisIter;
	}
	while (thatIter != thatNumber.end()){
		newNumber.push_back(*thatIter);
		++thatIter;
	}
	int i = 0;
	for (vector<int>::iterator newIter = newNumber.begin(); newIter != newNumber.end(); ++newIter, i++){
		remainder += *newIter;
		newNumber.at(i) = remainder % 10;
		remainder /= 10;
	}
	while (remainder > 0){
		newNumber.push_back(remainder % 10);
		remainder /= 10;
	}
	stripZeros(newNumber);
	return newNumber;
}
//always assumes m_number is larger
vector<int> Integer::subtractUnsigned(const Integer &lhs, const Integer &rhs){
	if (rhs.value() > lhs.value()) throw invalid_argument("Must subtract smaller from larger in subtractUnsigned");
	else if (lhs == rhs) return zero();
	vector<int> newNumber;
	vector<int> thisNumber = lhs.getNumber();
	vector<int>::const_iterator thisIter = thisNumber.begin();
	vector<int> thatNumber = rhs.getNumber();
	vector<int>::const_iterator thatIter = thatNumber.begin();

	while (thisIter != thisNumber.end() && thatIter != thatNumber.end()){
		newNumber.push_back(*thisIter - *thatIter);
		++thisIter; ++thatIter;
	}
	while (thisIter != thisNumber.end()){
		newNumber.push_back(*thisIter);
		++thisIter;
	}

	vector<int>::iterator newIter = newNumber.begin();
	while (newIter != newNumber.end()){
		if (*newIter < 0){
			*newIter += 10;
			(*(newIter + 1))--;
		}
		++newIter;
	}
	stripZeros(newNumber);
	return newNumber;
}
vector<int> Integer::multiplyUnsigned(const Integer &lhs, const Integer &rhs){
	if (lhs == 0 || rhs == 0) return zero();
	vector<int> thisNumber = lhs.getNumber();
	vector<int> thatNumber = rhs.getNumber();
	vector<int> newNumber(thisNumber.size() + thatNumber.size(), 0);
	
	int i = 0;
	for (vector<int>::const_iterator thisIter = thisNumber.begin(); thisIter != thisNumber.end(); ++thisIter, i++){
		int j = 0;
		for (vector<int>::const_iterator thatIter = thatNumber.begin(); thatIter != thatNumber.end(); ++thatIter, j++){
			newNumber.at(i + j) += ((*thisIter) * (*thatIter));
		}
	}
	
	int remainder = 0;
	i = 0;
	for (vector<int>::iterator newIter = newNumber.begin(); newIter != newNumber.end(); ++newIter, i++){
		remainder += *newIter;
		newNumber.at(i) = remainder % 10;
		remainder /= 10;
	}
	stripZeros(newNumber);
	return newNumber;
}
vector<int> Integer::divideUnsigned(const Integer & lhs, const Integer & rhs){
	if (rhs == 0) throw invalid_argument("Divide by zero error");
	else if (lhs == 0 || rhs.value() > lhs.value()) return zero();
	Integer bottom(rhs);
	Integer top(lhs);
	
	Integer q = recursiveDivide(top, bottom);
	q.stripZeros();
	return q.getNumber();
}
Integer Integer::recursiveDivide(Integer dividend, Integer divisor){
	const Integer constDivisor = divisor;
	Integer quotient(1);
	if (divisor.value() == dividend.value()){
		return Integer(1);
	}else if (dividend.value() < divisor.value()){
		return Integer(0);
	}
	while (divisor.value() < dividend.value()){
		divisor *= 2;
		quotient *= 2;
	}
	if (divisor.value() > dividend.value()) { divisor /= 2; quotient /= 2; }

	quotient += recursiveDivide(dividend.value() - divisor.value(), constDivisor);
	return quotient;
}
vector<int> Integer::moduloUnsigned(const Integer & lhs, const Integer & rhs){
	if (rhs == 0) throw invalid_argument("Divide by zero error");
	else if (lhs == 0) return zero();
	else if (rhs.value() > lhs.value()) return lhs.getNumber();
	Integer bottom(rhs);
	Integer top(lhs);
	
	Integer r = recursiveModulo(top, bottom);
	r.stripZeros();
	return r.getNumber();
}
Integer Integer::recursiveModulo(Integer dividend, Integer divisor){
	const Integer constDivisor = divisor;
	Integer remainder(0);
	if (divisor.value() == dividend.value()){
		return Integer(0);
	}else if (dividend.value() < divisor.value()){
		return dividend;
	}
	while (divisor.value() < dividend.value()){
		divisor *= 2;
	}
	if (divisor.value() > dividend.value()) { divisor /= 2; }
	
	remainder += recursiveModulo(dividend.value() - divisor.value(), constDivisor);
	return remainder;
}
void Integer::stripZeros(vector<int> &source){
	int i = 0;
	vector<int>::reverse_iterator iter = source.rbegin();
	while (iter != source.rend() && *iter == 0){
		iter++; i++;
	}
	source.resize(source.size() - i);
	if (source.size() == 0 || source.empty()) source.push_back(0);
}
vector<int> Integer::zero(){
	vector<int> newNumber;
	newNumber.push_back(0);
	return newNumber;
}