#include "Stack.h"

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
};