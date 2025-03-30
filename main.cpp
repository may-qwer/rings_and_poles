#include<iostream>

using namespace std;

class Stack {
    public: int data = -1;
    public: Stack *next;
    public: Stack *top = this;

    public: void push(int d) { 
        Stack *new_s = new Stack;
        new_s->data = d;
        new_s->next = top;
        top = new_s;
    }

    public: int peek() {
        return top->data;
    }

    public: bool is_empty() {
        return top->data == -1;
    }

    public: int get_stack_len() {
        int count = 0;
        Stack *tmp = new Stack;
        tmp->top = top;
        while (!(tmp->is_empty())) {
            count++;
            tmp->top = tmp->top->next;
        }
        delete tmp;
        return count;
    }

    public: int pop() {
        int res = top->data;
        Stack *tmp = top;
        top = top->next;
        delete tmp;
        return res;
    }

    public: int get_el_by_num(int num) {
        if (num > get_stack_len()) {
            return -2;
        }
        int res = 0;
        Stack *tmp = new Stack;
        tmp->top = top;
        for (int i = 0; i<num; i++) {
            tmp->top = tmp->top->next;
        }
        res = tmp->top->data;
        delete tmp;
        return res;
    }
};

class Game {
    private: Stack pole_one_main;
    private: Stack pole_two;
    private: Stack pole_three_finish;
    private: int len_one_str = 12;
    private: int half_len_str_without_sep = 6;

    public: Game (Stack pole_one_main, Stack pole_two, Stack pole_three_finish) {
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

        for (int i=0; i<5; i++) {
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

};

int main()
{
    bool one_more = true;

    while (one_more) {
        Stack pole_one_main;
        Stack pole_two;
        Stack pole_three_finish;
    
        for (int i = 11; i>2; i -= 2) {
            pole_one_main.push(i);
            pole_two.push(0);
            pole_three_finish.push(0);
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
            } while (game.can_do_with_poles(pole_take, pole_put));           
        }

    }

    return 0;
}
