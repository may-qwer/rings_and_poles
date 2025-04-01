    #include <iostream>

using namespace std;

class Note {
    public: int data;
    public: Note *next = nullptr;
    public: Note *prev = nullptr;
};

class Queue {
    public: Note *top;
    public: Note *bot;
    public: int len = 0;

    public: void push(int d) {
        Note *new_n = new Note;
        new_n->data = d;
        new_n->next = top;
        new_n->next->prev = new_n;
        top = new_n;
        if (len == 0) {
            bot = new_n;
        }
        len++;
    }

    public: int peek() {
        return bot->data;
    }

    public: bool is_empty () {
        return len == 0;
    }

    public: int get_queue_len() {
        return len;
    }

    public: int pop () {
        if (len == 0) {
            return -1;
        }
        int res = bot->data;
        Note *tmp = bot->prev;
        bot->prev = bot->prev->prev;
        delete tmp;
        len--;
        return res;
    }

    public: int get_el_by_num(int num) {
        if (num >= len) {
            return 0;
        }
        int res = 0;
        Note *tmp = new Note;
        tmp = top;
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

    t1.push(10);
    t1.push(11);
    t1.push(12);
    t1.push(13);
    t1.push(14);
    t1.push(15);

    cout << t1.top->data << t1.top->next->data << t1.top->next->next->data << t1.top->next->next->next->data << t1.top->next->next->next->next->data << t1.top->next->next->next->next->next->data  << t1.top->next->next->next->next->next->next->data  <<t1.top->next->next->next->next->next->next->data  << endl;
    cout << t1.bot->data << t1.bot->prev->data << t1.bot->prev->prev->data << t1.bot->prev->prev->prev->data << t1.bot->prev->prev->prev->prev->data << t1.bot->prev->prev->prev->prev->prev->data << endl;//  << t1.bot->prev->prev->prev->prev->prev->prev->data  <<t1.bot->prev->prev->prev->prev->prev->prev->data  << endl;

    // cout << t1.get_el_by_num(0) << endl;
    // cout << t1.get_el_by_num(1) << endl;
    // cout << t1.get_el_by_num(2) << endl;
    // cout << t1.get_el_by_num(3) << endl;
    // cout << t1.get_el_by_num(4) << endl;
    // cout << t1.get_el_by_num(5) << endl;


    return 0;
}