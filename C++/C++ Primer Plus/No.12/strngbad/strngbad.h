//strngbad.h -- flexible string class declaration
#include <iostream>
#ifndef STRINGBAD_H__
#define STRINGBAD_H__

class StringBad
{
    private:
        char *str;
        int len;
        static int num_strings;

    public:
        StringBad(const char *s);
        StringBad();
        ~StringBad();
        friend std::ostream &operator<<(std::ostream &os, const StringBad &st);
};

#endif

