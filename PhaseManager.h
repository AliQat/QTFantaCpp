//
// Created by Ali on 9/21/2024.
//

#ifndef PHASEMANAGER_H
#define PHASEMANAGER_H
#include <string>
#include <vector>
#include <iostream>



class PhaseManager {
    std::vector<std::string> phaseArray = {"Draw Phase","Main Phase", "Scuffle Phase", "End Phase"};
    std::string currentPhase = "Draw Phase";
public:
    std::string getPhase(int  phase);
    [[nodiscard]] int getPhase(const std::string& phase) const;
    void setPhase(const std::string& phase);
    void setPhase(int phase);
    std::string getCurrentPhase() {return currentPhase;};
    void nextPhase();
};
#endif //PHASEMANAGER_H
