#include "Stack.h"

void Stack::push(int d) { 
    Stack *new_s = new Stack;
    new_s->data = d;
    new_s->next = top;
    top = new_s;
}

int Stack::peek() {
    return top->data;
}

bool Stack::is_empty() {
    return top->data == -1;
}

int Stack::get_stack_len() {
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

int Stack::pop() {
    int res = top->data;
    Stack *tmp = top;
    top = top->next;
    delete tmp;
    return res;
}

int Stack::get_el_by_num(int num) {
    if (num >= get_stack_len()) {
        return 0;
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