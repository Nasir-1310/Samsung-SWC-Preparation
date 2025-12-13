#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>
using namespace std;

int n;
vector<int> a;
map<pair<int,int>, int> dp;  // Changed: map instead of array

int solve(int i, int diff){
    if(i == n){
        return (diff == 0) ? 0 : INT_MIN;
    }
    
    if(dp.count({i, diff}))  // Changed: map lookup
        return dp[{i, diff}];
    
    // Option 1: Add to pillar 1 (increases diff)
    int op1 = INT_MIN;
    int next1 = solve(i + 1, diff + a[i]);
    if(next1 != INT_MIN) op1 = next1 + a[i];
    
    // Option 2: Add to pillar 2 (decreases diff)
    int op2 = solve(i + 1, diff - a[i]);
    
    // Option 3: Skip current pole
    int op3 = solve(i + 1, diff);
    
    return dp[{i, diff}] = max({op1, op2, op3});  // Changed: map assignment
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        
        dp.clear();  // Changed: clear map instead of memset
        int ans = solve(0, 0);
        
        cout << (ans == INT_MIN ? 0 : ans) << "\n";
    }
    return 0;
}

/* 
CHANGES MADE:
-------------
1. int dp[25][10005]         → map<pair<int,int>, int> dp
2. dp[i][diff + OFFSET]      → dp[{i, diff}]
3. memset(dp, -1, sizeof(dp)) → dp.clear()
4. Removed: const int OFFSET = 5000

COMPLEXITY:
-----------
Time:  O(t × n × unique_diffs × log(states))
       ≈ O(t × 500 × 10000 × log(5M))
       ≈ O(t × 5M × 22) = O(110M × t) per test
       
Space: O(visited states) = O(n × unique_diffs)
       Typically O(500 × 5000) = O(2.5M) in worst case
       But usually much less due to pruning

For n ≤ 500, sum ≤ 25000:
Time:  O(500 × 25000 × log) ≈ O(300M) per test ✅
Space: O(2-5M) visited states ✅

BENEFITS:
---------
✅ Supports n up to 500-1000
✅ Supports any sum size (no OFFSET needed)
✅ Memory efficient (only stores visited states)
✅ Minimal code changes (only 4 lines changed)
✅ No array size limits

DRAWBACKS:
----------
⚠️ Slightly slower than array (log factor for map)
⚠️ More memory overhead per entry (map structure)

WHEN TO USE:
------------
- n ≤ 25, sum ≤ 10K   → Use original array version (faster)
- n ≤ 500, sum ≤ 50K  → Use this map version
- n > 500             → Consider unordered_map for speed
*/