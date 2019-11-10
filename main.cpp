#include <bits/stdc++.h> 
using namespace std;

// void visitPlanet(int planet, short levelOfPlutonium, vector<int> adjacencyList[], vector<bool> &resources, int &currentNumberOfVisitedPlanets)
// { 
//     currentNumberOfVisitedPlanets++;

//     levelOfPlutonium = resources[planet] ? 3 : levelOfPlutonium-1;

//     cout << planet << " ("<< levelOfPlutonium << ") ";

//     if(levelOfPlutonium <= 0) {
//         return;
//     }

//     for (int i=0; i<adjacencyList[planet].size(); i++) { 
//         visitPlanet(adjacencyList[planet][i], levelOfPlutonium, adjacencyList, resources, currentNumberOfVisitedPlanets); 
//     }
// }

// int return_planets (vector<int> &T, vector<bool> &B) {
//     int numberOfPlanets = T.size();
//     cout << "Number of planets: " << numberOfPlanets << endl;  

//     int numberOfVisitedPlanets = 0;

//     cout << "Planets: " << endl;  
//     for(int x : T) {
//         cout << x << " ";
//     }
//     cout << endl;

//     cout << "Resources on planets: " << endl;  
//     for(bool x : B) {
//         cout << x << " ";
//     }
//     cout << endl;

//     vector<int> planetsAdjacenyList[numberOfPlanets];
//     int startingPoint;
//     for (int i=0; i<numberOfPlanets; i++) {        
//         if(T[i] == i) {
//             startingPoint = i;
//             continue;
//         }

//         planetsAdjacenyList[T[i]].push_back(i);
//         // cout << "The size of planetsAdjacenyList[" << i << "] is " << planetsAdjacenyList[i].size() << endl; 
//         // cout << "The maximum capacity is " << planetsAdjacenyList[i].capacity() << endl; 
//     }

//     visitPlanet(startingPoint, 0, planetsAdjacenyList, B, numberOfVisitedPlanets); 

//     return numberOfVisitedPlanets;
// }

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

int main() {
    vector<int> planet_ids;
    vector<bool> planet_resources;

    planet_ids = {9, 1, 4, 9, 0, 4, 8, 1, 0, 7};
    planet_resources = {false, true, false, false, false, false, false, true, false, false};

    std::cout << "Maximum number of planets: " << solution(planet_ids, planet_resources) << endl;

    planet_ids = {9, 1, 4, 9, 0, 4, 8, 1, 0, 7};
    planet_resources = {true, true, false, false, false, false, false, false, false, false};
    std::cout << "Maximum number of planets: " << solution(planet_ids, planet_resources) << endl;

    planet_ids = {0, 0, 1, 2, 3};
    planet_resources = {false, false, false, false, false};
    std::cout << "Maximum number of planets: " << solution(planet_ids, planet_resources) << endl;

    planet_ids = {9, 1, 4, 9, 0, 4, 8, 1, 0, 7};
    planet_resources = {false, true, false, false, true, false, false, false, true, false};

    std::cout << "Maximum number of planets: " << solution(planet_ids, planet_resources) << endl;

    return 0;
}