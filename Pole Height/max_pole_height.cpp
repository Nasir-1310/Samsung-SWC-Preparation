#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int maxPole(vector<int>&a){
    int dp[10005], temp[10005];
    for(int i=0; i<10005; i++) dp[i]= INT_MIN;
    dp[0]=0;
    int total = 0;

    for(int r:a){
        total +=r;
        for(int i=0; i<=total; i++) temp[i] = dp[i];

            for(int diff=0; diff+r <=total; diff++){
                int d1 = diff + r;
                int d2 = abs(diff-r);

                dp[d1] = max(dp[d1], temp[diff]);
                dp[d2]= max(dp[d2], temp[diff] + min(diff, r));
            }
        }
        return dp[0];
    }

int main(){
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0; i<n ; i++) cin>>a[i];

        cout<<maxPole(a)<<"\n";
    }
}