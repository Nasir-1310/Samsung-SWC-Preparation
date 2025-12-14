#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

double calE(long long n, long long a, long long b, long long c){
    if(n <= 0)
        return 0;
    return a*n + b*n*log2(n) + c*(double)n*n*n;
}

long long findN(long long a, long long b, long long c, long long k){
    // ❌ Remove this check - k can be negative!
    // if(k <= 0) return 0;
    
    long long low = 1;
    long long high;
    long long result = 0;
    double minDiff = 1e18;
    
    // Smarter upper bound calculation
    if(c > 0) {
        // Cubic dominates, grows to positive infinity
        double estimate = cbrt((double)k / c);
        high = (long long)(estimate * 10);
        high = max(high, 100LL);
    }
    else if(c < 0) {
        // Negative cubic, function will eventually go negative
        // Need to search smaller range
        high = 10000LL;  // Limited search space
    }
    else {
        // c == 0, linear/logarithmic growth
        if(a > 0 || b > 0) {
            high = max(abs(k) * 2, 10000LL);
            high = min(high, 10000000LL);
        }
        else {
            high = 10000LL;
        }
    }
    
    // Binary search with ALL values (positive and negative k)
    while(low <= high){
        long long mid = low + (high - low) / 2;
        double val = calE(mid, a, b, c);
        double diff = fabs(val - k);
        
        if(diff < minDiff){
            minDiff = diff;
            result= mid;
        }
        
        if(val < k){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return (minDiff < 1e-6) ? result : 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << findN(a, b, c, k) << "\n";
    
    return 0;
}
