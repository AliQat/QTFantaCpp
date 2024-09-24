//
// Created by Ali on 9/21/2024.
//
#include "HandManager.h"

bool HandManager::addCardToHand(std::unique_ptr<Card> card) {
    if(cardsInHand.size() >= 5) {
        return false;
    }
    cardsInHand.push_back(std::move(card));
    return true;
}

bool HandManager::setCardInHand(const Card* cardToBeChanged, std::unique_ptr<Card> cardInputted) {
    for(auto& card : cardsInHand) {
        if (card.get() == cardToBeChanged) {
            card = std::move(cardInputted);
            return true;
        }
    }
    return false;
}
