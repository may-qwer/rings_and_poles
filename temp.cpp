#include <iostream>

using namespace std;

class Tmp {
    int data = 3;

};

class T {
    Tmp tmp;

    void tmp_def() {
        Tmp *ttmp = &tmp;
        ttmp->data++;
        cout << 
    }
};


int main() {
    Tmp t = ret_tmp();
    cout << &t << endl;


    return 0;
}