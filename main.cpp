#include <iostream>
#include "Queue.h"
#include "Game.h"

using namespace std;


int main()
{
    bool one_more = true;

    while (one_more) {
        Queue pole_one_main;
        Queue pole_two;
        Queue pole_three_finish;
    
        for (int i = 3; i<12; i += 2) {
            pole_one_main.push(i);
            // pole_two.push(0);
            // pole_three_finish.push(0);
        };
    
        Game game(pole_one_main, pole_two, pole_three_finish);

        bool running = true;

        while (running) {
            game.show();
            int pole_take;
            int pole_put;
            do {
                pole_take = game.get_data_from_user();
                pole_put = game.get_data_from_user();    
            } while (game.can_do_with_poles(pole_take, pole_put) && game.compare_top_of_pole(pole_take, pole_put));    
            
            game.push_pop_poles(pole_take, pole_put);
            running = game.is_win();
        }
        one_more = game.one_more_que();
    }

    return 0;
}
