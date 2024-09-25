//
// Created by Ali on 9/21/2024.
//

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Card {
protected:
    std::string cardName;
    std::string effectDescription;
    int cost;

public:
    explicit Card(std::string name, std::string effect, const int& cost);
    virtual ~Card() = default;

    [[nodiscard]] virtual std::string getType() const = 0;

    [[nodiscard]] std::string getEffectDescription() const;
    [[nodiscard]] int getCost() const;
    [[nodiscard]] std::string getName() const;

    void setName(const std::string& name);
    void setCost(const int& cost);
    void setEffectDescription(const std::string& description);

    virtual void setHealth(int health) {}
    virtual void setAttack(int attack) {}
};

#endif // CARD_H
