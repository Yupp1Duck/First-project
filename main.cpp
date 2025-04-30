#include "Creatures.cpp"
using namespace std;

int main() {
    BaseNpc current_npc = NPC(1, 0, "Default");
    Item current_inv = Item(1,1,1,1,1,1,1);
    main_char current = main_char(1,1,1,1);
    cout << "Hello! Select an action:";
    cin >> current_npc.current_dialog;
    if (current_npc.current_dialog == "Raid") {
        creature current_mob = creature(0,0,"");
        current_mob.mobGenerating(current);
        if (current_mob.health <= 9){
            current_mob.set_name("Little goblin");
        } else if (current_mob.health < 17){
            current_mob.set_name("Goblin");
        } else if (current_mob.health <= 23){
            current_mob.set_name("Elite goblin");
        } else if (current_mob.health <= 29){
            current_mob.set_name("Little demon");
        } else if (current_mob.health <= 35){
            current_mob.set_name("Goblin guardian");
        } else if (current_mob.health <= 44){
            current_mob.set_name("Weak ogre");
        } 
        cout << "Generated!" << '\n' << "Here's: ";
        cout << current_mob.get_name();
    }

    return 0;
}

