#include "note.h"
#ifndef QUEUE_H
#define QUEUE_H



class Queue {
    public: Note *top;
    public: Note *bot;

    Queue();


    public: int get_queue_len();

    public: void push(int d);

    public: int peek();

    public: bool is_empty ();

    public: int pop ();

    public: int get_el_by_num(int num);
};

#endif
