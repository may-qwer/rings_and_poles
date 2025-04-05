#include "Game.h"
#include "Queue.h"
#include <iostream>
using namespace std; 


Game::Game (Queue pole_one_main, Queue pole_two, Queue pole_three_finish) {
    this->pole_one_main = pole_one_main;
    this->pole_two = pole_two;
    this->pole_three_finish = pole_three_finish;
}

void Game::print_str(char** str) {
    for (int i=0; i<len_one_str; i++) { 
        cout <<  str[i];
    }
}

char** Game::add_el_to_str(int data) {
    char **str = new char*[len_one_str];
    for (int i=0; i<len_one_str; i++) {
        //i = 0 1 2 3 4 5 6 7 8 9 10 11 12
        //str[i]           -|-              
        //len_one_str = 12;
        //half_len_str_without_sep = 6;
        //data = 3
        if (i < (half_len_str_without_sep - (data-1)/2)) { // i < 6-(3-1)/2; i < 5
            str[i] = " ";
        }
        else if (i < half_len_str_without_sep) { // i < 6
            str[i] = "=";
        }
        else if (i == half_len_str_without_sep) { // i == 6 
            str[i] = "|";
        }
        else if (i > half_len_str_without_sep && i <= (half_len_str_without_sep + (data-1)/2)) { // i > 6 && i <= 6 + 1
            str[i] = "=";
        }
        else if (i > half_len_str_without_sep && i < len_one_str) { // i > 6 && i < 12
            str[i] = " ";
        }
    }
    // }
    return str;
}   

void Game::show() {
    cout << "\n\n";
    cout << "---------------------------------------------------------------------";
    cout << "\n\n";
    cout << "      1      " << " " << "      2      " << " " << "      3      " << endl;

    for (int i=4; i>-1; i--) {
        print_str(add_el_to_str(this->pole_one_main.get_el_by_num(i)));
        cout << "  ";
        print_str(add_el_to_str(this->pole_two.get_el_by_num(i)));
        cout << "  ";
        print_str(add_el_to_str(this->pole_three_finish.get_el_by_num(i)));
        cout << "\n";
    }
    cout << "\n\n";
}

int Game::get_data_from_user() {
    int user_data;
    cout << "Enter number of pole: ";
    cin >> user_data;
    if (user_data != 1 && user_data != 2 && user_data != 3) {
        cout << "You enter uncurrent number of pole!\nYou shoud enter '1', '2' or '3'.\nTry again.\n" << endl;
        user_data = get_data_from_user();
    }
    return user_data;

}


bool Game::can_do_with_poles(int pole_take, int pole_put) {
    if (pole_take == pole_put) {
        cout << "You enter identical pole.\nTry again.\n";
        return false;
    }
    return true;
}


Queue* Game::set_pole(int pole) {
    if (pole == 1) {
        return &pole_one_main;
    }
    else if (pole == 2) {
        return &pole_two;
    }
    else {
        return &pole_three_finish;
    }
} 

bool Game::compare_top_of_pole(int pole_take, int pole_put) {
    Queue* ptq = set_pole(pole_take);
    Queue* ppq = set_pole(pole_put);
    if (ppq->peek() < ptq->peek()){
        return false;
    }
    cout << "You can't move greater ring to less ring. Try again.\n" << endl;
    return true;
}

void Game::push_pop_poles(int pole_take, int pole_put) {
    Queue* ptq = set_pole(pole_take);
    Queue* ppq = set_pole(pole_put);
    ppq->push(ptq->pop());
}

bool Game::is_win() {
    if (pole_one_main.get_queue_len() == 0 && pole_three_finish.get_queue_len() == 5) {
        return false;
    }
    return true;
}

bool Game::one_more_que() {
    cout << "\nWould you like to play one more game?(Y/n)";
    char *ans;
    cin >> ans;
    if (ans == "Y" || ans == "y") {
        return true;
    }
    return false;
}

