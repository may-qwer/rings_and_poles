#include <iostream>

using namespace std;

int get_data_from_user() {
    int user_data;
    cout << "Enter number of pole: ";
    cin >> user_data;
    if (user_data != 1 && user_data != 2 && user_data != 3) {
        cout << "You enter uncurrent number of pole!\nYou shoud enter '1', '2' or '3'.\nTry again.\n" << endl;
        user_data = get_data_from_user();
    }
    return user_data;

}


int main() {
    int ud;
    ud = get_data_from_user();
    cout << ud << endl;


    return 0;
}