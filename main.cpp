#include "Creatures.cpp"
using namespace std;

int main() {
    NPC current_npc = NPC(1, 0, "Default");
    Item current_inv = Item(1,1,1,1,1,1,1);
    main_char current = main_char(1,1);
    if (current_npc.current_dialog == "Default"){
        cout << "Hello! Select an action:";}
    cin >> current_npc.current_dialog;
    if (current_npc.current_dialog == "Raid") {
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
        while (raid_current > 0)
        {
            current_npc.set_dialog("In battle");
            current.atk_update(current_inv);
            cin >> current_npc.current_dialog;
            if (current_npc.current_dialog == "Attack"){
                current.atk_output(current_mob);
                current_mob.damage_input(&current);
                cout << "Now " << current_mob.name << " have " << current_mob.health << " hp!" << '\n';
                if (current_mob.health <= 0){
                    cout << "You won!";
                    raid_current = 0;
                    break;
                }
                
            }
            current_mob.attack(current);
                current.dmg_input(current_mob.damage);
                if (current.current_hp >= 0){
                    cout << "You died";
                    return 0;
                }
        }
        current_npc.set_dialog("Default");
    }

    return 0;
}

