//
// Created by Ali on 9/21/2024.
//
#include "DeckManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include "MonsterCard.h"
#include "SpellCard.h"
#include "nlohmann/json.hpp"
#include <random>
#include "HandManager.h"

bool DeckManager::instantiateCardsInDeck() {
    std::ifstream file(R"(C:\Users\Ali\Documents\attempt3\Cards.json)");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file Cards.json" << std::endl;
        return false;
    }

    nlohmann::json jsonData;
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: Cards.json is empty" << std::endl;
        return false;
    }

    try {
        file >> jsonData;
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Parse error: " << e.what() << std::endl;
        return false;
    }

    for (const auto& item : jsonData) {
        if (std::string cardType = item["CardType"]; cardType == "Monster") {
            if (item.contains("Health") && item.contains("Attack")) {
                cardDeck.push_back(std::make_unique<MonsterCard>(
                    item["CardName"].get<std::string>(),
                    cardType,
                    item["CardEffect"].get<std::string>(),
                    item["CardCost"].get<int>(),
                    item["Health"].get<int>(),
                    item["Attack"].get<int>()
                    ));
            } else {
                std::cerr << "Error: Missing fields for Monster card: " << item["CardName"] << std::endl;
            }
        } else if (cardType == "Spell") {
            cardDeck.push_back(std::make_unique<SpellCard>(
                item["CardName"].get<std::string>(),
                cardType,
                item["CardEffect"].get<std::string>(),
                item["CardCost"].get<int>()
                ));
        } else {
            std::cerr << "Error: Unknown card type: " << cardType << std::endl;
        }
    }

    return true;
}

bool DeckManager::drawCard(HandManager& handManager) {
    if (cardDeck.empty()) {
        return false;
    }
    if(handManager.cardsInHand.size() <= 5) {
        std::unique_ptr<Card> card = std::move(cardDeck.front());
        cardDeck.pop_front();
        handManager.addCardToHand(std::move(card));
    }
    return true;
}
void DeckManager::initialDrawCard(HandManager& handManager) {
    for(int i = 0; i < INITIAL_DRAW; i++) {
        std::unique_ptr<Card> card = std::move(cardDeck.front());
        cardDeck.pop_front();
        handManager.addCardToHand(std::move(card));
    }
}

void DeckManager::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(cardDeck.begin(), cardDeck.end(), g);
}
bool DeckManager::searchCard(const Card& card) const {
    for (const auto& item : cardDeck) {
        if (item->getName() == card.getName()) {
            return true;
        }
    }
    return false;
}
