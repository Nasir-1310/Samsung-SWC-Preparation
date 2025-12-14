#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include<climits>
using namespace std;

struct node{
    int x;
    int y;
};
struct wormhole{
    node start;
    node des;
    int cost;
};

int dis(node start,node end){
    return (abs(start.x-end.x)+abs(start.y-end.y));
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        node source,des;
        cin>>source.x>>source.y>>des.x>>des.y;
        vector<node>nodes;
        nodes.push_back(source);
        nodes.push_back(des);
        
         vector<wormhole>wormholes(n);
        
         for(int j=0;j<n;j++){
            cin>>wormholes[j].start.x>>wormholes[j].start.y>>wormholes[j].des.x>>wormholes[j].des.y>>wormholes[j].cost;
                 nodes.push_back(wormholes[j].start);
                 nodes.push_back(wormholes[j].des);
            
         }
        int total_nodes=nodes.size();
        vector<vector<pair<int,int>>>adj(total_nodes);
        for(int j=0;j<total_nodes;j++){
            for(int k=j+1;k<total_nodes;k++){
                int manha_dis=dis(nodes[j],nodes[k]);
                adj[j].push_back({k,manha_dis});
                adj[k].push_back({j,manha_dis});
                
            }
        }
        for(int j=0;j<n;j++){//equal hobe kina
           int indx=2+2*j;
            int indy=2+2*j+1;
            int cost_t=wormholes[j].cost;
            adj[indx].push_back({indy,cost_t});
             adj[indy].push_back({indx,cost_t});
         }
        
        //Dijstra
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>dist(total_nodes,INT_MAX);
        dist[0]=0;
        
        while(!pq.empty()){
             auto curr=pq.top();
            pq.pop();
            int u=curr.second;
            int node_cost=curr.first;
            if(node_cost>dist[u])
                continue;
            for(auto v:adj[u]){
                int edge_cost=v.second;
                int node_v=v.first;
                if(dist[node_v]>edge_cost+node_cost){
                    dist[node_v]=edge_cost+node_cost;
                    pq.push({dist[node_v],node_v});
                }
            }
        }
        
        cout<<dist[1]<<"\n";
    }
    
    return 0;
}
