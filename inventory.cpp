#include "header.h"
#include "NPC.cpp" 
using namespace std;

class item {
public:
    
    int: armor_tier;
    int: wpn_tier;
    int: loot_low;
    int: loot_mid;
    int: loot_high;
    int: loot_boss;
    int: money;
    int loot_low_multipler = 0.6;
    int loot_mid_multipler = 0.8;
    int loot_high_multipler = 1.6;
    int loot_boss_multipler = 2.4;

    item(int armor_tier1, int wpn_tier1, int loot_mid1, int loot_high1, int loot_boss1, int money1): armor_tier(armor_tier1), wpn_tier(wpn_tier1), loot_mid(loot_mid1), loot_high(loot_high1), loot_boss(loot_boss1), money(money1) {}


    item(): armor_tier(0), wpn_tier(0), loot_mid(0), loot_high(0), loot_boss(0), money(0) {}

    void sell(NPC current_npc) {
        money += loot_low_multipler * current_npc.reputation * loot_low;
        money += loot_mid_multipler * current_npc.reputation * loot_mid;
        money += loot_high_multipler * current_npc.reputation * loot_high;
        money += loot_boss_multipler * loot_boss;
    }
}