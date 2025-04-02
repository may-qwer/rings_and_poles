#include <iostream>

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
        cout << "top = " << top << " bot = " << bot << endl;
        
    }


    public: int get_queue_len() {
        Note *tmp = new Note;
        int len = 0;
        tmp = top->next;
        while (tmp != bot) {
            len++;
            tmp = tmp->next;
        }
        delete tmp;
        return len;
    }

    public: void push(int d) {
        Note *new_n = new Note;
        new_n->data = d;
        new_n->next = top->next;
        top->next = new_n;
        new_n->prev = top;
        if (is_empty()) {
            bot->prev = new_n;
        }
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
        delete tmp;
        return res;
    }
};

int main() {
    Queue t1;
    cout << &t1 << endl;

    t1.push(10);
    t1.push(11);
    t1.push(12);
    t1.push(13);
    t1.push(14);
    t1.push(15);

    cout << t1.top->data << " " << t1.top->next << " " << t1.top->next->data << endl;


    return 0;
}