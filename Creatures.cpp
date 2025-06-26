#include "INVandNPC.cpp"

using namespace std;


class BaseChar {
    public:
    int current_hp;
    int current_dmg;
    int power_lvl;
    BaseChar(int current_hp1, int current_dmg1, int power_lvl1): current_hp(current_hp1), current_dmg(current_dmg1), power_lvl(power_lvl1) {}
    
    
    BaseChar(): current_hp(0), current_dmg(0), power_lvl(0){}
    virtual void dmg_input(int damage){}
    virtual void plvl_init(int power_lvl, int current_dmg, int current_hp){}

    virtual int get_current_dmg(){
        return current_dmg;
    }
    virtual int get_current_hp(){
        return current_hp;
    }
    virtual int get_power_lvl(){
        return power_lvl;
    }

    
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

    void set_damage(int damage1) {
        damage = damage1;
    }

    void set_name(string name1) {
        name = name1;
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
        hp_gen = abs(rand()) % 5 + 1;  
        health = hp_gen * current.current_dmg;
        srand((unsigned)time(0));
        int dmg_gen;
        dmg_gen = abs(rand()) % 5 + 1; 
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
        
        
        main_char(int current_hp1, int current_dmg1, int power_lvl1): BaseChar(current_hp1, current_dmg1, power_lvl1){}
    
    
        main_char(): BaseChar(){}
    
        
        int get_current_hp () {
            return current_hp;
        }
        int get_current_dmg () {
            return current_dmg;
        }
        int get_power_lvl () {
            return power_lvl;
        }
        
        
        
        void set_current_hp (int current_hp1) {
            current_hp = current_hp1;
        }

        void set_current_dmg (int current_dmg1) {
            current_dmg = current_dmg1;
        }

        void set_power_lvl (int power_lvl1) {
            power_lvl = power_lvl;
        }

        void plvl_init(BaseChar current){
            current.power_lvl = round((current.current_hp + current.current_dmg) / 2);
        }

        void game_over() {
            cout << "Game over";
            exit (0);
        }

        void atk_update(Item current_inv) {
            current_dmg = current_dmg + current_inv.wpn_tier;
        }

        void dmg_input(int damage) {
            current_hp -= damage;
        }

        void atk_output(creature current_mob) {
            current_mob.damage_input(this);
        }

        void set_stats(BaseChar current){
            set_current_dmg(current.current_dmg);
            set_current_hp(current.current_hp);
            plvl_init(int current.current_dmg, int current.current_hp);
            set_power_lvl(current.power_lvl);
        }
        
    };