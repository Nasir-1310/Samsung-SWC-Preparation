#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int grid[25][25];
int visited[25][25];
int n, k;
int rareElements[5][2];

struct Node {
    int x, y, time;
};

int step[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

// একটা position থেকে একটা rare-element এর distance
int bfs(int startX, int startY, int targetX, int targetY) {
   
    
    memset(visited, 0, sizeof(visited));
    queue<Node> q;
    q.push({startX, startY, 0});
    visited[startX][startY] = 1;
    
    while (!q.empty()) {
        Node current = q.front();
        q.pop();
         if (current.x == targetX && current.y == targetY)
                return current.time;
        
        for (int i = 0; i < 4; i++) {
            int nextX = current.x + step[i][0];
            int nextY = current.y + step[i][1];
            
            if (isValid(nextX, nextY) && grid[nextX][nextY] == 1 && visited[nextX][nextY] == 0) {
                visited[nextX][nextY] = 1;
                q.push({nextX, nextY, current.time + 1});
            }
        }
    }
    return INT_MAX; // পৌঁছানো যায়নি
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        cin >> n >> k;
        
        // Rare-elements positions (0-indexed)
        for (int i = 0; i < k; i++) {
            cin >> rareElements[i][0] >> rareElements[i][1];
            rareElements[i][0]--;
            rareElements[i][1]--;
        }
        
        // Grid input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        
        int answer = INT_MAX;
        
        // প্রতিটা road position check করো
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int maxDist = 0;
                    
                    // এই position থেকে সব rare-elements এর distance
                    for (int r = 0; r < k; r++) {
                        int dist = bfs(i, j, rareElements[r][0], rareElements[r][1]);
                        maxDist = max(maxDist, dist);
                    }
                    
                    answer = min(answer, maxDist);
                }
            }
        }
        cout << answer << "\n";
    }
    
    return 0;
}