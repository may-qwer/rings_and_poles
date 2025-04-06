#include "Queue.h"

class Dl_list {
    public:
    public: Note *top;
    public: Note *bot;

    Dl_list();

    void add_top(int d);

    void add_bot(int d);

    int get_top();

    int get_bot();

    int peek_top();

    int peek_bot();

    bool is_empty();

    int get_dll_len();

    int get_el_by_num_top(int num);

    int get_el_by_num_bot(int num);

};
