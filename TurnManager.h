//
// Created by Ali on 9/21/2024.
//

#ifndef TURNMANAGER_H
#define TURNMANAGER_H
#include <string>
#include <vector>

class TurnManager {
    std::vector<std::string> player = {"Player 1", "Player 2"};
    int currentTurn = 0;
    int turnCounter = 0;
public:
    TurnManager();
    std::string getTurn();
    bool setTurn(const std::string& playerName);
    bool nextTurn();
};
#endif //TURNMANAGER_H
