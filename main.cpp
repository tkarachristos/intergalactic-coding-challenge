#include <bits/stdc++.h> 
using namespace std;

void visitPlanet(int planet, int levelOfPlutonium, vector<int> adjacencyList[], vector<bool> resources,
                    vector<bool> &planetHasBeenVisited)
{ 
    planetHasBeenVisited[planet] = true;

    levelOfPlutonium = resources[planet] ? 3 : levelOfPlutonium-1;

    cout << planet << " ("<< levelOfPlutonium << ") ";
    
    for (int i=0; i<adjacencyList[planet].size(); i++) 
        if (planetHasBeenVisited[adjacencyList[planet][i]] == false) 
            visitPlanet(adjacencyList[planet][i], levelOfPlutonium, adjacencyList, resources, planetHasBeenVisited); 
}

int return_planets (vector<int> planets, vector<bool> resources) {
    int numberOfPlanets = planets.size();
    cout << "Number of planets: " << numberOfPlanets << endl;  

    int levelOfPlutonium = 0;

    cout << "Planets: " << endl;  
    for(int x : planets) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Resources on planets: " << endl;  
    for(bool x : resources) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> planetsAdjacenyList[numberOfPlanets];
    int startingPoint;
    for (int i=0; i<numberOfPlanets; i++) {        
        planetsAdjacenyList[i].push_back(planets[i]);
        planetsAdjacenyList[planets[i]].push_back(i);

        if(planets[i] == i) {
            startingPoint = i;

            if(resources[i]) {
                levelOfPlutonium = 3;
            }
        }
    }

    vector<bool> planetHasBeenVisited(numberOfPlanets, false);

    visitPlanet(startingPoint, levelOfPlutonium, planetsAdjacenyList, resources, planetHasBeenVisited); 

    return  1;
}

int main() {
    // vector<int> planet_ids{9, 1, 4, 9, 0, 4, 8, 1, 0, 7};
    // vector<bool> planet_resources{false, true, false, false, false, false, false, true, false, false};

    vector<int> planet_ids{0, 0, 1, 2, 3};
    vector<bool> planet_resources{false, false, false, false, false};

    std::cout << "Maximum number of planets: " << return_planets(planet_ids, planet_resources);

    return 0;
}