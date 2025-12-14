#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include<cstring>;

using namespace std;

int n,m;
vector<int>adj[52];
int parent[30];
int visited[30];
vector<int>bestCycle;

void dfs(int u){
    visited[u]=1;
    
    int sum=INT_MAX;//place
    for(int v:adj[u]){
        if(visited[v]==1){
            int cycle_sum=v;
            vector<int>cycle={v};
            for(int i=u;i!=v;i=parent[i]){
                cycle.push_back(i);
                cycle_sum+=i;
            }
            if(cycle_sum<sum){
                bestCycle=cycle;
                sum=cycle_sum;
            }
        }
        else{
            parent[v]=u;
        dfs(v);//call
        }
        
    }
    visited[u]=2;
    
}
int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            dfs(i);
        }
    }
    
    sort(bestCycle.begin(),bestCycle.end());
    for(auto u: bestCycle)
        cout<<u<<" ";
    
    return 0;
}
