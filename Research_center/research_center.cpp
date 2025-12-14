#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int grid[25][25];
int dist[5][25][25];  // dist[r][i][j] = rare element r থেকে (i,j) এর distance
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

// একটা rare element থেকে সব cells এ distance calculate
void bfs(int rareIdx, int startX, int startY) {
    // Initialize distances
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[rareIdx][i][j] = INT_MAX;
        }
    }
    
    queue<Node> q;
    q.push({startX, startY, 0});
    dist[rareIdx][startX][startY] = 0;
    
    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextX = current.x + step[i][0];
            int nextY = current.y + step[i][1];
            
            if (isValid(nextX, nextY) && 
                grid[nextX][nextY] == 1 && 
                dist[rareIdx][nextX][nextY] == INT_MAX) {
                
                dist[rareIdx][nextX][nextY] = current.time + 1;
                q.push({nextX, nextY, current.time + 1});
            }
        }
    }
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
        
        // প্রতিটা rare element থেকে একবার BFS
        for (int r = 0; r < k; r++) {
            bfs(r, rareElements[r][0], rareElements[r][1]);
        }
        
        int answer = INT_MAX;
        
        // প্রতিটা road position check
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int maxDist = 0;
                    
                    // এই cell থেকে সব rare elements এর distance
                    for (int r = 0; r < k; r++) {
                        maxDist = max(maxDist, dist[r][i][j]);
                    }
                    
                    // যদি সব rare elements reachable হয়
                    if (maxDist < INT_MAX) {
                        answer = min(answer, maxDist);
                    }
                }
            }
        }
        
        cout << (answer == INT_MAX ? -1 : answer) << "\n";
    }
    
    return 0;
}