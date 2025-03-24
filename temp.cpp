#include <iostream>

using namespace std;

int arr[5] = {1,2, 3, 4, 5};

int pop(int *arr, int c = 0) {
    if (c == 4) {
        return 5;
    }
    cout << c << endl;
    c++;
    pop(arr+1, c);
    return *arr;
};

int main() {
    cout << *(&arr[2]) << endl;
    cout << pop(arr) << endl;
    return 0;
}