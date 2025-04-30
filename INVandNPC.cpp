#include "header.h"
using namespace std;
class BaseNpc {
    public:
    string current_dialog;
    int reputation;
    int quests_lvl;
    vector<int> arm_prices;
    
    vector<int> wpn_prices;
    

};
class Item {
public:
    
    int armor_tier;
    int wpn_tier;
    int loot_low;
    int loot_mid;
    int loot_high;
    int loot_boss;
    int money;
    double loot_low_multipler = 0.6;
    double loot_mid_multipler = 0.8;
    double loot_high_multipler = 1.6;
    double loot_boss_multipler = 2.4;

    Item(int armor_tier1, int wpn_tier1, int loot_low1, int loot_mid1, int loot_high1, int loot_boss1, int money1): armor_tier(armor_tier1), wpn_tier(wpn_tier1), loot_low(loot_low1), loot_mid(loot_mid1), loot_high(loot_high1), loot_boss(loot_boss1), money(money1) {}


    Item(): armor_tier(0), wpn_tier(0), loot_low(0), loot_mid(0), loot_high(0), loot_boss(0), money(0) {}

    void sell(BaseNpc current_npc) {
        money += loot_low_multipler * current_npc.reputation * loot_low;
        money += loot_mid_multipler * current_npc.reputation * loot_mid;
        money += loot_high_multipler * current_npc.reputation * loot_high;
        money += loot_boss_multipler * loot_boss;
    }
};

class NPC : virtual public BaseNpc{
    public: 
        string current_dialog;
        int reputation;
        int quests_lvl;
        
        vector<int> arm_prices = {2, 5, 10, 15, 20, 28, 36, 45, 55, 70};
        
        vector<int> wpn_prices = {2, 5, 10, 15, 20, 28, 36, 45, 55, 70};
    
        NPC(int quests_lvl1, int reputation1, string current_dialog1): quests_lvl(quests_lvl1), reputation(reputation1), current_dialog(current_dialog1) {}
    
        NPC(): quests_lvl(0), reputation(1), current_dialog("") {}
    
        void buy(Item current_inv) {
            if (current_dialog == "ArmorShop") {
                cout << "Select armor tier(1-10)";
                int select_tier;
                cin >> select_tier;
                if (current_inv.money < arm_prices[select_tier]) {
                    cout << "Not enough money";
                    current_dialog = "Default";
                } if (current_inv.money > arm_prices[select_tier]) {
                    cout << "You bought" << select_tier + "th" << "tier armor";
                    current_inv.money -= arm_prices[select_tier];
                    current_dialog = "Default";
                }
            }
            if (current_dialog == "WeaponShop") {
                cout << "Select weapon tier";
                int select_wpn_tier;
                cin >> select_wpn_tier;
                if (current_inv.money < wpn_prices[select_wpn_tier]) {
                    cout << "Not enough money";
                    current_dialog = "Default";
                } if (current_inv.money > wpn_prices[select_wpn_tier]) {
                    cout << "You bought" << select_wpn_tier + "th" << "tier weapon";
                    current_inv.money -= wpn_prices[select_wpn_tier];
                    current_dialog = "Default";
                }
            }
        }
    };