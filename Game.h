#include "dl_list.h"

class Game {
    private: Dl_list pole_one_main;
    private: Dl_list pole_two;
    private: Dl_list pole_three_finish;
    private: int len_one_str = 12;
    private: int half_len_str_without_sep = 6;

    public: Game (Dl_list pole_one_main, Dl_list pole_two, Dl_list pole_three_finish);

    private: void print_str(char** str);

    private: char** add_el_to_str(int data);

    public: void show();

    public: int get_data_from_user();

    public: bool can_do_with_poles(int pole_take, int pole_put);

    private: Dl_list* set_pole(int pole);

    public: bool compare_top_of_pole(int pole_take, int pole_put);

    public: void push_pop_poles(int pole_take, int pole_put);

    public: bool is_win();

    public: bool one_more_que();
 };