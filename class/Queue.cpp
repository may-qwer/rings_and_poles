#include "Queue.h"

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

int main() {
    Queue t1;
    t1.push(10);
    t1.push(11);
    t1.push(12);
    t1.push(13);
    t1.push(14);
    t1.push(15);
    
    cout << t1.get_el_by_num(0) << endl;
    cout << t1.get_el_by_num(1) << endl;
    cout << t1.get_el_by_num(2) << endl;
    cout << t1.get_el_by_num(3) << endl;
    cout << t1.get_el_by_num(4) << endl;
    cout << t1.get_el_by_num(5) << endl; 
    cout << endl;
    
    // cout << t1.bot->data << " " << t1.bot->prev->data << " " << t1.bot->prev->prev->data << " " << t1.bot->prev->prev->prev->data << endl;
    cout << t1.peek() << endl;
    cout << t1.pop() << endl;
    cout << t1.peek() << endl;
    cout << t1.pop() << endl;
    cout << t1.peek() << endl;

    
    return 0;
}