#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int n;
int dist[20][20];
int dp[1<<20][20];
int tpas(int mask,int position){
    if(mask==(1<<n)-1)
        return dist[position][0];
    if(dp[mask][position]!=-1)
        return dp[mask][position];
    
    int min_score=INT_MAX;
    for(int city=0;city<n;city++){
        if((mask & (1<<city))==0){
            int score=dist[position][city]+tpas((mask | (1<<city)),city);
            min_score=min(score,min_score);
        }
    }
   return dp[mask][position]=min_score;
}

int main() {
   int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                int val;
                cin>>val;
                dist[j][k]=val;
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=tpas(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
