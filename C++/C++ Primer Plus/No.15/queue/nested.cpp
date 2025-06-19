//nested.cpp -- using a queue that has a nested class
#include <iostream>
#include <string>
#include "queuetp.h"

int main()
{
    using std::string;
    using std::cout;
    using std::cin;
    QueueTP<string> cs(5);
    string temp;
    while (!cs.isfull())
    {
        cout << "Please enter your name, You will be "
                "served in the order of arrival.\n"
                "name: ";
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full, Processing begin!\n";
    while (!cs.isempty())
    {
        cs.dequeue(temp);
        cout << "Now processing: " << temp << "...\n";
    }
    return 0;
}
