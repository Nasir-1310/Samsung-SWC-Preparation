#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int visited[15];
vector<int> adj[15];
int parent[15];
vector<int> best_cycle;
int min_sum = INT_MAX;

void dfs(int u) {
    visited[u] = 1;  // Currently visiting
    
    for(auto v : adj[u]) {
        if(parent[u] == v) continue;  // Skip parent edge (for undirected graph)
        
        if(visited[v] == 1) {  // Back edge found - cycle detected!
            int cycle_sum = 0;
            vector<int> cycle;
            
            // Build cycle from u to v
            cycle.push_back(v);
            cycle_sum += v;
            
            for(int i = u; i != v; i = parent[i]) {
                cycle.push_back(i);
                cycle_sum += i;
            }
            
            // Update best cycle if this one is better
            if(cycle_sum < min_sum) {
                min_sum = cycle_sum;
                best_cycle = cycle;
            }
        }
        else if(visited[v] == 0) {  // Not visited yet
            parent[v] = u;
            dfs(v);
        }
        // If visited[v] == 2, already fully processed, skip
    }
    
    visited[u] = 2;  // Fully processed
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }
    
    memset(visited, 0, sizeof(visited));   // 0 = not visited
    memset(parent, -1, sizeof(parent));
    
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            dfs(i);
        }
    }
    
    if(best_cycle.empty()) {
        cout << "No cycle found\n";
    } else {
        sort(best_cycle.begin(), best_cycle.end());
        for(auto i : best_cycle) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;
}







// #include <cmath>
// #include <cstdio>
// #include <climits>
// #include <cstring>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int n, m ;
// int visited[500];
// vector<int>adj[15];
// int parent[15];
// vector<int>best_cycle;
// int min_sum= INT_MAX;
// //vector<vector<int>>all_cycle;

// void dfs(int u){
//     visited[u] =1;
    
//     for(auto v:adj[u]){
//         if(visited[v]==1){
//         if(visited[v]==1 && parent[u]!=v){ // for bi directed 
//         int cycle_sum =0;
//         vector<int>cycle={v};
//         cycle_sum+=v;
        
//         for(int i=u; i!=v ; i= parent[i]){
//             cycle.push_back(i);
//             cycle_sum+=i;
//         }
//             //all_cycle.push_back(cycle);
//         if(cycle_sum<min_sum){
//             min_sum = cycle_sum;
//             best_cycle = cycle;
//         }
//     }
//     }
//         else {
//             parent[v]=u;
//             dfs(v);
//         }
// }
//     visited[u]=2;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     cin>>n>>m;
    
//     for(int i=0; i<m;i++){
//         int u, v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u); //for undirected
//     }
    
//     memset(visited, -1, sizeof(visited));
//     memset(parent, -1, sizeof(parent));
    
//     for(int i=1; i<=n;i++){
//         if(visited[i]!=2){
//             dfs(i);
//         }
//     }
//     // for( auto &u:all_cycle){
//     //     sort(u.begin(), u.end());
//     //     for(auto &val:u){
//     //         cout<<val<<" ";
//     //     }
//     //     cout<<endl;
//     // }
    
//     sort(best_cycle.begin(), best_cycle.end());
//     for(auto i:best_cycle){
//         cout<<i<<" ";
//     }
        
//         return 0;
// }