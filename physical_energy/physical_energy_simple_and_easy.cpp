#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int dp[3001][11];
int cost[5], time_taken[5];


int solve(int energy, int distance) {
    // Base case 1: Destination reached
    if (distance == 0) return 0;
    
    // Base case 2: No energy left, can't proceed
    if (energy == 0) return INT_MAX;
    
    // Memoization check
    if (dp[energy][distance] != -1) return dp[energy][distance];
    
    int minTime = INT_MAX;
    
    for (int i = 0; i < 5; i++) {
        if (cost[i] <= energy) {
            int result = solve(energy - cost[i], distance - 1);
            if (result != INT_MAX) {
                minTime = min(minTime, result + time_taken[i]);
            }
        }
    }
    
    return dp[energy][distance] = minTime;
}

int main() {
    int H, D;
    cin >> H >> D;
    
    for (int i = 0; i < 5; i++) cin >> cost[i];
    for (int i = 0; i < 5; i++) cin >> time_taken[i];
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(H, D) << endl;
    
    return 0;
}