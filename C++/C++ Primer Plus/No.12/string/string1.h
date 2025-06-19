//string1.h -- fixed and augmented string class definition
#ifndef STRING_H__
#define STRING_H__
#include <iostream>
using std::ostream;
using std::istream;

class String
{
    private:
        char *str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;

    public:
        String(const char *s);
        String();
        String(const String &st);
        ~String();
        int length() const { return len; }
        String &operator=(const String &st);
        String &operator=(const char *s);
        char &operator[](int i);
        const char &operator[](int i) const;
        friend bool operator<(const String &str1, const String &str2);
        friend bool operator>(const String &str1, const String &str2);
        friend bool operator==(const String &str1, const String &str2);
        friend ostream &operator<<(ostream &os, const String &st);
        friend istream &operator>>(istream &is, String &st);
        static int HowMany();
};

#endif

