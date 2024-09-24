//
// Created by Ali on 9/21/2024.
//
#include "phaseManager.h"

std::string PhaseManager::getPhase(const int phase) {
    return phaseArray.at(phase);
}

int PhaseManager::getPhase(const std::string& phase) const { // loop through the phases, find the current phase, return its number
    for (int i = 0; i < phaseArray.size(); i++) {
        if (phaseArray.at(i) == phase) {
            return i;
        }
    }
    throw std::out_of_range("No phase found");
}

void PhaseManager::setPhase(const std::string& phase) {
    for(const auto & i : phaseArray) {
        if(i == phase) {
            currentPhase = i;
        }
    }
}

void PhaseManager::setPhase(const int phase) {
    currentPhase = phaseArray.at(phase);
}

void PhaseManager::nextPhase() {
    int nextPhase = getPhase(currentPhase);
    if((nextPhase+= 1) > 3) {
        nextPhase = 0;
    }
    currentPhase = getPhase(nextPhase);
}



