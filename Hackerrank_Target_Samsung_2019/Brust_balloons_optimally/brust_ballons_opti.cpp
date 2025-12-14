#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int b[20];
int dp[20][20];
int n;
int brust_ballun(int l,int r){
    
    if(l>r)
        return 0;
    
    if(dp[l][r]!=-1)
        return dp[l][r];
    
    
    int max_score=0;
    for(int i=l;i<=r;i++){
        bool left=(l-1>=0);
        bool right=(r+1<=n-1);
        int score;
        if(left && right)
            score=b[l-1]*b[r+1];
        else if(left && !right)
            score=b[l-1];
        else if(!left && right)
            score=b[r+1];
        else
            score=b[i];
        max_score=max(max_score, score+brust_ballun(l,i-1)+brust_ballun(i+1,r));
        
    }
    return dp[l][r]=max_score;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    memset(dp,-1,sizeof(dp));
    cout<<brust_ballun(0,n-1)<<"\n";
    
    return 0;
}
