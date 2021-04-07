#include <iostream>
#include <string>
#include "ring.h"

using namespace std;

int main()
{
    ring<string> textring(3);
    textring.add("first");
    textring.add("second");
    textring.add("three");
    textring.add("four");

    // use iterator to iterate through the buffer
    // c++ 98
    for (ring<string>::iterator it = textring.begin(); it != textring.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl;
    // c++ 11
    for (auto val : textring)
    {
        cout << val << endl;
    }
    return 0;
}