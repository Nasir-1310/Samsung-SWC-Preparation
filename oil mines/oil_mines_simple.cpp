#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int c, n, oil[20], ans;
bool vis[20];

void solve(int idx, int sum, int companies, int minVal, int maxVal) {
    if(vis[idx]) {
        if(companies == c) {
            int newMin = min(sum, minVal);
            int newMax = max(sum, maxVal);
            ans = min(ans, newMax - newMin);
        }
        return;
    }
    
    int next = (idx + 1) % n;
    vis[idx] = true;
    
    // Add to current company
    solve(next, sum + oil[idx], companies, minVal, maxVal);
    
    // Start new company
    if(companies < c) {
        int newMin = min(sum, minVal);
        int newMax = max(sum, maxVal);
        solve(next, oil[idx], companies + 1, newMin, newMax);
    }
    
    vis[idx] = false;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        cin >> c >> n;
        for(int i = 0; i < n; i++) {
            cin >> oil[i];
            vis[i] = false;
        }
        
        if(c > n) {
            cout << -1 << "\n";
            continue;
        }
        
        ans = INT_MAX;
        for(int start = 0; start < n; start++) {
            solve(start, 0, 1, INT_MAX, INT_MIN);
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}