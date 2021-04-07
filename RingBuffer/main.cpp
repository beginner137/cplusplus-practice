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

    for (int i = 0; i < textring.size(); i++)
    {
        cout << textring.get(i) << endl;
    }
    return 0;
}