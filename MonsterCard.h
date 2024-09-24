//
// Created by Ali on 9/21/2024.
//

#ifndef MONSTERCARD_H
#define MONSTERCARD_H


#include <string>
#include <utility>
#include "Card.h"
class MonsterCard final : public Card {
private:
    int health;
    int attack;
    std::string type = "Monster";
public:
    MonsterCard(const std::string &name, std::string type, const std::string &effect, const int cost, const int health, const int attack)
        : Card(name, effect, cost), health(health), attack(attack), type(std::move(type)) {};

    [[nodiscard]] std::string getType() const override { return type; }
    [[nodiscard]] int getHealth() const { return health; }
    [[nodiscard]] int getAttack() const { return attack; }
    void setHealth(const int health)    { this->health = health; }
    void setAttack(const int attack)    { this->attack = attack; }
};
#endif //MONSTERCARD_H
