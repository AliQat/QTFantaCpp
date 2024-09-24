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
    explicit Card(std::string name, std::string effect, const int& cost)
        : cardName(std::move(name)), effectDescription(std::move(effect)), cost(cost) {};
    virtual ~Card() = default;
    [[nodiscard]] virtual std::string getType() const = 0;
    [[nodiscard]] std::string getEffectDescription() const {
        if (effectDescription.empty()) {
            throw std::runtime_error("Effect description is empty.");
        }
        return effectDescription;
    }
    [[nodiscard]] int getCost() const {
        if (cost < 0) {
            throw std::runtime_error("Cost cannot be negative.");
        }
        return cost;
    }
    [[nodiscard]] std::string getName() const {
        if (cardName.empty()) {
            throw std::runtime_error("Card name is empty.");
        }
        return cardName;
    }
    void setName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("Card name cannot be empty.");
        }
        this->cardName = name;
    }

    void setCost(const int& cost) {
        if (cost < 0) {
            throw std::invalid_argument("Cost cannot be negative.");
        }
        this->cost = cost;
    }

    void setEffectDescription(const std::string& description) {
        if (description.empty()) {
            throw std::invalid_argument("Effect description cannot be empty.");
        }
        this->effectDescription = description;
    }

    virtual void setHealth(int health) {}
    virtual void setAttack(int attack) {}
};
#endif //CARD_H
