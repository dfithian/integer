#ifndef Integer_h
#define Integer_h
#include <string>
#include <vector>
class Integer{
 	public:
  		Integer();
  		Integer(int);
  		Integer(unsigned int);
  		Integer(short);
  		Integer(unsigned short);
  		Integer(long);
  		Integer(unsigned long);
  		Integer(int*, int);
  		Integer(std::vector<int>);
  		~Integer();
  		Integer & operator=(const Integer &rhs);
  		Integer & operator=(const int &rhs);
  		Integer & operator=(const unsigned int &rhs);
  		Integer & operator=(const short &rhs);
  		Integer & operator=(const unsigned short &rhs);
  		Integer & operator=(const long &rhs);
  		Integer & operator=(const unsigned long &rhs);

  		enum Sign { NEG, POS };
  		
  		Integer & operator++();
  		Integer & operator--();
  		Integer & operator++(int);
  		Integer & operator--(int);

  		Integer & operator+=(const Integer &rhs);
  		Integer & operator-=(const Integer &rhs);
  		Integer & operator*=(const Integer &rhs);
  		Integer & operator/=(const Integer &rhs);
  		Integer & operator%=(const Integer &rhs);

  		const Integer Integer::operator+(const Integer &other) const;
  		const Integer Integer::operator-(const Integer &other) const;
  		const Integer Integer::operator*(const Integer &other) const;
  		const Integer Integer::operator/(const Integer &other) const;
  		const Integer Integer::operator%(const Integer &other) const;

        const bool operator==(const Integer& rhs) const;
        const bool operator!=(const Integer& rhs) const;
        const bool operator> (const Integer& rhs) const;
        const bool operator< (const Integer& rhs) const;
        const bool operator>=(const Integer& rhs) const;
        const bool operator<=(const Integer& rhs) const;
        //absolute value operator
        const bool operator^ (const Integer& rhs) const;
        const bool operator^=(const Integer& rhs) const;
  		
  		Integer & operator+=(const int &rhs);
  		Integer & operator-=(const int &rhs);
  		Integer & operator*=(const int &rhs);
  		Integer & operator/=(const int &rhs);
  		Integer & operator%=(const int &rhs);
  		Integer & operator+=(const unsigned int &rhs);
  		Integer & operator-=(const unsigned int &rhs);
  		Integer & operator*=(const unsigned int &rhs);
  		Integer & operator/=(const unsigned int &rhs);
  		Integer & operator%=(const unsigned int &rhs);
		Integer & operator+=(const short &rhs);
  		Integer & operator-=(const short &rhs);
  		Integer & operator*=(const short &rhs);
  		Integer & operator/=(const short &rhs);
  		Integer & operator%=(const short &rhs);
  		Integer & operator+=(const unsigned short &rhs);
  		Integer & operator-=(const unsigned short &rhs);
  		Integer & operator*=(const unsigned short &rhs);
  		Integer & operator/=(const unsigned short &rhs);
  		Integer & operator%=(const unsigned short &rhs);
  		Integer & operator+=(const long &rhs);
  		Integer & operator-=(const long &rhs);
  		Integer & operator*=(const long &rhs);
  		Integer & operator/=(const long &rhs);
  		Integer & operator%=(const long &rhs);
  		Integer & operator+=(const unsigned long &rhs);
  		Integer & operator-=(const unsigned long &rhs);
  		Integer & operator*=(const unsigned long &rhs);
  		Integer & operator/=(const unsigned long &rhs);
  		Integer & operator%=(const unsigned long &rhs);
  		
  		const Integer Integer::operator+(const int &other) const;
  		const Integer Integer::operator-(const int &other) const;
  		const Integer Integer::operator*(const int &other) const;
  		const Integer Integer::operator/(const int &other) const;
  		const Integer Integer::operator%(const int &other) const;
  		const Integer Integer::operator+(const unsigned int &other) const;
  		const Integer Integer::operator-(const unsigned int &other) const;
  		const Integer Integer::operator*(const unsigned int &other) const;
  		const Integer Integer::operator/(const unsigned int &other) const;
  		const Integer Integer::operator%(const unsigned int &other) const;
  		const Integer Integer::operator+(const short &other) const;
  		const Integer Integer::operator-(const short &other) const;
  		const Integer Integer::operator*(const short &other) const;
  		const Integer Integer::operator/(const short &other) const;
  		const Integer Integer::operator%(const short &other) const;
  		const Integer Integer::operator+(const unsigned short &other) const;
  		const Integer Integer::operator-(const unsigned short &other) const;
  		const Integer Integer::operator*(const unsigned short &other) const;
  		const Integer Integer::operator/(const unsigned short &other) const;
  		const Integer Integer::operator%(const unsigned short &other) const;
  		const Integer Integer::operator+(const long &other) const;
  		const Integer Integer::operator-(const long &other) const;
  		const Integer Integer::operator*(const long &other) const;
  		const Integer Integer::operator/(const long &other) const;
  		const Integer Integer::operator%(const long &other) const;
  		const Integer Integer::operator+(const unsigned long &other) const;
  		const Integer Integer::operator-(const unsigned long &other) const;
  		const Integer Integer::operator*(const unsigned long &other) const;
  		const Integer Integer::operator/(const unsigned long &other) const;
  		const Integer Integer::operator%(const unsigned long &other) const;
  		
        const bool operator==(const int& rhs) const;
        const bool operator!=(const int& rhs) const;
        const bool operator> (const int& rhs) const;
        const bool operator< (const int& rhs) const;
        const bool operator>=(const int& rhs) const;
        const bool operator<=(const int& rhs) const;
        const bool operator==(const unsigned int& rhs) const;
        const bool operator!=(const unsigned int& rhs) const;
        const bool operator> (const unsigned int& rhs) const;
        const bool operator< (const unsigned int& rhs) const;
        const bool operator>=(const unsigned int& rhs) const;
        const bool operator<=(const unsigned int& rhs) const;
        const bool operator==(const short& rhs) const;
        const bool operator!=(const short& rhs) const;
        const bool operator> (const short& rhs) const;
        const bool operator< (const short& rhs) const;
        const bool operator>=(const short& rhs) const;
        const bool operator<=(const short& rhs) const;
        const bool operator==(const unsigned short& rhs) const;
        const bool operator!=(const unsigned short& rhs) const;
        const bool operator> (const unsigned short& rhs) const;
        const bool operator< (const unsigned short& rhs) const;
        const bool operator>=(const unsigned short& rhs) const;
        const bool operator<=(const unsigned short& rhs) const;
        const bool operator==(const long& rhs) const;
        const bool operator!=(const long& rhs) const;
        const bool operator> (const long& rhs) const;
        const bool operator< (const long& rhs) const;
        const bool operator>=(const long& rhs) const;
        const bool operator<=(const long& rhs) const;
        const bool operator==(const unsigned long& rhs) const;
        const bool operator!=(const unsigned long& rhs) const;
        const bool operator> (const unsigned long& rhs) const;
        const bool operator< (const unsigned long& rhs) const;
        const bool operator>=(const unsigned long& rhs) const;
        const bool operator<=(const unsigned long& rhs) const;

  		const void print() const;
  		const std::string toString() const;
  		const std::string debug() const;
  		
  		inline std::vector<int> const getNumber() const { return m_number; };
  		inline Integer::Sign const getSign() const { return m_sign; };
  		inline void setSign(Integer::Sign newSign) { m_sign = newSign; };
  		inline void stripZeros() { stripZeros(m_number); };
 	private:
  		std::vector<int> m_number;
  		Integer::Sign m_sign;
  		static std::string intToString(int n);
  		void copy(int source);
  		void copy(unsigned int source);
  		void copy(short source);
  		void copy(unsigned short source);
  		void copy(long source);
  		void copy(unsigned long source);
  		void copy(int* source, int size);
  		
  		static std::vector<int> addUnsigned(const Integer &lhs, const Integer &rhs);
  		static std::vector<int> subtractUnsigned(const Integer &lhs, const Integer &rhs);
  		static std::vector<int> multiplyUnsigned(const Integer &lhs, const Integer &rhs);
  		static std::vector<int> divideUnsigned(const Integer &lhs, const Integer &rhs);
  		static std::vector<int> moduloUnsigned(const Integer &lhs, const Integer &rhs);
  		
  		static void stripZeros(std::vector<int> &source);
  		static std::vector<int> zero();
};
#endif
