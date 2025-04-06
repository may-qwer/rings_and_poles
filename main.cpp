#include <iostream>
#include "dl_list.h"
#include "Game.h"

using namespace std;


int main()
{
    bool one_more = true;

    while (one_more) {
        Dl_list pole_one_main;
        Dl_list pole_two;
        Dl_list pole_three_finish;
    
        for (int i = 13; i>2; i -= 2) {
            pole_one_main.add_top(i);
        };
    
        Game game(pole_one_main, pole_two, pole_three_finish);

        bool running = true;
        while (running) {
            game.show();
            int pole_get;
            int pole_set;
            do {
                cout << "Choose pole to take ring. ";
                pole_get = game.get_data_from_user(); 
                cout << "Choose pole to set ring. ";
                pole_set = game.get_data_from_user();    
            } while (game.can_do_with_poles(pole_get, pole_set) && game.compare_top_of_pole(pole_get, pole_set));    
            
            game.push_pop_poles(pole_get, pole_set);
            running = game.is_win();
        }
        one_more = game.one_more_que();
    }

    return 0;
}
