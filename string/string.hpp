#ifndef CS2_STRING
#define CS2_STRING

#include <iostream>
const int STRING_SIZE = 256; // String capacity + 1 (for null terminator)

///////////////////////////////////////////////////////////
// CLASS INV: 0 <= length() <= capacity() &&             //
//            capcity() == STRING_SIZE -1 &&             //
//            str(length()) == 0          &&             //
//              can only access str[0, ... , length() - 1) //
///////////////////////////////////////////////////////////


class String {
public:
    String();
    String(char);
    String(const char[]);

    int     capacity() const { return STRING_SIZE - 1; }
    int     length()   const;
    char    operator[](int) const; //Accessor/Getter
    char&   operator[](int);       //Modifier/Setter

    String  operator+(const String&) const;
    String& operator+=(const String&);

    bool   operator==(const String&) const;  // These two are methods! Define the rest with these two operators.
    bool   operator< (const String&) const;
    String substr    (int, int) const;
    int    findchar  (int, char) const;
    int    findsubstr(int, const String&) const;

    friend std::ostream& operator<<(std::ostream&, const String&);

private:
    char str[STRING_SIZE];
};


std::istream& operator>>(std::istream&, String&);

String operator+(char, const String&);
String operator+(const char[], const String&);
//String operator+(String, const String&);

bool operator==(char, const String&);
bool operator==(const char[], const String&);
bool operator< (char, const String&);
bool operator< (const char[], const String&);
bool operator!=(const String&, const String&);
bool operator>=(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator> (const String&, const String&);

#endif