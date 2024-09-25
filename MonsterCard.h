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
    MonsterCard(const std::string &name, std::string type, const std::string &effect, int cost, int health, int attack);

    [[nodiscard]] std::string getType() const override;
    [[nodiscard]] int getHealth() const;
    [[nodiscard]] int getAttack() const;

    void setHealth(int health);
    void setAttack(int attack);
};
#endif //MONSTERCARD_H
