#include "SpellCard.h"

SpellCard::SpellCard(const std::string& name, std::string type, const std::string& effect, int cost)
    : Card(name, effect, cost), type(type) {
    if (cost < 0) {
        throw std::invalid_argument("Cost cannot be negative.");
    }
}
std::string SpellCard::getType() const {
    return type;
}
