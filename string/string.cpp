
#include <cassert>
#include "string.hpp"

String::String() {
	str[0] = 0;
}

String::String(char c) {
	str[0] = c;
	str[1] = 0;
}

String::String(const char literal[]) {
	int i = 0;
	while (literal[i] != 0) {
		if (i >= capacity()) break;
		str[i] = literal[i];
		++i;
	}
	str[i] = 0;
}

int String::length() const {
	int result = 0;
	while (str[result] != 0) ++result;
	return result;
}

// REQUIRES: 0 <= i < length()
char String::operator[](int i) const {
	assert(i >= 0);
	assert(i < length());
	return str[i];
}

// REQUIRES: 0 <= i < length()
char& String::operator[](int i) { // same as above, just a ref response instead
	assert(i >= 0);
	assert(i < length());
	return str[i];
}

String String::operator+(const String& rhs) const {
	String result(str);
	int i = 0;
	int offset = length();
	while(rhs[i] != 0) {
		result.str[i + offset] = rhs[i];
		++i;
	}
	result.str[i + offset] = 0;
	return result;
}

String operator+(char lhs, const String& rhs) { return String(lhs) + rhs; }
String operator+(const char lhs[], const String& rhs) {return String(lhs) + rhs; }

String& String::operator+=(const String& rhs) {
	int rhsLength = rhs.length();
	int offset = length();
    int i = 0;
    while (i < rhsLength) {
        str[i + offset] = rhs[i];
        ++i;
    }
    str[i + offset] = i;
    return *this;
}

String operator+(String lhs, const String& rhs) { return lhs += rhs; }

bool String::operator==(const String& rhs) const {
    int i = 0;
    while ((str[i] != 0) && str[i] == rhs.str[i]) ++i;
    return str[i] == rhs.str[i];
}

bool String::operator<(const String& rhs) const {
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] < rhs.str[i];
}

bool operator==(char, const String&) { return String(lhs) == rhs; }
bool operator==(const char[], const String&) { return String(lhs) == rhs; };
bool operator< (char, const String&) { return String(lhs) < rhs; };
bool operator< (const char[], const String&)  { return String(lhs) < rhs; };
bool operator !=(const String&, const String&)  { return !(String(lhs) == rhs); };
bool operator<=(const String&, const String&) { return !(rhs < lhs); };
bool operator>=(const String&, const String&) { return !(lhs < rhs); };
bool operator> (const String&, const String&) { return rhs < lhs; };

//
// REQUIRES: 0 <= start < capacity()
// ENSURE:   RETVAL == i where str[i] == ch && i >= start
//           RETVAL == -1 where ch not in string
int String::findchar(int start, char ch) const {
	if (start >= length()) return -1;
	if (start < 0) start = 0;

	int i = start;
	while (str[i] != 0) {
		if (str[i] == ch) return i;
	}

	return -1;
}

// REQUIRES: 0 <= start < length() && start <= end < length()
// 
//
String String::substr(int start, int end) const {
	String result;
	if (end < start)       return result;
	if (start >= length()) return result;
	if (start < 0)         start = 0;
	if (end >= length())   end = length() - 1;

	for (int i = start; i < end; ++i) result += str[i];

	return result;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
	out << rhs.str;
	return out;
}

std::istream& operator>>(std::istream& in, String& rhs) {
	char buffer[STRING_SIZE];
	if (in.eof())
		buffer[0] = 0;
	else
		in >> buffer;

	return in;

}