//
// Created by Ali on 9/21/2024.
//

#ifndef SPELLCARD_H
#define SPELLCARD_H

#include "Card.h"
#include <string>
#include <utility>

class SpellCard final : public Card {
private:
    std::string type = "Spell";

public:
    explicit SpellCard(const std::string& name, std::string type, const std::string& effect, int cost);

    [[nodiscard]] std::string getType() const override;
};

#endif // SPELLCARD_H
