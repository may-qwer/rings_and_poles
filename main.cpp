#include <iostream>
// #include "./class/Stack.h"
// #include "./class/Queue.h"

using namespace std;

class Note {
    public: int data;
    public: Note *next;
    public: Note *prev;
};

class Queue {
    public: Note *top;
    public: Note *bot;

    Queue() {
        top = new Note;
        top->data = 0;
        top->prev = nullptr;
        bot = new Note;
        bot->data = -1;
        bot->next = nullptr;
        top->next = bot;
        bot->prev = top;        
    }


    public: int get_queue_len() {
        Note *tmp = new Note;
        int len = 0;
        tmp = top->next;
        while (tmp != bot) {
            len++;
            tmp = tmp->next;
        }
        tmp = nullptr;
        delete tmp;
        return len;
    }

    public: void push(int d) {
        Note *new_n = new Note;
        if (is_empty()) {
            bot->prev = new_n;
        }
        new_n->data = d;
        new_n->next = top->next;
        new_n->prev = top;
        new_n->next->prev = new_n;
        top->next = new_n;
    }

    public: int peek() {
        return bot->prev->data;
    }

    public: bool is_empty () {
        return get_queue_len() == 0;
    }

    public: int pop () {
        int res = 0;
        Note *tmp = bot->prev;
        bot->prev = bot->prev->prev;
        res = tmp->data;
        delete tmp;
        return res;
    }

    public: int get_el_by_num(int num) {
        int res = 0;
        Note *tmp = new Note;
        tmp = top->next;
        for (int i = 0; i<num; i++) {
            tmp = tmp->next;
        }
        res = tmp->data;
        tmp = nullptr;
        delete tmp;
        return res;
    }
};

class Game {
    private: Queue pole_one_main;
    private: Queue pole_two;
    private: Queue pole_three_finish;
    private: int len_one_str = 12;
    private: int half_len_str_without_sep = 6;

    public: Game (Queue pole_one_main, Queue pole_two, Queue pole_three_finish) {
        this->pole_one_main = pole_one_main;
        this->pole_two = pole_two;
        this->pole_three_finish = pole_three_finish;
    }

    private: void print_str(char** str) {
        for (int i=0; i<len_one_str; i++) { 
            cout <<  str[i];
        }
    }

    private: char** add_el_to_str(int data) {
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

    public: void show() {
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

    public: int get_data_from_user() {
        int user_data;
        cout << "Enter number of pole: ";
        cin >> user_data;
        if (user_data != 1 && user_data != 2 && user_data != 3) {
            cout << "You enter uncurrent number of pole!\nYou shoud enter '1', '2' or '3'.\nTry again.\n" << endl;
            user_data = get_data_from_user();
        }
        return user_data;
    
    }


    public: bool can_do_with_poles(int pole_take, int pole_put) {
        if (pole_take == pole_put) {
            cout << "You enter identical pole.\nTry again.\n";
            return false;
        }
        return true;
    }


    private: Queue* set_pole(int pole) {
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

    public: bool compare_top_of_pole(int pole_take, int pole_put) {
        Queue* pts = set_pole(pole_take);
        Queue* pps = set_pole(pole_put);
        cout << "You can't move greater ring to less ring. Try again.\n" << endl;
        cout << pps->peek() << pts->peek() << (pps->peek() < pts->peek()) << endl;
        if (pps->peek() < pts->peek()){
            return false;
        }
        return true;
    }

    public: void push_pop_poles(int pole_take, int pole_put) {
        Queue* pts = set_pole(pole_take);
        Queue* pps = set_pole(pole_put);
        int put_data = pts->pop();
        pps->push(put_data);
    }

    public: bool is_win() {
        if (pole_one_main.get_queue_len() == 0 && pole_three_finish.get_queue_len() == 5) {
            return false;
        }
        return true;
    }

    public: bool one_more_que() {
        cout << "\nWould you like to play one more game?(Y/n)";
        char *ans;
        cin >> ans;
        if (ans == "Y" || ans == "y") {
            return true;
        }
        return false;
    }

 };


int main()
{
    bool one_more = true;

    while (one_more) {
        Queue pole_one_main;
        Queue pole_two;
        Queue pole_three_finish;
    
        for (int i = 3; i<12; i += 2) {
            pole_one_main.push(i);
            // pole_two.push(0);
            // pole_three_finish.push(0);
        };
    
        Game game(pole_one_main, pole_two, pole_three_finish);

        bool running = true;

        while (running) {
            game.show();
            int pole_take;
            int pole_put;
            do {
                pole_take = game.get_data_from_user();
                pole_put = game.get_data_from_user();    
            } while (game.can_do_with_poles(pole_take, pole_put) && game.compare_top_of_pole(pole_take, pole_put));    
            
            game.push_pop_poles(pole_take, pole_put);
            running = game.is_win();
        }
        one_more = game.one_more_que();
    }

    return 0;
}
