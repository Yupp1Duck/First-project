#include "Creatures.cpp"
using namespace std;

int main() {
    NPC current_npc = NPC(1, 0, "Default");
    Item current_inv = Item(1,1,0,0,0,0,1);
    main_char current = main_char(0,0,0,2,4,2);
    cout << '\n' << "Hello!";
    while (true) {
        if (current_npc.current_dialog == "Default"){
            cout << '\n' <<"Select an action: ";
            current.set_stats(current);}
        cin >> current_npc.current_dialog;
        if (current_npc.current_dialog == "Exit"){
            cout << '\n' <<"bye!";
            return 0;
        }
        if (current_npc.current_dialog == "Inv") {
            cout << "Power level: " << current.get_power_lvl() << '\n';
            cout << "Money " << current_inv.money << '\n';
            cout << "Weapon"<< "\t" << "Armor" << "\t" << "Artifacts" << "\t" << "class placeholder" << "\n" << "T" << current_inv.get_wpnt() << "\t" << "T" << current_inv.get_armt() << "\t" << "Savior sign x" << current.get_svr() << "\t" << "placeholderStr1";
            cout << '\n' << "" << "\t" << ""  << "\t" << "Monarch soul x" << current.get_srp() << "\t" << "placeholderStr2";
            cout <<'\n'<< "" << "\t" << ""  << "\t" << "Demon blood x" << current.get_blood() << "\t" << "placeholderStr3";
            cout <<'\n' << "Goblin's ear: x" << current_inv.get_loot_l();
            cout <<'\n' << "Imp horn: x" << current_inv.get_loot_m();
            cout <<'\n' << "Ogre's eye: x" << current_inv.get_loot_h();
            current_npc.set_dialog("Default");
        } 
        if (current_npc.current_dialog == "Raid") {
            vector<int> save_stats;
            save_stats.push_back(current.get_current_hp());
            save_stats.push_back(current.get_current_dmg());
            creature current_mob = creature(0,0,"");
            current_mob.mobGenerating(current);
            int raid_current;
            raid_current = 0;
            if (current_mob.health <= 9){
                current_mob.set_name("Little goblin");
                raid_current = 1;
            } else if (current_mob.health < 17){
                current_mob.set_name("Goblin");
                raid_current = 1;
            } else if (current_mob.health <= 23){
                current_mob.set_name("Elite goblin");
                raid_current = 1;
            } else if (current_mob.health <= 29){
                current_mob.set_name("Little demon");
                raid_current = 1;
            } else if (current_mob.health <= 35){
                current_mob.set_name("Goblin guardian");
                raid_current = 1;
            } else if (current_mob.health <= 44){
                current_mob.set_name("Weak ogre");
                raid_current = 1;
            } 
            cout << "Generated!" << '\n' << "Here's: ";
            cout << current_mob.get_name() << '\n';
            
            current_mob.save_mob.push_back(current_mob.get_health());
            while (raid_current > 0)
            {
                current_npc.set_dialog("In battle");
                current.atk_update(current_inv);
                cin >> current_npc.current_dialog;
                if (current_npc.current_dialog == "Attack"){
                    current.atk_output(current_mob);
                    current_mob.damage_input(&current);
                    cout << "Mob got " << current.current_dmg << " dmg!" << '\n';
                    cout << "Now " << current_mob.name << " have " << current_mob.health << " hp!" << '\n';
                    if (current_mob.health <= 0){
                        cout << "You won!";
                        raid_current = 0;
                        current_mob.drop(current_inv, current_mob);
                        current_npc.set_dialog("Default");
                        current.set_current_hp(save_stats[0]);
                        current.set_current_dmg(save_stats[1]);
                    }
                    
                }
                current_mob.attack(current);
                    current.dmg_input(current_mob.damage);
                    cout << "You got " << current_mob.damage << " damage!" << '\n';
                    cout << "Now you have " << current.current_hp << " hp!" << '\n';
                    if (current.current_hp <= 0){
                        cout << "You died";
                        raid_current = 0;
                        current_npc.set_dialog("Default");
                        current.set_current_hp(save_stats[0]);
                        current.set_current_dmg(save_stats[1]);
                    }
            }
            current_npc.set_dialog("Default");
        }
    }
    return 0;
}

