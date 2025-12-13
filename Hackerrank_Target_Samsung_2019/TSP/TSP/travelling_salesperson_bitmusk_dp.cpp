#include <bits/stdc++.h>
using namespace std;

int n;
int arr[20][20];
int dp[1 << 12][12];  // memoization table (mask, last city)
int func_call = 0;

int tsp(int mask, int pos) {
    func_call++;

    // if all cities visited, return cost to go back to city 0
    if (mask == (1 << n) - 1)
        return arr[pos][0];

    // already computed
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        // if not visited
        if ((mask & (1 << city)) == 0) {
            int newCost = arr[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newCost);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        memset(dp, -1, sizeof(dp));
        func_call = 0;

        int ans = tsp(1, 0); // start from city 0, visited mask = 000...001
        cout << ans << endl;
        cout << func_call << endl;
    }
    return 0;
}
