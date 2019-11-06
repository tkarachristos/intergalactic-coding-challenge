#include <bits/stdc++.h> 
using namespace std;

int return_planets (vector<int> planets, vector<bool> resources) {
    for(int x : planets) {
        cout << x << " ";
    }
    cout << endl;

    for(bool x : resources) {
        cout << x << " ";
    }
    cout << endl;

    return  1;
}

int main() {
    vector<int> planet_ids{9, 1, 4, 9, 0, 4, 8, 1, 0, 7};
    vector<bool> planet_resources{false, true, false, false, false, false, false, true, false, false};

    std::cout << "Maximum number of planets: " << return_planets(planet_ids, planet_resources);

    return 0;
}