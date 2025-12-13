#include <bits/stdc++.h>
using namespace std;

void buildGraph(int m, vector<vector<pair<int, double>>>& adj) {
    for(int i = 0; i < m; i++) {
        int u, v;
        double prob;
        cin >> u >> v >> prob;
        adj[u].push_back({v, prob});
    }
}

void simulateMovement(int steps, int n, vector<vector<pair<int, double>>>& adj, vector<double>& curr) {
    for(int s = 0; s < steps; s++) {
        vector<double> next(n + 1, 0.0);
        
        for(int u = 1; u <= n; u++) {
            if(curr[u] > 0) {
                for(auto [v, prob] : adj[u]) {
                    next[v] += curr[u] * prob;
                }
            }
        }
        
        curr = next;
    }
}

pair<int, double> findMaxProbability(int n, vector<double>& curr) {
    int maxNode = 1;
    double maxProb = curr[1];
    
    for(int i = 2; i <= n; i++) {
        if(curr[i] > maxProb) {
            maxProb = curr[i];
            maxNode = i;
        }
    }
    
    return {maxNode, maxProb};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, m, time;
        cin >> n >> m >> time;
        
        vector<vector<pair<int, double>>> adj(n + 1);
        buildGraph(m, adj);
        
        vector<double> curr(n + 1, 0.0);
        curr[1] = 1.0;
        
        int steps = time / 10;
        simulateMovement(steps, n, adj, curr);
        
        auto [maxNode, maxProb] = findMaxProbability(n, curr);
        
        cout << maxNode << " " << fixed << setprecision(6) << maxProb << "\n";
    }
    
    return 0;
}