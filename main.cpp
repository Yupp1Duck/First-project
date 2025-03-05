#include "header.h"
#include "npc.cpp"
#include "Mobs.cpp"
using namespace std;

int main() {
    cout << "Hello! Select an action:";
    cin >> NPC.current_dialog;
    if current_dialog == "Raid" {
        creature current_mob  == creature()
        if (current_mob.health <= 9){
            mob_name = "Little goblin";
        } elif (current_mob.health < 17){
            mob_name = "Goblin";
        } elif (current_mob.health <= 23){
            mob_name = "Elite goblin";
        } elif (current_mob.health <= 29){
            mob_name = "Little demon";
        } elif (current_mob.health <= 35){
            mob_name = "Goblin guardian";
        } elif (current_mob.health <= 44){
            mob_name = "Weak ogre";
        } elif (current_mob.health <= 59){
            mob_name = "Goblin champion *BOSS*";
        } elif (current_mob.health <= 65){
            mob_name = "Ogre *BOSS*";
        } elif (current_mob.health <= 77){
            mob_name = "Demon guardian *BOSS*";
        } elif (current_mob.health <= 83){
            mob_name = "Dragon *BOSS*";
        } elif (current_mob.health <= 99){
            mob_name = "Satan *BOSS*";
        } elif (current_mob.health > 99){
            mob_name = "Perfect being *THE STRONGEST*";
        creature current_mob  == creature(mob_name,);
    }
}

}