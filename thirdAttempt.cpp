#include <bits/stdc++.h> 
using namespace std;

void visitPlanet(int planet, short levelOfPlutonium, vector<int> adjacencyList[], vector<bool> &resources, int &currentNumberOfVisitedPlanets)
{
    currentNumberOfVisitedPlanets++;

    // Decrease or replenish the level of plutonium
    levelOfPlutonium = resources[planet] ? 3 : levelOfPlutonium-1;
    
    // Step back if plutonium has been depleted
    if(levelOfPlutonium <= 0) {
        return;
    }

    // Visit the adjacent planets
    for (unsigned int i=0; i<adjacencyList[planet].size(); i++) { 
        visitPlanet(adjacencyList[planet][i], levelOfPlutonium, adjacencyList, resources, currentNumberOfVisitedPlanets); 
    }
}

int solution(vector<int> &T, vector<bool> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int numberOfPlanets = T.size();
    int numberOfVisitedPlanets = 0;
    int startingPoint = -1;

    // Create the adjacency list
    vector<int> planetsAdjacenyList[numberOfPlanets];
    for (int i=0; i<numberOfPlanets; i++) {
        // Store the starting point
        if(T[i] == i) {
            startingPoint = i;
            continue;
        }

        // Add adjacency link
        planetsAdjacenyList[T[i]].push_back(i);
        planetsAdjacenyList[T[i]].shrink_to_fit();
    }

    // Start the planet exploration from the starting point, if any
    if(startingPoint > -1) {
        visitPlanet(startingPoint, 0, planetsAdjacenyList, B, numberOfVisitedPlanets); 
    }

    return numberOfVisitedPlanets;    
}