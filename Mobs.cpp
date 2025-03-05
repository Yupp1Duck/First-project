#include "header.h"
#include "main_character.cpp"
#include "inventory.cpp"
using namespace std;

class creature {
public:
    string: name;
    int: damage;
    int: health;

    creature(int damage1, int health1, string name1): damage(damage1), health(health1), name(name1) {}

    creature(): damage(0), health(0), name("") {}

    void attack(main_char current) {
        current.dmg_input(damage);
    }
    void damage_input(int current_dmg) {
        health -= main_char.current_dmg;
    }

    void drop(item current_inv) {
        if (health <= 10) {
            current_inv.loot_low =+ 1;
        }
        elif (health <= 17) {
            current_inv.loot_mid =+ 1;
        }
        elif (health <= 25) {
            current_inv.loot_high =+ 1;
        }
    }
}

class Boss : public creature {
    void boss_drop(item current_inv) {
        current_inv.loot_boss += round(health * 0.4);
    }
}