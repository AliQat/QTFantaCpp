//
// Created by Ali on 9/21/2024.
//
#include "CoinFlip.h"


std::string CoinFlip::getCoinFlip() {
    return result;
}
void CoinFlip::setCoinFlip(int coinFlip) {
    for(int i = 0; i < coinSide.size(); i++) {
        if(i == coinFlip) {
            result = coinSide.at(i);
        }
    }
}
void CoinFlip::doCoinFlip() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 1);
    setCoinFlip(distrib(gen)); // Generate a random number 0 or 1
}
