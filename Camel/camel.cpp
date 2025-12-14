#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> c(n);
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        
        sort(c.begin(), c.end());
        
        int cost = 0;
        int right = n - 1;
        
        // Formula-based approach
        while(right > 2) {
            // Strategy 1: 2*c[1] + c[0] + c[right]
            int s1 = 2*c[1] + c[0] + c[right];
            
            // Strategy 2: 2*c[0] + c[right] + c[right-1]
            int s2 = 2*c[0] + c[right] + c[right-1];
            
            cost += min(s1, s2);
            right -= 2;
        }
        
        // Handle remaining
        if(right == 2) {
            cost += c[0] + c[1] + c[2];  // 3 left
        } else if(right == 1) {
            cost += c[1];  // 2 left
        }
        
        cout << cost << "\n";
    }
    
    return 0;
}
/*
2                // Number of test cases
4                // Number of camels in the first test case
1 2 8 9          // Costs of camels in the first test case
6                // Number of camels in the second test case
14 45 73 86 95 98 // Costs of camels in the second test case
Output
16
434

*/