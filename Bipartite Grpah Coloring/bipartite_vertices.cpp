 #include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<int> adj[105];
int color[105];  // -1 = uncolored, 0 = color1, 1 = color2
bool is_bipartite = true;

void dfs(int u, int c) {
    color[u] = c;  // Current node ko color c assign karo
    
    for(auto v : adj[u]) {
        if(color[v] == -1) {  // Agar adjacent node uncolored hai
            dfs(v, 1 - c);  // Opposite color assign karo (0->1 or 1->0)
        }
        else if(color[v] == color[u]) {  // Agar same color hai
            is_bipartite = false;  // NOT Bipartite!
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }
    
    memset(color, -1, sizeof(color));  // Sabko uncolored mark karo
    
    // Har uncolored node se DFS chalao (for disconnected components)
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            dfs(i, 0);  // Starting color = 0
        }
    }
    
    if(!is_bipartite) {
        cout << "-1" << endl;
    }
    else {
        // Print all nodes with color 0
        for(int i = 1; i <= n; i++) {
            if(color[i] == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
