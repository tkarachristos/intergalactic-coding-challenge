#include <bits/stdc++.h> 
using namespace std;

void visitPlanet(int &planet, int &levelOfPlutonium, vector<int> adjacencyList[], vector<bool> &resources,
                    vector<bool> &planetVisited, int &currentNumberOfVisitedPlanets)
{ 
    planetVisited[planet] = true;
    currentNumberOfVisitedPlanets++;

    levelOfPlutonium = resources[planet] ? 3 : levelOfPlutonium-1;

    if(levelOfPlutonium <= 0) {
        return;
    }

    for (int i=0; i<adjacencyList[planet].size(); i++) { 
        if (planetVisited[adjacencyList[planet][i]] == false) {
            visitPlanet(adjacencyList[planet][i], levelOfPlutonium, adjacencyList, resources, planetVisited, currentNumberOfVisitedPlanets); 
        }
    }
}

int solution(vector<int> &T, vector<bool> &B) {
    int numberOfPlanets = T.size();
    int levelOfPlutonium = 0;
    int numberOfVisitedPlanets = 0;

    vector<int> planetsAdjacenyList[numberOfPlanets];
    int startingPoint;
    for (int i=0; i<numberOfPlanets; i++) {        
        planetsAdjacenyList[i].push_back(T[i]);
        planetsAdjacenyList[T[i]].push_back(i);

        if(T[i] == i) {
            startingPoint = i;

            if(B[i]) {
                levelOfPlutonium = 3;
            }
        }
    }

    for (int i=0; i<numberOfPlanets; i++) {        
        planetsAdjacenyList[i].shrink_to_fit();
    }

    vector<bool> planetVisited(numberOfPlanets, false);

    visitPlanet(startingPoint, levelOfPlutonium, planetsAdjacenyList, B, planetVisited, numberOfVisitedPlanets); 

    return numberOfVisitedPlanets;
}