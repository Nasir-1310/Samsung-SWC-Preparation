#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int grid[105][105];
int visited[105][105];
int rows, cols;

struct Node {
    int x;
    int y;
    int time;
};

int step[4][2] = {
    {-1, 0},  // up
    {1, 0},   // down
    {0, -1},  // left
    {0, 1}    // right
};
bool isValid(int x, int y) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

int bfs(int startX, int startY) {
    if (grid[startX][startY] == 0) {
        return 0;
    }
    
    queue<Node> q;
    // Node start;
    // start.x = startX;
    // start.y = startY;
    // start.time = 1;
    q.push({startX, startY, 1});
    visited[startX][startY] = 1;
    
    int maxTime = 1;
    
    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextX = current.x + step[i][0];
            int nextY = current.y + step[i][1];
            
            if (isValid(nextX, nextY) && grid[nextX][nextY] == 1 && visited[nextX][nextY] == 0) {

                q.push({nextX,nextY,current.time + 1});
                visited[nextX][nextY] = 1;
                maxTime = max(maxTime,current.time + 1);
            }
        }
    }
    
    return maxTime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCases;
    cin >> testCases;
    
    for (int tc = 1; tc <= testCases; tc++) {
        cin >> rows >> cols;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> grid[i][j];
            }
        }
        
        int bombX, bombY;
        cin >> bombX >> bombY;
        
        memset(visited, 0, sizeof(visited));
        
        int totalTime = bfs(bombX-1, bombY-1);
        
        cout << "Case #" << tc << "\n";
        cout << totalTime << "\n";
    }
    
    return 0;
}

/*
2
8 7
0 0 1 1 0 0 0
1 1 1 1 0 1 0
0 0 1 1 1 1 1
0 1 1 1 1 1 1
0 1 0 0 1 1 0
0 1 1 1 1 0 0
0 0 1 0 1 1 1
0 0 0 0 1 0 0
5 2
10 10
1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 1 0 1 1 0
0 0 1 1 0 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 1 0 1 0 1 1 1 1 0
0 0 0 0 0 1 1 0 0 0
1 0 1 0 1 0 1 1 0 0
0 0 1 1 1 1 1 1 1 1
1 0 1 0 0 1 0 1 1 0
1 1 1 0 0 0 0 1 1 1
2 2


Output
Case #1
8
Case #2
21
*/