#include "dl_list.h"

Dl_list::Dl_list() {
    top = new Note;
    top->data = 0;
    top->prev = nullptr;
    bot = new Note;
    bot->data = -1;
    bot->next = nullptr;
    top->next = bot;
    bot->prev = top;   
}

void Dl_list::add_top(int d){
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

void Dl_list::add_bot(int d){
    Note *new_n = new Note;
    if (is_empty()) {
        top->next = new_n;
    }
    new_n->data = d;
    new_n->prev = bot->prev;
    new_n->next = bot;
    new_n->prev->next = new_n;
    bot->prev = new_n;
}

int Dl_list::get_top(){
    int res = 0;
    Note *tmp = top->next;
    top->next = top->next->next;
    top->next->prev = top;
    res = tmp->data;
    delete tmp;
    return res;
}

int Dl_list::get_bot(){
    int res = 0;
    Note *tmp = bot->prev;
    bot->prev = bot->prev->prev;
    bot->prev->next = bot;
    res = tmp->data;
    delete tmp;
    return res;
}

int Dl_list::peek_top(){
    return top->next->data;
}

int Dl_list::peek_bot(){
    return bot->prev->data;
}

bool Dl_list::is_empty(){
    return get_dll_len() == 0;
}

int Dl_list::get_dll_len(){
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

int Dl_list::get_el_by_num_top(int num){
    if (num >= get_dll_len()) {
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

int Dl_list::get_el_by_num_bot(int num){
    if (num >= get_dll_len()) {
        return 0;
    }
    int res = 0;
    Note *tmp = new Note;
    tmp = bot->prev;
    for (int i = 0; i<num; i++) {
        tmp = tmp->prev;
    }
    res = tmp->data;
    tmp = nullptr;
    delete tmp;
    return res;
}