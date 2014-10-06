#ifndef largenumber_h
#define largenumber_h
#include <string>
class LargeNumber{
 	public:
  		LargeNumber();
  		LargeNumber(int);
  		LargeNumber(int*, int);
  		~LargeNumber();
  		LargeNumber & operator=(const LargeNumber &rhs);
  		LargeNumber & operator=(const int &rhs);
  		
  		LargeNumber & operator++();
  		LargeNumber operator++(int);
  		LargeNumber & operator--();
  		LargeNumber operator--(int);

  		LargeNumber & operator+=(const LargeNumber &rhs);
  		LargeNumber & operator-=(const LargeNumber &rhs);
  		LargeNumber & operator*=(const LargeNumber &rhs);
  		LargeNumber & operator/=(const LargeNumber &rhs);
  		LargeNumber & operator%=(const LargeNumber &rhs);

  		const LargeNumber LargeNumber::operator+(const LargeNumber &other) const;
  		const LargeNumber LargeNumber::operator-(const LargeNumber &other) const;
  		const LargeNumber LargeNumber::operator*(const LargeNumber &other) const;
  		const LargeNumber LargeNumber::operator/(const LargeNumber &other) const;
  		const LargeNumber LargeNumber::operator%(const LargeNumber &other) const;

  		LargeNumber & operator+=(const int &rhs);
  		LargeNumber & operator-=(const int &rhs);
  		LargeNumber & operator*=(const int &rhs);
  		LargeNumber & operator/=(const int &rhs);
  		LargeNumber & operator%=(const int &rhs);

  		const LargeNumber LargeNumber::operator+(const int &other) const;
  		const LargeNumber LargeNumber::operator-(const int &other) const;
  		const LargeNumber LargeNumber::operator*(const int &other) const;
  		const LargeNumber LargeNumber::operator/(const int &other) const;
  		const LargeNumber LargeNumber::operator%(const int &other) const;
  		
  		const bool operator==(const int& rhs) const;
  		const bool operator!=(const int& rhs) const;
  		const bool operator> (const int& rhs) const;
  		const bool operator< (const int& rhs) const;
  		const bool operator>=(const int& rhs) const;
  		const bool operator<=(const int& rhs) const;
  		
  		const bool operator==(const LargeNumber& rhs) const;
  		const bool operator!=(const LargeNumber& rhs) const;
  		const bool operator> (const LargeNumber& rhs) const;
  		const bool operator< (const LargeNumber& rhs) const;
  		const bool operator>=(const LargeNumber& rhs) const;
  		const bool operator<=(const LargeNumber& rhs) const;

  		const void print() const;
  		const std::string toString() const;

 	private:
  		int* m_number;
  		int m_size;
  		const int digits(int) const;
};
#endif
