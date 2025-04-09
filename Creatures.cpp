#include "INVandNPC.cpp"

using namespace std;


class BaseChar {
    public:
    int base_hp;
    int base_dmg;
    int current_hp;
    int current_dmg;
    virtual void dmg_input(int damage){}
    virtual void get_current_dmg(int damage){}
    
};

class creature {
    public:
    string name;
    int damage;
    int health;    
    creature(int damage1, int health1, string name1): damage(damage1), health(health1), name(name1) {}

    creature(): damage(0), health(0), name("") {}
    
    int get_damage () {
        return damage;
    }
    int get_health () {
        return health;
    }
    string get_name () {
        return name;
    }

    void attack(BaseChar current) {
        current.dmg_input(damage);
    }
    void damage_input(BaseChar * current) {
        health -= current -> current_dmg;
    }

    void drop(Item current_inv) {
        if (health <= 10) {
            current_inv.loot_low =+ 1;
        }
        else if (health <= 17) {
            current_inv.loot_mid =+ 1;
        }
        else if (health <= 25) {
            current_inv.loot_high =+ 1;
        }
    }

    void mobGenerating(BaseChar current){
        srand((unsigned)time(0));
        int hp_gen;
        hp_gen = rand() % 5 + 1;  
        health = hp_gen * current.current_dmg;
        srand((unsigned)time(0));
        int dmg_gen;
        dmg_gen = rand() % 5 + 1; 
        damage = hp_gen * current.current_hp;
    }
};

class Boss : public creature {
    void boss_drop(Item current_inv) {
        current_inv.loot_boss += round(health * 0.4);
    }
};

class main_char : virtual public BaseChar {
    public:
        
        int base_hp;
        int base_dmg;
        int current_hp;
        int current_dmg;
        main_char(int base_hp1, int base_dmg1, int current_hp1, int current_dmg1 ): base_hp(base_hp1), base_dmg(base_dmg1), current_hp(current_hp1), current_dmg(current_dmg1) {}
    
    
        main_char(): base_hp(0), base_dmg(0), current_hp(0), current_dmg(0){}
    
        int get_base_hp () {
            return base_hp;
        }
        int get_current_hp () {
            return current_hp;
        }
        int get_current_dmg () {
            return current_dmg;
        }
        int get_base_dmg () {
            return base_dmg;
        }


        
        void game_over() {
            cout << "Game over";
            exit (0);
        }
        void atk_update(Item current_inv) {
            current_dmg = base_dmg + current_inv.wpn_tier;
        }
        void dmg_input(int damage) {
            current_hp -= damage;
        } 
        void atk_output(creature current_mob) {
            current_mob.damage_input(this);
        }
    
        
    };