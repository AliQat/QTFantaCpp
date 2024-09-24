#include "MonsterCard.h"

MonsterCard::MonsterCard(const std::string &name,std::string type, const std::string &effect, int cost, int health, int attack)
    : Card(name, effect, cost), type(type), health(health), attack(attack) {
    if (health < 0) {
        throw std::invalid_argument("Health cannot be negative.");
    }
    if (attack < 0) {
        throw std::invalid_argument("Attack cannot be negative.");
    }
}

std::string MonsterCard::getType() const {
    return type;
}

int MonsterCard::getHealth() const {
    return health;
}

int MonsterCard::getAttack() const {
    return attack;
}

void MonsterCard::setHealth(int health) {
    if (health < 0) {
        throw std::invalid_argument("Health cannot be negative.");
    }
    this->health = health;
}

void MonsterCard::setAttack(int attack) {
    if (attack < 0) {
        throw std::invalid_argument("Attack cannot be negative.");
    }
    this->attack = attack;
}

