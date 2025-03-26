#include <iostream> 

using namespace std;

//==========================================================

class Stack {
public:
    int data = -1;
    Stack *next;   

    void push (Stack *s, int data) {
        // Stack *tmp = new Stack;
        // tmp->data = data;
        // tmp->next = s;
        // s = tmp;
        // delete tmp;
    }

    bool is_empty (Stack *s) {
        return s->data == -1;
    }
 
    int pop (Stack *s) {
        if (!(s->is_empty(s))) {
            Stack *tmp = new Stack;
            cout << s->next->data << endl;
            tmp->data = s->next->data;
            tmp->next = s->next->next; 
            int res = s->data;
            *s = *tmp;
            delete tmp;
            return res;
        }
        return 0;
    }

    int peek (Stack *s) {
        return s->data;
    }

    int stack_len (Stack *s, int count = 1) {
        if (s->data == -1) {
            return count;
        }
        count++;
        stack_len(s = s->next, count);
    }

};

//==========================================================

int main() {
    Stack t1;
    cout << " " << endl;

    t1.push(&t1, 10);
    cout << t1.peek(&t1) << endl;
    t1.push(&t1, 11);
    cout << t1.peek(&t1) << endl;
    t1.push(&t1, 12);
    cout << t1.peek(&t1) << endl;


    cout << t1.pop(&t1) << endl;
    cout << t1.peek(&t1) << endl;

    cout << " " << endl;
    return 0;
}