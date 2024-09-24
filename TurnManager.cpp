//
// Created by Ali on 9/21/2024.
//
#include "TurnManager.h"

TurnManager::TurnManager() {
    std::vector<std::string> player = {"Player 1", "Player 2"};
    turnCounter = 0;
    currentTurn = 0;
}

std::string TurnManager::getTurn() {
    return player[currentTurn];
}

bool TurnManager::setTurn(const std::string& playerName) {
    if (playerName == player[0]) {
        currentTurn = 0;
        return true;
    } else if (playerName == player[1]) {
        currentTurn = 1;
        return true;
    } else {
        return false;
    }
}

bool TurnManager::nextTurn() {
    currentTurn = (currentTurn + 1) % 2;
    turnCounter++;
    return true;
}
