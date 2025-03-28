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
    private: int len_one;
    private: int len_two;
    private: int len_three;
    private: char str[6];
    private: int len_one_str = 12;
    private: int half_len_str_without_sep = 6;

    public: Game (Stack pole_one_main, Stack pole_two, Stack pole_three_finish) {
        this->pole_one_main = pole_one_main;
        this->pole_two = pole_two;
        this->pole_three_finish = pole_three_finish;

        this->len_one = pole_one_main.get_stack_len();
        this->len_two = pole_two.get_stack_len();
        this->len_three = pole_three_finish.get_stack_len();
    }

    private: void print_str(char* str) {
        cout << " ";
        for (int i=0; i>len_one_str; i++) { 
            cout <<  str[i];
        }
        cout << " ";
    }

    private: char* add_el_to_str(int data) {
        char *str[len_one_str];
        if (data == 0){
            for (int i=0; i<half_len_str_without_sep; i++) {
                str[i] = " ";
            }
        }
        else {
            cout << "here" << endl;
            for (int i=0; i<len_one_str; i++) {
                cout << i << endl;
                //0 1 2 3 4 5 6 7 8 9 10 11 12
                //        ----|----              
                if (i < (half_len_str_without_sep - data)) {
                    str[i] = " ";
                }
                else if (i < half_len_str_without_sep) {
                    str[i] = "-";
                }
                else if (i == half_len_str_without_sep) {
                    str[i] = "|";
                }
                else if (i > half_len_str_without_sep && i < (len_one_str - data)) {
                    str[i] = "-";
                }
                else if (i > half_len_str_without_sep && i < len_one_str) { 
                    str[i] = " ";
                }
            }



            // for (int i=0; i<(half_len_str_without_sep-data); i++) {
            //     str[i] = " ";
            // }
            // for (int i=data; i<half_len_str_without_sep; i++) {
            //     str[i] = "-";
            // }
            // str[6] = "|";
            // for (int i=0; i<(half_len_str_without_sep-data); i++) {
            //     str[i] = "-";
            // }
            // for (int i=data; i<half_len_str_without_sep; i++) {
            //     str[i] = " ";
            // }

        }

    }    
    public: void show() {
        cout << "\n\n";
        cout << "=========================================================================";
        cout << "\n";

        print_str(add_el_to_str(0));
        print_str(add_el_to_str(1));
        print_str(add_el_to_str(2));
        print_str(add_el_to_str(3));
        print_str(add_el_to_str(4));


    }


};

int main()
{
    Stack pole_one_main;
    Stack pole_two;
    Stack pole_three_finish;

    for (int i = 11; i<3; i -= 2) {
        pole_one_main.push(i);
        pole_two.push(0);
        pole_three_finish.push(0);
    };

    Game game(pole_one_main, pole_two, pole_three_finish);
    game.show();

    //===============================================================================================

    // Stack t1;
    // t1.push(11); //4
    // t1.push(9); //3
    // t1.push(7); //2
    // t1.push(5); //1 
    // t1.push(3); //0
    // cout << "len + " << t1.get_stack_len() << endl;
    // cout << "el 5 = " << t1.get_el_by_num(5) << endl;
    // cout << "el 1 = " << t1.get_el_by_num(1) << endl;
    // cout << "el 20 = " << t1.get_el_by_num(20) << endl;
    // cout << "el 0 = " << t1.get_el_by_num(0) << endl;
    // t1.push(20);
    // cout << t1.pop() << endl;

    return 0;
}
