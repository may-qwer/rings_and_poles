#include <iostream>

using namespace std;

void print_str(char** str) {
    cout << "el 0: '" << str[0] << "'" << endl;
    cout << "el 1: '" << str[1] << "'" << endl;
    cout << "el 2: '" << str[2] << "'" << endl;
    cout << "el 3: '" << str[3] << "'" << endl;
    cout << "el 4: '" << str[4] << "'" << endl;
    cout << "el 5: '" << str[5] << "'" << endl;
    cout << "el 6: '" << str[6] << "'" << endl;
    cout << "el 7: '" << str[7] << "'" << endl;
    cout << "el 8: '" << str[8] << "'" << endl;
    cout << "el 9: '" << str[9] << "'" << endl;
    cout << "el 10: '" << str[10] << "'" << endl;
}

char **create_str() {
    char **str = new char*[11];
    str[0] = "0";
    str[1] = "1";
    str[2] = "2";
    str[3] = "3";
    str[4] = "4";
    str[5] = "5";
    str[6] = "6";
    str[7] = "7";
    str[8] = "8";
    str[9] = "9";
    str[10] = "0";
    return str;

}

int main() {
    char **str = create_str();
    print_str(str);
}