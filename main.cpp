#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <string>
#include <vector>

#include "CoinFlip.h"
#include "DeckManager.h"
#include "MonsterCard.h"
#include "PhaseManager.h"
#include "SpellCard.h"
#include "TurnManager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    DeckManager deck;
    HandManager playerHand;
    MonsterCard mc("balls", "nails", "Monster", 1,1, 1);
    CoinFlip coin;
    coin.doCoinFlip();
    std::cout << "Result of coin flip " << coin.getCoinFlip() << std::endl;
    PhaseManager phase;
    const int phaseNumber = phase.getPhase(phase.getCurrentPhase());
    std::cout << "Result of phase " << phase.getPhase(phaseNumber) << std::endl;
    phase.nextPhase();
    std::cout << "next phase is " << phase.getPhase(phase.getPhase(phase.getCurrentPhase())) << std::endl;
    phase.nextPhase();
    std::cout << "next phase is " << phase.getPhase(phase.getPhase(phase.getCurrentPhase())) << std::endl;
    phase.nextPhase();
    std::cout << "next phase is " << phase.getPhase(phase.getPhase(phase.getCurrentPhase())) << std::endl;
    phase.nextPhase();
    std::cout << "next phase is " << phase.getPhase(phase.getPhase(phase.getCurrentPhase())) << std::endl;
    TurnManager tm;
    for(int i = 0; i < 101; i++) {
        tm.nextTurn();
        phase.nextPhase();
    }
    std::cout << "next phase is " << phase.getPhase(phase.getPhase(phase.getCurrentPhase())) << std::endl;
    std::cout << "next phase is " << tm.getTurn() << std::endl;
    deck.shuffle();
    std::cout << "size of deck is: " << deck.getCardDeckSize() << std::endl;
    deck.initialDrawCard(playerHand);
    std::cout << "size of deck is: " << deck.getCardDeckSize() << std::endl;
    for (const std::vector<std::unique_ptr<Card>>& cardsInPlayerHand = playerHand.getCardsInHand(); const auto& card : cardsInPlayerHand) {
        if(!card) { break;}
        if(card->getName().empty()) {break;}
        std::string effect = card->getEffectDescription();
        std::string type = card->getType();
        int cost = card->getCost();
        std::cout << "name: " << card->getName() << std::endl;
        std::cout << "Card Type: " << type << ", Effect: " << effect << ", Cost: " << cost << std::endl;

        if (auto* monsterCard = dynamic_cast<MonsterCard*>(card.get())) {
            std::cout << "MonsterCard - Health: " << monsterCard->getHealth() << ", Attack: " << monsterCard->getAttack() << std::endl;
        } else if (auto* spellCard = dynamic_cast<SpellCard*>(card.get())) {
            std::cout << "SpellCard - No additional attributes" << std::endl;
        }
        for(int i = 0; i < 900; i++) {
            deck.drawCard(playerHand);
        }
        // Create a temporary card on the stack and search for it
        MonsterCard searchCard("WarmGhost Whiz-Kidz", "Monster", "Ward. If your opponent controls more monsters than you then you can summon this card for free", 5, 3, 3);
        if (deck.searchCard(searchCard)) {
            std::cout << "Card Found! " << searchCard.getName() << std::endl;
        } else {
            std::cout << "Card Not Found!" << std::endl;
        }
    }
    // my name is mister frog
    std::cout << "size of deck is: " << deck.getCardDeckSize() << std::endl;
    return a.exec();
}
