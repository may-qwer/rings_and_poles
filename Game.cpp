#include "Game.h"
#include "dl_list.h"
#include <iostream>
#include <stdio.h>
using namespace std; 


Game::Game (Dl_list pole_one_main, Dl_list pole_two, Dl_list pole_three_finish) {
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
        print_str(add_el_to_str(this->pole_one_main.get_el_by_num_top(i)));
        cout << "  ";
        print_str(add_el_to_str(this->pole_two.get_el_by_num_top(i)));
        cout << "  ";
        print_str(add_el_to_str(this->pole_three_finish.get_el_by_num_top(i)));
        cout << "\n";
    }
    cout << "\n\n";
}

int Game::get_data_from_user() {
    int user_data;
    cout << "Enter number of pole: ";
    cin >> user_data;
    if (user_data != 1 && user_data != 2 && user_data != 3) {
        cout << "\033[31mYou enter uncurrent number of pole!\nYou shoud enter '1', '2' or '3'.\033[0m\nTry again.\n" << endl;
        user_data = get_data_from_user();
    }
    return user_data;

}


bool Game::can_do_with_poles(int pole_get, int pole_set) {
    if (pole_get == pole_set) {
        cout << "\033[31mYou enter identical pole.\033[0m\nTry again.\n";
        return false;
    }
    return true;
}


Dl_list* Game::set_pole(int pole) {
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

bool Game::compare_top_of_pole(int pole_get, int pole_set) {
    Dl_list* pg_dll = set_pole(pole_get);
    Dl_list* ps_dll = set_pole(pole_set);
    int g = pg_dll->peek_bot();
    int s = ps_dll->peek_bot();
    if ((pg_dll->peek_bot() < ps_dll->peek_bot()) || (ps_dll->peek_bot() == 0)){
        return false;
    }
    cout << "\033[31mYou can't move greater ring to less ring.\033[0m\nTry again.\n" << endl;
    return true;
}

void Game::push_pop_poles(int pole_get, int pole_set) {
    Dl_list* pg_dll = set_pole(pole_get);
    Dl_list* ps_dll = set_pole(pole_set);
    ps_dll->add_bot(pg_dll->get_bot());
}

bool Game::is_win() {
    if (pole_one_main.get_dll_len() == 0 && pole_three_finish.get_dll_len() == 5) {
        return false;
    }
    return true;
}

bool Game::one_more_que() {
    cout << 
    "\nYou WIN!!! \033[31mC\033[32mO\033[33mN\033[34mG\033[35mR\033[36mA\033[31mT\033[32mU\033[33mL\033[34mA\033[35mT\033[36mI\033[31mO\033[32mN\033[33m!\033[34m!\033[35m!\033[0m\n"
     << endl;
    cout << "\nWould you like to play one more game?(Y/n)";
    char ans;
    cin >> ans;
    cout << ans << " " << &ans << " " << endl;
    if (ans == 89/*Y*/ || ans == 121/*y*/) {
        return true;
    }
    return false;
}

