#include <iostream>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

bool available[10];
bool ops[5];

bool canType(int num) {
    if (num == 0) return available[0];
    string s = to_string(num);
    for (char c : s) {
        if (!available[c - '0']) return false;
    }
    return true;
}

int countDigits(int num) {
    return to_string(num).length();
}

int bfs(int target, int maxTouches) {
    if (canType(target)) {
        return countDigits(target);
    }
    
    queue<pair<int, int>> q;
    set<int> visited;
    
    for (int i = 0; i <= 9; i++) {
        if (available[i]) {
            q.push({i, 1});
            visited.insert(i);
        }
    }
    
    while (!q.empty()) {
        int num = q.front().first;
        int touches = q.front().second;
        q.pop();
        
        if (touches + 3 > maxTouches) continue;
        
        for (int digit = 0; digit <= 9; digit++) {
            if (!available[digit]) continue;
            
            int newNums[4] = {-1, -1, -1, -1};
            
            if (ops[1]) newNums[0] = num + digit;
            if (ops[2]) newNums[1] = num - digit;
            if (ops[3]) newNums[2] = num * digit;
            if (ops[4] && digit != 0 && num % digit == 0) newNums[3] = num / digit;
            
            for (int i = 0; i < 4; i++) {
                int result = newNums[i];
                if (result < 0 || result > 100000) continue;
                
                int newTouches = touches + 3; // operation + digit + =
                
                if (result == target) {
                    return newTouches;
                }
                
                if (visited.find(result) == visited.end()) {
                    visited.insert(result);
                    q.push({result, newTouches});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, o;
        cin >> n >> m >> o;
        
        memset(available, false, sizeof(available));
        memset(ops, false, sizeof(ops));
        
        for (int i = 0; i < n; i++) {
            int d;
            cin >> d;
            available[d] = true;
        }
        
        for (int i = 0; i < m; i++) {
            int op;
            cin >> op;
            ops[op] = true;
        }
        
        int target;
        cin >> target;
        
        cout << bfs(target, o) << endl;
    }
    
    return 0;
}