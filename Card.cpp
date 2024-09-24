#include "Card.h"

Card::Card(std::string name, std::string effect, const int& cost)
    : cardName(std::move(name)), effectDescription(std::move(effect)), cost(cost) {}

std::string Card::getEffectDescription() const {
    if (effectDescription.empty()) {
        throw std::runtime_error("Effect description is empty.");
    }
    return effectDescription;
}

int Card::getCost() const {
    if (cost < 0) {
        throw std::runtime_error("Cost cannot be negative.");
    }
    return cost;
}

std::string Card::getName() const {
    if (cardName.empty()) {
        throw std::runtime_error("Card name is empty.");
    }
    return cardName;
}

void Card::setName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Card name cannot be empty.");
    }
    this->cardName = name;
}

void Card::setCost(const int& cost) {
    if (cost < 0) {
        throw std::invalid_argument("Cost cannot be negative.");
    }
    this->cost = cost;
}

void Card::setEffectDescription(const std::string& description) {
    if (description.empty()) {
        throw std::invalid_argument("Effect description cannot be empty.");
    }
    this->effectDescription = description;
}
