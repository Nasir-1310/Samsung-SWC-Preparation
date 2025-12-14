#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
struct node{
    int x;
    int y;
};
vector<node>dist;
int dp[1<<20][20];

int distance(node p,node q){
     return (abs(p.x-q.x)+abs(p.y-q.y));
}
   

int kim_and_ref(int mask,int position){
    if(mask==((1<<(n+1))-2))
        return distance(dist[position],dist[n+1]);
    if(dp[mask][position]!=-1)
        return dp[mask][position];
    
    int min_path=INT_MAX;
    for(int customer=1;customer<=n;customer++){
        if((mask & (1<<customer))==0){
            int cost=distance(dist[position],dist[customer])+kim_and_ref((mask | (1<<customer)),customer);
            min_path=min(cost,min_path);
        }
    }
    return dp[mask][position]=min_path;
}

int main() {
    for(int t=1;t<11;t++){
        cin>>n;
        node source,des;
        cin>>source.x>>source.y>>des.x>>des.y;
        
        dist.resize(n+2);
        dist[0]=source;
        dist[n+1]=des;
        
        for(int i=1;i<=n;i++){
            node p;
            cin>>p.x>>p.y;
            dist[i]=p;
            
        }
        
        memset(dp,-1,sizeof(dp));
        int ans=kim_and_ref(0,0);
        cout<<"#"<<" "<<t<<" "<<ans<<"\n";
    }
    return 0;
}
