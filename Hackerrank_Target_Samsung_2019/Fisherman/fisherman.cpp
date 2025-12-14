#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int n;
int gate[3];
int fisherman[3];
int dp[20][20][20][20];

int fisherman_set(int index,int f0,int f1,int f2){
    // cout<<"enter"<<" "<<f0<<" "<<f1<<" "<<f2<<" ";
    if(f0<=0 && f1<=0 && f2<=0)
        return 0;
    // cout<<"after 1st if"<<"\n";
    if(index>n)
        return INT_MAX/2;
   
    if(dp[index][f0][f1][f2]!=-1)
        return dp[index][f0][f1][f2];
     // cout<<"after 1st if--"<<"\n";
    // cout<<"in func"<<"\n";
    int ans=INT_MAX/2;
    for(int i=0;i<3;i++)
    {
      int fisherman_count[3]={f0,f1,f2};//second bracket used.
        if(fisherman_count[i]>0){
            fisherman_count[i]--;
            int distance=abs(index-gate[i])+1;//index or i
            // cout<<distance<<"\n";
            ans=min(ans,distance+fisherman_set(index+1, fisherman_count[0],fisherman_count[1],fisherman_count[2]));
                    
             }
    }
    ans=min(ans,fisherman_set(index+1,f0,f1,f2));
    return dp[index][f0][f1][f2]=ans;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n;
    for(int i=0;i<3;i++){
        cin>>gate[i];
        // cout<<gate[i]<<" ";
    }
        
    for(int j=0;j<3;j++){
         cin>>fisherman[j];
        // cout<<fisherman[j]<<" ";
    }
       
    
    memset(dp,-1,sizeof(dp));
    // cout<<"before f cll"<<"\n";
    int aa=fisherman_set(1,fisherman[0],fisherman[1],fisherman[2]);
    cout<<aa;
    // cout<<fisherman_set(1,fisherman[0],fisherman[1],fisherman[2])<<"\n";
    
    return 0;
}
