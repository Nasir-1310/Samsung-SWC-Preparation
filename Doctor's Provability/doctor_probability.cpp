#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;

int n, m;
int minute;

vector<double> calculate_next_move(vector<vector<pair<int,double>>>& adj, vector<double>& curr, int n, int steps) {
    for(int step = 0; step < steps; step++) {
        vector<double> next(n + 1, 0.0);
        
        for(int u = 1; u <= n; u++) {
            if(curr[u] > 0.0) {
                for(auto v : adj[u]) {
                    int node = v.first;
                    double prob = v.second;
                    next[node] += curr[u] * prob;
                }
            }
        }
        
        curr = next;
    }
    return curr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> n >> m >>minute;
        
        vector<vector<pair<int, double>>> adj(n + 1);
        
        for(int j = 0; j < m; j++) {
            int u, v;
            double p;
            cin >> u >> v >> p;
            adj[u].push_back({v, p});
        }
        
        vector<double> curr(n + 1, 0.0);
        curr[1] = 1.0;
        
        int steps = minute/ 10;
        curr = calculate_next_move(adj, curr, n, steps);
        
        int des_node = 1;
        double des_prob = curr[1];
        
        for(int j = 2; j <= n; j++) {
            if(curr[j] > des_prob) {
                des_prob = curr[j];
                des_node = j;
            }
        }
        
        cout << des_node << " " << fixed << setprecision(6) << des_prob << "\n";
    }
    
    return 0;
}
