//strquote.cpp -- different designs

#include <iostream>
#include <cstring>
using namespace std;
string version1(const string & s, const char * cstr);
const string version2(string & s, const string & str);
const string version3(string & s, const char * cstr);
int main()
{
    string input;
    string copy;
    string result;
    cout << "Enter a string :";
    getline(cin, input);
    copy = input;
    cout << "Your string as entered: "<< input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: "<< result << endl;
    cout<<"Your original string: "<< input << endl;
    result = version2(copy, "###");
    cout << "Your string enhanced: "<< result << endl;
    cout<<"Your original string: "<< copy << endl;
    cout << "Resetting original string.\n";
    copy = input;
    result = version3(copy, "@@@");
    cout << "Your string enhanced: "<< result << endl;
    cout << "Your original string: " << copy << endl;
    return 0;
}

string version1(const string & s1, const char * s2)
{
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}
const string version2(string & s1, const string & s2)
{
    s1 = s2 + s1 + s2;
    return s1;
}
const string version3(string & s1, const char * s2)
{
    string temp;
    temp = s2 + s1 + s2;
    return s1;
}

