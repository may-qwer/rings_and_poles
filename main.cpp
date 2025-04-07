#include <iostream>
#include "Game.h"

using namespace std;


int main()
{
    bool one_more = true;

    while (one_more) {
        Dl_list pole_one_main;
        Dl_list pole_two;
        Dl_list pole_three_finish;
    
        for (int i = 3; i<12; i += 2) {
            pole_one_main.add_top(i);
        };
        // pole_three_finish.add_top(5);
        // pole_three_finish.add_top(7);
        // pole_three_finish.add_top(9);
        // pole_three_finish.add_top(11);
        // pole_two.add_top(3);
        
    
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
        game.show();
        one_more = game.one_more_que();
    }

    return 0;
}

// 
