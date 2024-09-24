//
// Created by Ali on 9/21/2024.
//

#ifndef HANDMANAGER_H
#define HANDMANAGER_H
#include <memory>
#include <vector>

#include "Card.h"
class HandManager {
    std::vector<std::unique_ptr<Card>> cardsInHand;
public:
    friend class DeckManager;
    bool addCardToHand(std::unique_ptr<Card> card);
    [[nodiscard]] const std::vector<std::unique_ptr<Card>>& getCardsInHand() const { return cardsInHand; }

    bool setCardInHand(const Card* cardToBeChanged, std::unique_ptr<Card> cardInputted);
};
#endif //HANDMANAGER_H
