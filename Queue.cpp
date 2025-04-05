#include "Queue.h"


Queue::Queue() {
    top = new Note;
    top->data = 0;
    top->prev = nullptr;
    bot = new Note;
    bot->data = -1;
    bot->next = nullptr;
    top->next = bot;
    bot->prev = top;        
}

int Queue::get_queue_len() {
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

void Queue::push(int d) {
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

int Queue::peek() {
    return bot->prev->data;
}

bool Queue::is_empty () {
    return get_queue_len() == 0;
}

int Queue::pop () {
    int res = 0;
    Note *tmp = bot->prev;
    bot->prev = bot->prev->prev;
    bot->prev->next = bot;
    res = tmp->data;
    delete tmp;
    return res;
}

int Queue::get_el_by_num(int num) {
    if (num >= get_queue_len()) {
        return 0;
    }
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
