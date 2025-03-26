#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int b;
    b = a;
    a += 1;
    cout << "a = " << a << "  b = " << b << endl;
    cout << "&a = " << &a << "  &b = " << &b << endl;
    return 0;
}