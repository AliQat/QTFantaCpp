//
// Created by Ali on 9/21/2024.
//

#ifndef DECKMANAGER_H
#define DECKMANAGER_H
#define INITIAL_DRAW 3
#include <memory>
#include "Card.h"
#include <queue>
#include <vector>

#include "HandManager.h"

class DeckManager {
private:
    std::deque<std::unique_ptr<Card>> cardDeck;
public:
    friend class HandManager;
    DeckManager() { if (instantiateCardsInDeck()) instantiateCardsInDeck(); };
    bool instantiateCardsInDeck();

    bool drawCard(HandManager& handManager);
    void initialDrawCard(HandManager& handManager);
    [[nodiscard]] size_t getCardDeckSize() const { if(!cardDeck.empty()) return cardDeck.size(); return 0; };
    [[nodiscard]] bool searchCard(const Card& card) const;
    void shuffle();
};
#endif //DECKMANAGER_H
