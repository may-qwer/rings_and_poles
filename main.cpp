#include<iostream>

using namespace std;

class Stack {
public:
    int data = -1;
    Stack *next;
    Stack *top = this;

    void push(int d) { 
        Stack *new_s = new Stack;
        new_s->data = d;
        new_s->next = top;
        top = new_s;
    }

    int peek() {
        return top->data;
    }

    bool is_empty() {
        return top->data == -1;
    }

    int get_stack_len() {
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

    int pop() {
        int res = top->data;
        Stack *tmp = top;
        top = top->next;
        delete tmp;
        return res;
    }
};

int main()
{
    Stack t1;
    cout << t1.get_stack_len() << endl;

    t1.push(10);
    t1.push(11);
    t1.push(12);
    t1.push(13);
    t1.push(14);
    t1.push(15);
    
    cout << t1.get_stack_len() << endl;

    cout << t1.pop() << endl;
    cout << t1.peek() << endl;

    cout << t1.pop() << endl;
    cout << t1.peek() << endl;

    cout << t1.pop() << endl;
    cout << t1.peek() << endl;

    cout << t1.pop() << endl;
    cout << t1.peek() << endl;

    cout << t1.get_stack_len() << endl;

    cout << t1.is_empty() << endl;

    t1.push(22);

    cout << t1.peek() << endl;

    return 0;
}
