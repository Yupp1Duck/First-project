#include "header.h"
#include "inventory.cpp"
#include "Mobs.cpp"
using namespace std;
class NPC {
public: 
    string current_dialog;
    int reputation;
    int quests_lvl;
    vector<int> arm_prices;
    vector<int> arm_prices = {2, 5, 10, 15, 20, 28, 36, 45, 55, 70};
    vector<int> wpn_prices;
    vector<int> wpn_prices = {2, 5, 10, 15, 20, 28, 36, 45, 55, 70};

    NPC(int reputation1, int quests_lvl1, string current_dialog1): quests_lvl(quests_lvl1), reputation(reputation1), current_dialog(current_dialog1) {}

    NPC(): quests_lvl(0), reputation(1), current_dialog("") {}

    void buy(item current_inv) {
        if (current_dialog == "ArmorShop") {
            cout << "Select armor tier(1-10)";
            int select_tier;
            cin >> select_tier;
            if money < arm_prices[select_tier] {
                cout << "Not enough money";
                current_dialog = "Default";
            } if money > arm_prices[select_tier] {
                cout << "You bought" << select_tier + "th" << "tier armor";
                money -= arm_prices[select_tier];
            }
        }
        if (current_dialog == "WeaponShop") {
            cout << "Select weapon tier";
            int select_wpn_tier;
            cin >> select_wpn_tier;
            if money < wpn_prices[select_wpn_tier] {
                cout << "Not enough money";
                current_dialog = "Default";
            } if money > wpn_prices[select_wpn_tier] {
                cout << "You bought" << select_wpn_tier + "th" << "tier weapon";
                money -= wpn_prices[select_wpn_tier];
            }
        }
    }
}