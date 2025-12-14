#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int grid[105][5];
int n;
int dp[105][5][2][10]; // [row][col][bombUsed][rowsSinceBomb]

int find_max_score(int x, int y, bool check, int index) {
    if(x < 0 || (grid[x][y] == 2 && index >= 5))
        return 0;
    
    // Check memoization
    if(dp[x][y][check][index] != -1)
        return dp[x][y][check][index];
    
    int max_score = 0;
    int step[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};
    
    for(int i = 0; i < 3; i++) {
        int dx = x + step[i][0];
        int dy = y + step[i][1];
        int score = 0;
        
        if(dx >= 0 && dx < n && dy >= 0 && dy < 5) {
            
            if(grid[dx][dy] == 1 && check == false)
                score = 1 + find_max_score(dx, dy, false, index);
            else if(grid[dx][dy] == 1 && check == true)
                score = 1 + find_max_score(dx, dy, true, index + 1);
            
            else if(grid[dx][dy] == 2 && check == false)
                score = find_max_score(dx, dy, true, index + 1);
            else if(grid[dx][dy] == 2 && check == true)
                score = find_max_score(dx, dy, true, index + 1);
            
            else if(grid[dx][dy] == 0 && check == false)
                score = find_max_score(dx, dy, false, index);
            else if(grid[dx][dy] == 0 && check == true)
                score = find_max_score(dx, dy, true, index + 1);
        }
        max_score = max(score, max_score);
    }
    
    // Store in memoization table
    return dp[x][y][check][index] = max_score;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        cin >> n;
        
        for(int j = 0; j < n; j++)
            for(int k = 0; k < 5; k++) {
                cin >> grid[j][k];
            }
        
        // Initialize memoization table
        memset(dp, -1, sizeof(dp));
        
        cout << "#" << i << " " << find_max_score(n, 2, false, 0) << endl;
    }
    
    return 0;
}