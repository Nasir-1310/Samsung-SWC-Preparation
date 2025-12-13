/*
Physical Energy Problem
Problem Description
You have a certain amount of energy and need to travel a specific distance. You can choose from five different speeds to travel, each with its own energy cost and time taken per kilometer.

Your goal is to minimize the total time required to cover the distance, ensuring that you do not exceed the available energy.

Given
An initial amount of energy H.
A total distance D to travel.
Five speeds, each with associated:
Cost of traveling 1 km (energy required per km).
Time taken to travel 1 km (time required per km).
Input
An integer H representing the initial amount of energy.
An integer D representing the total distance to be traveled.
A list of five integers representing the energy cost to travel 1 km for each speed.
A list of five integers representing the time taken to travel 1 km for each speed.
Example
Input
3000---> limit highest energy 
10 ---> distance to travel (km)
4 5 2 3 6 ---> energy cost 
200 210 230 235 215 ---> time taken (seconds)
input: 
3000
10
4 5 2 3 6
200 210 230 235 215

output 2000

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int dp[3001][1001][6]; // dp[energy][distance][speed] = min time

int solve(int h, int d, int cost[], int time[], int n){
    if(d == 0) return 0;
    if(n == 0 || h < 0) return INT_MAX; // impossible case 
    if(dp[h][d][n] !=-1) return dp[h][d][n];

    if(cost[n-1] <=h && d > 0){
        int w1 = solve(h - cost[n-1], d-1, cost, time, n);
        if(w1 != INT_MAX) w1 += time[n-1];
        int w2 = solve(h, d, cost, time, n-1); //skip
        return dp[h][d][n] = min(w1, w2);
    }
    else{ 
        return dp[h][d][n] = solve(h, d, cost, time, n-1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, d; // highest energy and distance
    cin>>h>>d; 
    int cost[5], time[5];
    for(int i=0; i<5; i++) cin>>cost[i];
    for(int i=0; i<5; i++) cin>>time[i];

    memset(dp, -1, sizeof(dp));

    cout<<solve(h, d, cost, time, 5)<<endl;  // 5 ta speed options
    return 0;
}