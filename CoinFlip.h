//
// Created by Ali on 9/21/2024.
//

#ifndef COINFLIP_H
#define COINFLIP_H
#include <random>
class CoinFlip {
    std::vector<std::string> coinSide = {"Tails", "Heads"};
    std::string result;
public:
    std::string getCoinFlip();
    void setCoinFlip(int coinFlip);
    void doCoinFlip();
};
#endif //COINFLIP_H
