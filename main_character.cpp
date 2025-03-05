#include "header.h"
#include "Mobs.cpp"
using namespace std;

class main_char {
public:
    int: base_hp;
    int: base_dmg;
    int: current_hp;
    int: current_dmg;

    main_char(int base_hp1, int base_dmg1, int current_hp1, int current_dmg1 ): base_hp(base_hp1), base_dmg(base_dmg1), current_hp(current_hp1), current_dmg(current_dmg1), {}


    main_char(): base_hp(0), base_dmg(0), current_hp(0), current_dmg(0){}

    void game_over() {
        cout << "Game over";
        break;
    }
    void atk_update() {
        current_dmg = base_dmg + wpn_tier;
    }
    void dmg_input(int damage) {
        current_hp -= damage;
    } 
    void atk_output(creature current_mob) {
        current_mob.damage_input(current_dmg);
    }

    
};

