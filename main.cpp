#include <iostream> 

using namespace std;

//==========================================================

class Stack {
public:
    int data = NULL;
    Stack *next;   

    void push(Stack *s, int data);
    int pop(Stack *s);
    int peek(Stack *s);
    int stack_len(Stack *s, int count = 1);
    bool is_empty(Stack *s);


    void push (Stack *s, int data) {
        Stack *tmp = new Stack;
        tmp->data = data;
        tmp->next = s;
        s = tmp;
        delete tmp;
    }

    int pop (Stack *s) {
        Stack *tmp = s;
        s = s->next;
        int res = tmp->data;
        delete tmp;
        return res;
    }

    int peek (Stack *s) {
        return s->data;
    }

    bool is_empty (Stack *s) {
        return s->data == NULL;
    }

    int stack_len (Stack *s, int count = 1) {
        if (s->data == NULL) {
            return count;
        }
        count++;
        stack_len(s = s->next, count);
    }

};

//==========================================================

int main() {


    return 0;
}