#include <bits/stdc++.h>

using namespace std;
// There are N petrol stations (0,1,2,...,N-1) in arranged in circle. 
// The vector<vector<int>> contains pairs 
// (petrol added, petrol used to  reach the next station)
// 
// The function below returns the minimum index of the station
// where the truck can make a trip around the whole circle.
// (from i, i+1, ... N-1, 1, 2, ... i-1)
int truckTour(vector<vector<int>> petrolpumps) {
    int numPumps = petrolpumps.size();
    int currentPetrolLevel = 0;
    int minPetrolLevel = 0;
    int minPetrolStation = 0;
    // After passing station i and arriving at station i+1
    for(int i = 0; i < numPumps; ++i) {
        int petrolAdded = petrolpumps[i][0];
        int petrolUsed = petrolpumps[i][1];
        currentPetrolLevel += petrolAdded - petrolUsed;
        if(currentPetrolLevel < minPetrolLevel) {
            minPetrolLevel = currentPetrolLevel;
            minPetrolStation = (i+1) % numPumps;
            // The truck reaches minimum petrol after station i, 
            // when it arrives the next station (i+1) % N where N = numPumps
            // (Note: Use % to wrap N to 0)
            // To avoid this minimum and have enough for the entire journey, 
            // it must start at station i+1 % N
        }
    }
    return minPetrolStation;
}
