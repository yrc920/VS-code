//studenti.h -- defines a Student class using private inheritance
#ifndef STUDENTC_H__
#define STUDENTC_H__
#include <iostream>
#include <valarray>
#include <string>

class Student : private std::string, private std::valarray<double>
{
    private:
        typedef std::valarray<double> ArrayDb;
        std::ostream &arr_out(std::ostream &os) const;
    public:
        Student() : std::string("Null student"), ArrayDb() {}
        explicit Student(const std::string &s) : std::string(s), ArrayDb() {}
        explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}
        Student(const std::string &s, int n) : std::string(s), ArrayDb(n) {}
        Student(const std::string &s, const ArrayDb &a) : std::string(s), ArrayDb(a) {}
        Student(const std::string &s, const double *pd, int n) : std::string(s), ArrayDb(pd, n) {}
        ~Student() {}
        double Average() const;
        double &operator[](int i);
        double operator[](int i) const;
        const std::string &Name() const;
        friend std::istream &operator>>(std::istream &is, Student &stu);
        friend std::istream &getline(std::istream &is, Student &stu);
        friend std::ostream &operator<<(std::ostream &os, const Student &stu);
};

#endif
