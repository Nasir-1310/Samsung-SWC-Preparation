#include <iostream>
#include <cmath>
using namespace std;

double calE(long long n, long long a, long long b, long long c) {
    if(n <= 0) return 0;
    double val = (double)a * n + (double)b * n * log2(n) + (double)c * n * n * n;
    return val;
}

long long findN(long long a, long long b, long long c, long long k) {
    if(k == 0) return 0;
    
    long long low = 1;
    long long high;
    
    if(c != 0) {
        double estimate = cbrt((double)k / c);
        high = (long long)(estimate * 10);
        high = max(high, 100LL);
    } else {
        high = min(k, 10000000LL);
    }
    
    long long result = 0;
    double minDiff = 1e18;
    
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        double val = calE(mid, a, b, c);
        double diff = fabs(val - k);  // ✅ Changed to fabs()
        
        if(diff < minDiff) {
            minDiff = diff;
            result = mid;
        }
        
        if(val < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return (minDiff < 1e-6) ? result : 0;
}

int main() {
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << findN(a, b, c, k) << endl;
    return 0;
}

// #include <iostream>
// #include <cmath>
// #include <climits>
// #include <algorithm>
// #define ll long long 
// using namespace std;

// long double calE(ll n, ll a, ll b, ll c){
//     if(n<=0) return 0;
//     long double val = (long double)a*n + (long double)b*n*log2(n) + (long double)c*n*n*n;
//     return val;
// }
// ll findN(ll a, ll b, ll c, ll k){
//     if(k <= 0) return 0;

//     ll low = 1, high;

//     if(c != 0){
//         ll estimate = cbrt((long double)k / c);
//         high = max(estimate * 2, 100LL);
//     } else {
//         high = max(100LL, k);
//     }

//     high = min(high, 10000000LL);

//     while(low <= high){
//         ll mid = low + (high - low)/2;
//         long double val = calE(mid, a, b, c);

//         if(fabsl(val - k) <= 1e-9){
//             return mid;
//         }
//         else if(val < k){
//             low = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }
//     return 0;
// }


// int main(){
//     ll a, b, c, k;
//     cin>>a>>b>>c>>k;
//     cout<<findN(a, b, c, k)<<"\n";
//     return 0;
// }

