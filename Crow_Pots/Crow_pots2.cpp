#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (k <= 0 || k > n) {
        cout << -1;
        return 0;
    }

    sort(a.begin(), a.end());

    long long ans = 0;

    // Special case: K == 1
    if (k == 1) {
        ans = min(2 * a[0], a[n - 1]);
    } 
    else {
        long long sum = 0;
        for (int i = 0; i < k; i++)
            sum += a[i];

        ans = sum * (n - k + 1);
    }

    cout << ans << endl;
    return 0;
}