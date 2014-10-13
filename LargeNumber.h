#ifndef largenumber_h
#define largenumber_h
#include <string>
#include <vector>
class LargeNumber{
 	public:
 		static const int NEGATIVE_TAG;
 		static const int POSITIVE_TAG;
  		LargeNumber();
  		LargeNumber(int);
  		LargeNumber(int*, int);
  		LargeNumber(std::vector<int>);
  		~LargeNumber();
  		LargeNumber & operator=(const LargeNumber &rhs);
  		LargeNumber & operator=(const int &rhs);
  		
  		LargeNumber & operator++();
  		LargeNumber & operator++(int);
  		LargeNumber & operator--();
  		LargeNumber & operator--(int);

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
  		const std::string debug() const;
  		
  		inline std::vector<int> const getNumber() const { return m_number; };
 	private:
  		std::vector<int> m_number;
  		static std::string intToString(int n);
  		static std::vector<int> refactor(std::vector<int> source);
  		static std::vector<int> changeSign(std::vector<int> source);
  		bool isNegative();
  		void copy(int source);
  		void copy(int* source, int size);
};
#endif
